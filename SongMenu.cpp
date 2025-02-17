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
	return 0;
}
