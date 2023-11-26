#pragma once 

/* PART A */
/* Stacks using Fixed Size Arrays */

class Stack_A {
private:
    int stk[1024]; // The fixed size array
    int size; // Number of elements in the stack

public: 
    // Constructor
    Stack_A();

    void push(int data);

    int pop();

    int get_element_from_top(int idx);

    int get_element_from_bottom(int idx);

    void print_stack(bool top_or_bottom);

    int add();

    int subtract();

    int multiply();

    int divide(); 

    int* get_stack(); // Get a pointer to the array

    int get_size(); // Get the size of the stack

};
