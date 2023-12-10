#pragma once
#include "entry.h"
#include "string"
using namespace std;

class SymbolTable {
private:
    int size;
    SymEntry* root;

public: 

    SymbolTable();

    ~SymbolTable();

    // Insert a key value pair in the symbol table
    void insert(string k, UnlimitedRational* v);

    // Remove a key (and value) in the symbol table
    void remove(string k);
 
    // Find the val corresponding to the key in the symbol table
    UnlimitedRational* search(string k);

    // Get size
    int get_size();

    // Get root 
    SymEntry* get_root();
};