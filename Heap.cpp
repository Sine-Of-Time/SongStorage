#include "Heap.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Heap::Peek(){
  if(heap.empty())return -1234; //Arbitary value. Can be changed. -Kian 10:26pm 4/17
  return heap[0]->getSongDuration();//Assuming idx=0 is top. -Kian 10:27pm 4/17
}

void Heap::Push(Song *value) {
    int index = heap.size();
    heap.push_back(value);
    value->setIdx(index);
    PercolateUp(index); //Ensuring every element is in its proper place -Kian 4/17
}

Song* Heap::Pop() {//Changed to return Song* on 4/28/24 10:52AM -Kian F
    if (heap.empty()){
        cout<< "Heap is empty!"<<endl;
        return nullptr;
    } 
    Song* top=heap[0];
    heap[0]=heap.back(); 
    heap.pop_back();                
    if(!heap.empty())PercolateDown(0);//This prevents out of bounds errors when vector is empty-Kian F 4/28 12:11PM   
    return top;
}

void Heap::PercolateUp(int index) {// Tested on 4/19/24 @6:55pm with Push() -4/19/24 KF
    if (index<0) return;
    int parentIndex=CalculateParentIndex(index);
    if (heap[index]->getSongDuration()>heap[parentIndex]->getSongDuration()) { 
        Song *temp=heap[index];//Temp storage for child value - 4/19/2024 Kian F
        heap[index]=heap[parentIndex];//Move parent value down - 4/19/2024 Kian F
        heap[parentIndex]=temp;// Put the child value at correct position - 4/19/2024 Kian F
        heap[index]->setIdx(index);
        heap[parentIndex]->setIdx(parentIndex);
        PercolateUp(parentIndex);
    }
}

void Heap::PercolateDown(int index){//Tested as of 4/21/24 1:58PM-KF
    int childIndex=2*index + 1;//Left child index-KF 4/20
    Song *value=heap[index];

    while(childIndex<(int)heap.size()){//Finding max-KF 4/20
        int maxValue=value->getSongDuration();
        int maxIndex=-1;

        for (int i = 0;i< 2 && i + childIndex < (int)heap.size(); i++) {
            int temp=i+childIndex;
            if (heap[temp]->getSongDuration()>maxValue) {
                maxValue=heap[temp]->getSongDuration();
                maxIndex=temp;
            }
        }

        if(maxValue==value->getSongDuration()){
            return; //Restore heap-KF 4/20
        }else{
            swapNodesInHeap(index,maxIndex);//Tested as of 4/21/24 1:55PM-KF
            index=maxIndex;//For the next iter-KF 4/20
            childIndex=2*index + 1; 
        }
    }
}

void Heap::Remove(int index){//Tested 9:39PM 4/21/2024-KF
    if (index<0||index>=(int)heap.size()){
        return;
    }
    heap[index]=heap.back();// Swap the element to be removed with the last element-KF 4/20 11:35AM
    heap.pop_back();

    //The following ensures the vector is still a heap-KF 4/20 11:37AM
    if(index==0||heap[index]<heap[CalculateParentIndex(index)]){
        PercolateDown(index);//Move the swapped value down-KF 4/20
    }else{
        PercolateUp(index);//Move the swapped Value up-KF 4/20
    }
}

int Heap::Size(){
    return heap.size();
}

bool Heap::Empty(){
    return heap.empty();
}

int Heap::CalculateParentIndex(int index){ //Prevents rewriting the same code -KF 4/20 
    return (index-1)/2;
}

void Heap::Display_heap(){//Mostly for debugging -KF 4/20
    // if (heap.empty()) {
    //     cout<<"Heap is empty!"<<endl;
    //     return;
    // }

    // cout<<"Heap elements: ";
    // for (int element : heap){
    //     cout << element << " ";
    // }
    // cout << endl;
}

void Heap::swapNodesInHeap(int idx1,int idx2){//Feels wrong-KF 4/20/24 12:25PM
    Song *temp=heap[idx1];
    heap[idx1]=heap[idx2];
    heap[idx2]=temp;
}
