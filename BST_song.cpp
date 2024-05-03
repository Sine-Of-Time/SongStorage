#include <string>
#include <iostream>
#include "BST_song.h"

using namespace std;

BST_song::BST_song(){
	root = nullptr;
}

void BST_song::destroy(NodeBST *node){
	if (node != nullptr){
		destroy(node->left);
		destroy(node->right);
		delete node->data;
		delete node;
	}
}

BST_song::~BST_song(){
	destroy(root);
}

bool BST_song::insert(Song &value){
	NodeBST *new_node = new NodeBST();
	new_node->data = &value;
	if (root == nullptr){
		root = new_node;
	}
	else{
		NodeBST *current = root;
		while (current != nullptr){
			if (value.getSongID() < current->data->getSongID()){
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

void BST_song::remove(Song &value){
	NodeBST *parent = nullptr;
	NodeBST *current = root; 
	while(current != nullptr){
		if(current->data->getSongID() == value.getSongID()){
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
		else if(value.getSongID() < current->data->getSongID()){
			parent = current;
			current = current->left;
		}
		else{
			parent = current;
			current = current->right;
		}
	}
}

bool BST_song::isEmpty(){
	return root == nullptr;
}

bool BST_song::search(Song &value){
	NodeBST *current = root;
	while (current != nullptr){
		if (current->data->getSongID() == value.getSongID()){
			return true;
		}
		else if (value.getSongID() < current->data->getSongID()){
			current = current->left;
		}
		else{
			current = current->right;
		}
	}
	return false;
}

void BST_song::printInOrder(NodeBST *node){   
	if(root != nullptr)
	{
		if (node != nullptr)
		{
			printInOrder(node->left);
			if(node->data->getRemovedStat() == false) // only print out if the song hasnt been removed 
			{
				cout << endl << node->data->getSongID() << " " << node->data->getSongTitle() << " has been listened to for " << node->data->getSongDuration() << " seconds" << endl;
			}
			printInOrder(node->right);
		}
	}
	else
	{
		cout << endl << "Your song list is empty" << endl;
	}
}

BST_song::NodeBST *BST_song::getRoot(){
	return root;
}