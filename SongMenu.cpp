#include <vector>
#include <iostream>
#include <sstream>
#include "Song.h"
#include "BST_songTitle.h"
#include "BST_song.h"
#include "Heap.h" 
#include "Manager.h"

using namespace std;

bool checkID(string x){
	try{
		stoi(x);
	}
	catch(...){
		cout << endl << x << " is not a valid song ID" << endl;
		return false;
	}
	return true;
}

bool checkTime(string x){
	try{
		stoi(x);
	}
	catch(...){
		cout << endl << x << " is not a valid length of time" << endl;
		return false;
	}
	return true;
}

void songMenu(){

	Manager manage;

	cout << endl;
	cout << "Enter [\"song <song-id> <title>\"" << endl;
	cout << "	\"listen <song-title> <seconds>\"" << endl;
	cout << "	\"favorite\"" << endl;
	cout << "	\"remove <song-title>\"" << endl;
	cout << "	\"show_listen_time\"" << endl;
	cout << "	\"quit\"]" << endl;

	while(true){

		cout << ": ";
		string input, command;
		getline(cin, input);
		vector<string> full_input;
		stringstream ss(input);
		string word;
		while(ss >> word){
			if(word.front() == '\"'){
				string phrase = word.substr(1);
				while(ss >> word){
					phrase += " " + word;
					if(word.back() == '\"'){
						phrase.pop_back();
						break;
					}
				}
				full_input.push_back(phrase);
			}
			else{
				full_input.push_back(word);
			}
		}

		if(input.empty())
		{
			cout << endl << "Please enter a command" << endl;
		}
		else if(full_input[0] == "song"){
			if(full_input.size() < 3){
				cout << endl << "invalid number of argumets. Required : <id> <song-title>" << endl;
				continue;
			}
			if(checkID(full_input[1]) == false){
				continue;
			}
			Song *song = new Song(stoi(full_input[1]), full_input[4]);
			// if(manage.uniqueID(*song) == true){
			// 	cout << endl << "Song ID already exists" << endl;
			// 	delete song;
			// 	continue;
			// }
			manage.addSong(*song);
		}
		else if(full_input[0] == "remove"){
			if(full_input.size() < 2){
				cout << endl << "invalid number of arguments. Required : <song-title>" << endl;
				continue;
			}
			manage.remove(full_input[1]);
		}
		else if(full_input[0] == "listen"){
			if(full_input.size() < 3){
				cout << endl << "invalid number of arguments. Required : <song-title> <seconds>" << endl;
				continue;
			}
			if(checkTime(full_input[2]) == false){
				continue;
			}
			manage.listen(full_input[1], stoi(full_input[2]));
		}
		else if(full_input[0] == "favorite"){
			if(full_input.size() < 1){
				cout << endl << "invalid number of arguments. Required : favorite" << endl;
				continue;
			}
			manage.favorite();
		}
		else if(full_input[0] == "show_listen_time"){
			if(full_input[0].size() < 1){
				cout << endl << "invalid number of arguments. Required : show_listen_time" << endl;
				continue;
			}
			manage.show_listen_time();
		}
		else if(full_input[0] == "quit"){
			break;
		}
		else{
			cout << endl << "Command not recognized" << endl;
		}
	}
}

int main(){	
	songMenu();

	/*BST_song test;
	BST_songTitle test2;

	string word = "We will wont";
	
	Song *t = new Song(20, "Queen", 10, "Me");
	Song *a = new Song(10, "Queen", 10, "Te will");
	Song *b = new Song(30, "Queen", 10, "Ae will rock");
	Song *c = new Song(40, "Queen", 10, "Be will rock you");

	test.insert(*t);
	test.insert(*a);
	test.insert(*b);
	test.insert(*c);

	test2.insert(*t);
	test2.insert(*a);
	test2.insert(*b);
	test2.insert(*c);

	test.isEmpty();

	test.printInOrder(test.getRoot());
	cout << "" << endl;
	test2.printInOrder(test2.getRoot());

	test.remove(*t);
	test2.remove(*t);

	test2.search(word);

	test.printInOrder(test.getRoot());
	cout << "" << endl;
	test2.printInOrder(test2.getRoot());

	delete t;
	delete a;
	delete b;
	delete c;
	
	//songMenu();
	return 0;*/

	//The following is code I was using to test different heap functions -KF 4/20 12:55PM
	// Heap myHeap;

    // // Create a sample heap (you might want to generate more complex data)
    // myHeap.Push(15);
    // myHeap.
	// Push(8);
    // myHeap.Push(10);
    // myHeap.Push(5);
    // myHeap.Push(3);
    // myHeap.Push(12);

	// //myHeap.DisplayHeapAsTree();

    // cout << "Heap before PercolateDown:\n";
    // myHeap.Display_heap();

    // // Test Case 1: Percolate down from the root
    // int testIndex = 0; 
    // cout << "\nRemove from index" << testIndex << ":\n";
    // myHeap.Remove(0);
    // myHeap.Display_heap();

    // // Test Case 2: Percolate down a non-root node
    // testIndex = 2; 
    // cout << "\nPercolateDown from index " << testIndex << ":\n";
    // myHeap.Remove(2);
    // myHeap.Display_heap();

	// myHeap.Push(100);
    // myHeap.Push(33);
    // myHeap.Push(3);

	// myHeap.Display_heap();
	//  // Test Case 1: Percolate down from the root
    // testIndex = 4; 
    // cout << "\nPercolateDown from index " << testIndex << ":\n";
    // myHeap.Remove(4);
    // myHeap.Display_heap();

    // // Test Case 2: Percolate down a non-root node
    // testIndex = 5; 
    // cout << "\nPercolateDown from index " << testIndex << ":\n";
    // myHeap.Remove(5);
    // myHeap.Display_heap();

	// // Test Case 2: Percolate down a non-root node
    // testIndex = 0; 
    // cout << "\nPercolateDown from index " << testIndex << ":\n";
	// myHeap.Remove(0);
    // myHeap.Display_heap();

	// // Test Case 2: Percolate down a non-root node
    // testIndex = 2; 
    // cout << "\nPercolateDown from index " << testIndex << ":\n";
	// myHeap.Remove(2);
    // myHeap.Display_heap();

	// myHeap.Remove(0);
    // myHeap.Display_heap();
	// myHeap.Remove(1);
    // myHeap.Display_heap();
	// myHeap.Remove(2);
    // myHeap.Display_heap();

	// Manager manage;

	// Song *t = new Song(1, 10, "YES");
	// Song *a = new Song(10, 10, "YES2");
	// Song *s = new Song(5, 10, "YES3");
	// Song *b = new Song(8, 10, "YES4");
	// Song *n = new Song(15, 10, "YES5");
	// Song *c = new Song(2, 10, "YES6");
	// Song *q = new Song(16, 10, "YES7");
	// Song *w = new Song(3, 10, "YES8");

	// manage.addSong(*t);
	// manage.addSong(*a);
	// manage.addSong(*s);
	// manage.addSong(*b);
	// manage.addSong(*n);
	// manage.addSong(*c);
	// manage.addSong(*q);
	// manage.addSong(*w);
	// manage.show_listen_time();

	// delete t;
	return 0;
}