#include <iostream>
#include <string>
#include "BST_song.h"
#include "BST_songTitle.h"
#include "Heap.h"
#include "Song.h"
#include <string>

using namespace std;

class Manager{
	public:
		void addSong(Song &value);
		void show_listen_time();
		void listen(string &title, int seconds);
		void remove(string &songToDeletesTitle);
		bool uniqueID(Song &song);
		bool checkSong(string &title);
		void Remove(string songTitle);
		void favorite();
	private:
};
