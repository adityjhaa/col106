#pragma once
#include <string>
using namespace std;

class UnlimitedInt {
private:

    int size;
    int sign; // 1 if positive, -1 if negative
    int capacity; // Capacity of the unlimited_int array
    int* unlimited_int; // The array to store the unlimited int
    
public:

    UnlimitedInt();
    UnlimitedInt(string s); // Create from string 
    UnlimitedInt(int i); // Create from int
    UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz); // Complete constructor

    ~UnlimitedInt();

    // Return the size of the unlimited int
    int get_size();

    // Return the unlimited_int array
    int* get_array(); 

    // Get sign
    int get_sign();

    // Get capacity 
    int get_capacity();

    // Implement these integer operations as they are defined for integers in mathematics
    // (Since there are no size restrictions)
    static UnlimitedInt* add(UnlimitedInt* i1, UnlimitedInt* i2);
    static UnlimitedInt* sub(UnlimitedInt* i1, UnlimitedInt* i2);
    static UnlimitedInt* mul(UnlimitedInt* i1, UnlimitedInt* i2);
    static UnlimitedInt* div(UnlimitedInt* i1, UnlimitedInt* i2);
    static UnlimitedInt* mod(UnlimitedInt* i1, UnlimitedInt* i2);

    // Conversion Functions 
    string to_string();
    
};