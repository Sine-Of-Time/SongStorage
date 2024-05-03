#include <iostream>
#include <string>
#include "Song.h"
#ifndef BSTSONG_H
#define BSTSONG_H

using namespace std;

class BST_song{
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
			BST_song();
			~BST_song();
			bool insert(Song &value); // Passed by reference so we can update the information
			void remove(Song &value);
			bool isEmpty(); // Could be useful we will see
			bool search(Song &value);
			void printInOrder(NodeBST *node);
			NodeBST *getRoot();
      		void destroy(NodeBST *node);
};

#endif
