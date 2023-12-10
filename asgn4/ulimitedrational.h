#pragma once
#include "ulimitedint.h"
#include <string>
using namespace std;

class UnlimitedRational {
private:
    UnlimitedInt* p;
    UnlimitedInt* q;

public:

    UnlimitedRational();
    UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den);

    ~UnlimitedRational();

    UnlimitedInt* get_p();

    UnlimitedInt* get_q();

    string get_p_str(); // Return the numerator as a string

    string get_q_str(); // Return the denominator as a string
    
    string get_frac_str(); // Return the rational as "p/q"

    // Rational arithmetic operations
    static UnlimitedRational* add(UnlimitedRational* i1, UnlimitedRational* i2);
    static UnlimitedRational* sub(UnlimitedRational* i1, UnlimitedRational* i2);
    static UnlimitedRational* mul(UnlimitedRational* i1, UnlimitedRational* i2);
    static UnlimitedRational* div(UnlimitedRational* i1, UnlimitedRational* i2);
    
};
