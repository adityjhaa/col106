#pragma once
#include "heapnode.h"
using namespace std;

class MinHeap{
  private:
  int size = 0;
  HeapNode* root = NULL;
  
  public:
  MinHeap();
  ~MinHeap();

  void push_heap(int num); // Insert num into the heap
  int get_min(); // Returns min of the heap (which must be at root)
  void pop(); // Deletes the min element from the heap
};