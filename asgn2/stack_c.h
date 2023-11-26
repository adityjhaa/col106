#pragma once 
#include "list.h"

/* PART B */
/* Stacks using Linked Lists */

class Stack_C {
private:
    List* stk; // The linked list

public: 
    // Constructor
    Stack_C();

    // Destructor
    ~Stack_C();

    void push(int data);

    int pop();

    int get_element_from_top(int idx);

    int get_element_from_bottom(int idx);

    void print_stack(bool top_or_bottom);

    int add();

    int subtract();

    int multiply();

    int divide(); 

    List* get_stack(); // Get a pointer to the linked list representing the stack

    int get_size(); // Get the size of the stack
};
