#pragma once
#include "symnode.h"
#include "string"
using namespace std;

class SymbolTable {
private:
    int size = 0;
    SymNode* root = NULL;

public: 

    SymbolTable();
    ~SymbolTable();

    // Insert a key in the symbol table, there is no value now
    void insert(string k);

    // Remove a key (and it's memory address) in the symbol table
    void remove(string k);
 
    // Find the memory address corresponding to the variable in the symbol table
    int search(string k);

    // Assigns a memory address to the key in the symbol table
    void assign_address(string k,int idx);

    // Get size
    int get_size();

    // Get root 
    SymNode* get_root();
};