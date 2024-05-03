#include <iostream>
#include <string>
#include <stdlib.h>
#include "Song.h"
using namespace std;

Song::Song(){
	songID = 0;
	songDuration = 0;
	songTitle = "";
	idx=0;
	removed=false;
	isFavorite=false;
}

Song::Song(int id, string title){
	songID = id;
	songDuration = 0;
	songTitle = title;
	idx=0;
	removed=false;
	isFavorite=false;
}

bool Song::getisFavorite(){
	return isFavorite;
}

void Song::setIsFavorite(bool status){
	isFavorite=status;
}

int Song::getSongID(){
	return songID;
}

int Song::getIdx(){
	return idx;
}

bool Song::getRemovedStat(){
	return removed;
}


void Song::setRemovedStat(bool status){
	//cout << endl << "setting " << songTitle << "'s removed status = " << status << endl;
	removed=status;
}

void Song::setIdx(int new_idx){
	idx = new_idx;
}

// this is called when the song is deleted in order to set its ID = -1, to free up whatever ID it had
void Song::setSongID(int newID){
	songID = newID;
}


// bool operator<(const Song& lhs, const Song& rhs) {
//     return lhs.songID < rhs.songID;
// }

// bool operator==(const Song& lhs, const Song &rhs){
// 	return lhs.songID == rhs.songID;
// }

int Song::getSongDuration(){
	return songDuration;
}

string Song::getSongTitle(){
	return songTitle;
}

void Song::setDuration(int &seconds){
	if (!isFavorite)songDuration += seconds;
	else cout << "Can not increase duration for favorite song!" << endl;
}

ostream &operator<<(ostream &os, const Song& song){
  os << song.songID << " " << song.songTitle << " has been listened to for " << song.songDuration << " seconds " << endl; 
  return os;
}

void Song::show() {
    cout << "song " << songID << songTitle << endl;
}