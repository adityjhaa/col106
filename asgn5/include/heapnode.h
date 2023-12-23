#pragma once
#include <string>
using namespace std;

class HeapNode{
  public:
  int val;
  HeapNode* par = NULL;
  HeapNode* left = NULL;
  HeapNode* right = NULL;
  
  HeapNode();
  HeapNode(int _val);
  
  ~HeapNode();
};