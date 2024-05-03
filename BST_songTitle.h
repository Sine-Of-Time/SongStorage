#include <iostream>
#include <string>
#include "Song.h"
#ifndef BSTSONGTITLE_H
#define BSTSONGTITLE_H

using namespace std;

class BST_songTitle{
	private:
		class NodeBST{
			public:
				Song *data;
				NodeBST *left;
				NodeBST *right;
				NodeBST(){
					left = nullptr;
					right = nullptr;
				}
		};
		NodeBST *root;
		public:
			BST_songTitle();
			~BST_songTitle();
			bool insert(Song &value); // Passed by reference so we can update the information
			void remove(Song &value);
			bool isEmpty(); // Could be useful we will see
			NodeBST *search(string &value);
				
			// *** jacksons helper mess \/ ***
			NodeBST *findAndReturnSong(string &value); 			
			void removeHelper(string &value);					
			bool getFavoriteStatHelper(string &value);
			bool getRemovedStatHelper(string &value);
			int getHeapIndexHelper(string &value);				
			void setFavoriteStatHelper(string &value, bool status);			
			void setRemovedStatHelper(string &value, bool status);	
			void setSongIDHelper(string &value, int newID);			
			// *** jacksons helper mess /\ ***

			void printInOrder(NodeBST *node);
			int listenHelper(string &value, int &seconds);
			NodeBST *getRoot();
      		void destroy(NodeBST *node);
};

#endif
