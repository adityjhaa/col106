#include "string"
#include "ulimitedrational.h"
using namespace std;

class SymEntry {
public:
    string key;
    UnlimitedRational* val;
    
    SymEntry* left;
    SymEntry* right;

    SymEntry();
    SymEntry(string k, UnlimitedRational* v);

    ~SymEntry();
    
};