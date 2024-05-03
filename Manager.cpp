#include <iostream>
#include <string>
#include "Manager.h"
#include "Heap.h"
#include "BST_songTitle.h"
#include "BST_song.h"
#include "Song.h"

using namespace std;

BST_song songTree;
BST_songTitle songTitleTree;
Heap songTime;

void Manager::addSong(Song &value){
	songTree.insert(value);
	songTitleTree.insert(value);
	songTime.Push(&value);

	cout <<  endl << "new song " << value.getSongID() << " " << value.getSongTitle() << endl;
}

void Manager::show_listen_time(){
	songTree.printInOrder(songTree.getRoot());
}

void Manager::listen(string &title, int seconds){
	int index = songTitleTree.listenHelper(title, seconds);
	songTime.PercolateUp(index);
	songTime.Peek();
}

void Manager::favorite(){//Finished and tested on 4/28/2024 @ 1:06PM. -Kian F
	if(songTime.Empty()){
		cout << "No song to favorite" << endl;
		return;
	}
    Song* topSng=songTime.Pop();//Pop the top song from the heap- 4/28/24 Kian F 
    if(topSng == nullptr){
        cout << "Heap is empty, no song to favorite." << endl;
        return;
    }

    topSng->setIsFavorite(true);//Set the favorite flag to true, should effect song in BST- 4/28/24 Kian F 
    cout <<"Song "<< topSng->getSongTitle() << " added to list of favorites ("<<topSng->getSongDuration()<<")" << endl;//Printing-Kian F
}

bool Manager::uniqueID(Song &song){
	return songTree.search(song);
}

// bool Manager::checkSong(string &title){
// 	return true; // Not impemented yet -> meant to check if the song exists or not -> multiple uses ? Maybe
// }

/* 
Removes the song from the BST_songTitle and Heap, and sets its 
   'removed' attribute = true so that its effectively "removed" from the BST_song

Note:
	  a song being a favorite has no effect on how its removed, it just prints out
	  a slightly different output
*/
void Manager::remove(string &songToDelete)
{
	// make sure the song exists first
	if(songTitleTree.findAndReturnSong(songToDelete) != nullptr)
	{
		// set the songs id to something never to be used to free up the old ID
		songTitleTree.setSongIDHelper(songToDelete, -1);

		// "remove" it from the Song Object BST... just set its removed stat = true
		songTitleTree.setRemovedStatHelper(songToDelete, true);

		//  if the song isnt a favorite
		if(songTitleTree.getFavoriteStatHelper(songToDelete) == false)
			cout << endl << "Removed " << songToDelete << " from your songs" << endl;
		else 	// the song is a favorite
			cout << endl << "Removed " << songToDelete << " from your favorites" << endl;
		
		// remove it from the Heap
		songTime.Remove(songTitleTree.getHeapIndexHelper(songToDelete));

		// remove it from the Title BST
		songTitleTree.removeHelper(songToDelete);
	}
	else
	{
		cout << endl << "Song " << songToDelete << " does not exist" << endl;
	} // show_listen_time
}	
bool Manager::checkSong(string &title){
	return true; // Not impemented yet -> meant to check if the song exists or not -> multiple uses ? Maybe
}
