#ifndef HEAP_H
#define HEAP_H
#include "Song.h"
#include <vector>
using namespace std;

class Heap {
public:
    Heap():heap(){}// Default cnstr which init vector -Kian 4/19/24
    bool Empty();
    void Remove(int index);
    void Push(Song *value);                 
    Song* Pop();
    void Display_heap();
    int Peek(); 
    int Size();
    void DisplayHeapAsTree(); 
    void PercolateUp(int index); 
private:
    vector<Song*> heap;
    void PercolateDown(int index);
    void swapNodesInHeap(int idx1,int idx2);
    int CalculateParentIndex(int index);
};

#endif // HEAP_H