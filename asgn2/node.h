#pragma once 

/* PART B */
/* Stacks using Linked Lists */

class Node {
private: 
    int value;
    bool is_sentinel;

public: 
    Node* next;
    Node* prev;

    // Use to construct a sentinel node (see list.h)
    Node(bool sentinel=true);   

    // Use to construct a regular node
    Node(int v, Node* nxt, Node* prv);

    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
    bool is_sentinel_node();

    // Return the value of a node
    int get_value();
};