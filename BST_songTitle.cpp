#include <string>
#include <iostream>
#include "BST_songTitle.h"

using namespace std;

BST_songTitle::BST_songTitle(){
	root = nullptr;
}

void BST_songTitle::destroy(NodeBST *node){
	if (node != nullptr){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

BST_songTitle::~BST_songTitle(){
	destroy(root);
}

bool BST_songTitle::insert(Song &value){
	NodeBST *new_node = new NodeBST();
	new_node->data = &value;
	if (root == nullptr){
		root = new_node;
	}
	else{
		NodeBST *current = root;
		while (current != nullptr){
			if (value.getSongTitle() < current->data->getSongTitle()){
				if (current->left == nullptr){
					current->left = new_node;
					current = nullptr;
				}
				else{
					current = current->left;
				}
			}
			else{
				if (current->right == nullptr){
					current->right = new_node;
					current = nullptr;
				}
				else{
					current = current->right;
				}
			}
		}
	}
	return true;
}

void BST_songTitle::remove(Song &value){
	NodeBST *parent = nullptr;
	NodeBST *current = root; 
	while(current != nullptr){
		if(current->data->getSongTitle() == value.getSongTitle()){
			if(current->left == nullptr && current->right == nullptr){ //remove leaf
				if(parent == nullptr){
					root = nullptr;
				}
				else if(parent->left == current){
					parent->left = nullptr;
				}
				else{
					parent->right = nullptr;
				}
				delete current;
			}
			else if(current->right == nullptr){ // remove if only one left child
				if(parent == nullptr){
					root = current->left;
				}
				else if(parent->left == current){
					parent->left = current->left;
				}
				else{
					parent->right = current->left;
				}
				delete current;
			}
			else if(current->left == nullptr){ // remove if only one right child
				if(parent == nullptr){
					root = current->right;
				}
				else if(parent->left == current){
					parent->left = current->right;
				}
				else{
					parent->left = current->right;
				}
				delete current;
			}
			else{ // remove node with two children
				NodeBST *succesor = current->right;
				NodeBST *succesorParent = current;
				while(succesor->left != nullptr){
					succesorParent = succesor;
					succesor = succesor->left;
				}
				Song *succesorData = succesor->data;
				if(succesorParent != current){
					if(succesor->right != nullptr){
						succesorParent->left = succesor->right;
					} else {
						succesorParent->left = nullptr;
					}
				} else {
					if(succesor->right != nullptr){
						succesorParent->right = succesor->right;
					} else {
						succesorParent->right = nullptr;
					}
				}
				delete succesor;
				current->data = succesorData;
			}
			return;
		}
		else if(value.getSongTitle() < current->data->getSongTitle()){
			parent = current;
			current = current->left;
		}
		else{
			parent = current;
			current = current->right;
		}
	}
}

bool BST_songTitle::isEmpty(){
	return root == nullptr;
}

BST_songTitle::NodeBST *BST_songTitle::search(string &value){
	NodeBST *current = root;
	while (current != nullptr){
		if (current->data->getSongTitle() == value){
			return current;
		}
		else if (value < current->data->getSongTitle()){
			current = current->left;
		}
		else{
			current = current->right;
		}
	}
	cout << endl << "Song not found" << endl;
	return nullptr;
}

int BST_songTitle::listenHelper(string &value, int &seconds){
	NodeBST *node = search(value);
	if(node != nullptr){
		node->data->setDuration(seconds);									// shows how many seconds you just listened for, not how long its been listened to in total
		cout << endl << "Listened to "<< node->data->getSongTitle() << " for " << seconds << " seconds"<< endl;
		return node->data->getIdx();
	}
	return -1;
}


// ***** jacksons helper mess \/ ***** 

int BST_songTitle::getHeapIndexHelper(string &value) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToGetHeapIndex = *(node->data);
        return songToGetHeapIndex.getIdx();
    }else {
		//cout << "Node is null -- BST_songTitle::getHeapIndexHelper" << endl;
		return -1;
	}
}

bool BST_songTitle::getRemovedStatHelper(string &value) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToGetRemovedStatus = *(node->data);
        return songToGetRemovedStatus.getRemovedStat();
    }else {
		return false;
	}
}
void BST_songTitle::setRemovedStatHelper(string &value, bool status) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToSetRemovedStatus = *(node->data);
        return songToSetRemovedStatus.setRemovedStat(status);
    }
}

void BST_songTitle::setSongIDHelper(string &value, int newID) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToSetRemovedStatus = *(node->data);
        return songToSetRemovedStatus.setSongID(newID);
    }
}


bool BST_songTitle::getFavoriteStatHelper(string &value) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToGetFavStatus = *(node->data);
        return songToGetFavStatus.getisFavorite();
    }
	return false;
	
}
void BST_songTitle::setFavoriteStatHelper(string &value, bool status) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
	{
        Song &songToSetFavStatus = *(node->data);
        return songToSetFavStatus.setIsFavorite(status);
    }
} 


void BST_songTitle::removeHelper(string &value) {
    NodeBST *node = findAndReturnSong(value);
    if (node != nullptr) 
    {
        Song *songToRemove = node->data;
        remove(*songToRemove);
        //delete songToRemove;
    }
}
// uses the songs title to search for, and return the correct node
BST_songTitle::NodeBST* BST_songTitle::findAndReturnSong(string &givenTitle) {
    NodeBST *current = root;
    while (current != nullptr) 
	{
        if (current->data->getSongTitle() == givenTitle) {
            return current; // pointer to the node containing the song
        } 
		else if (givenTitle < current->data->getSongTitle()) {
            current = current->left;
        } 
		else {
            current = current->right;
        }
    }
    return nullptr; 
}


// ***** jacksons helper mess /\ ***** 






void BST_songTitle::printInOrder(NodeBST *node){
	if (node != nullptr){
		printInOrder(node->left);
		cout << node->data << " " << endl;
		printInOrder(node->right);
	}
}

BST_songTitle::NodeBST *BST_songTitle::getRoot(){
	return root;
}