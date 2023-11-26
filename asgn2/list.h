#pragma once 
#include "node.h"

/* PART B */
/* Stacks using Linked Lists */

/* 
Linked Lists with Sentinels 
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/

class List {
private: 
    int size;
    Node* sentinel_head;
    Node* sentinel_tail;

public: 
    List();

    ~List();

    // Insert an element at the tail of the linked list 
    void insert(int v);

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int delete_tail();

    // Return the size of the linked list 
    // Do not count the sentinel elements
    int get_size(); 

    // Return a pointer to the sentinel head of the linked list 
    Node* get_head();

};