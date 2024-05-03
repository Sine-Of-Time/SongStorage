#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class Song{
  public:
    Song();
    Song(int id, string title);
    friend ostream& operator<<(ostream &os, const Song& song);
    // friend bool operator<(const Song& lhs, const Song &rhs); 
    // friend bool operator==(const Song& lhs, const Song &rhs);
    int getSongID();
    int getIdx();
    bool getRemovedStat();
    bool getFavoritedStat();
    int getSongDuration();
    void show();
    void setRemovedStat(bool status);
    void setFavoritedStat(bool status);
    string getSongTitle();
    void setDuration(int &seconds);
    void setIdx(int new_idx);
    void setSongID(int newID); // called by a helper function when the song is being deleted 
    bool getisFavorite(); //Both getter and setter for isFav added 4/28 to work with fav f(x) in manager-Kian F
    void setIsFavorite(bool status);
  private:
    int songID;
    int songDuration;
    int idx;
    bool removed;
    bool favorited;
    bool isFavorite;//Add on 4/28 to work with favorite function in manager-Kian F
    string songTitle;
};

#endif
