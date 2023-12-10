#pragma once
#include "exprtreenode.h"
#include "symtable.h"
#include <vector>

class Evaluator {
public:
    vector<ExprTreeNode*> expr_trees;
    SymbolTable* symtable;

    Evaluator();

    ~Evaluator();

    // Read an input vector of tokens (strings)
    // Parse it and convert it to a parse tree
    // Push the root of the tree in the expr_trees
    void parse(vector<string> code);

    // Evaluate the last element of the expr_trees
    // This function is guaranteed to be called immediately 
    // after a call to parse, and will be only called ONCE
    // for a tree
    // Also populate the symbol tables
    void eval();

};