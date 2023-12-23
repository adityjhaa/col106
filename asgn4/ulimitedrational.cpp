#include "ulimitedrational.h"

bool grtr(UnlimitedInt* i1, UnlimitedInt* i2){
    int size1 = i1->get_size();
    int size2 = i2->get_size();
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    int* array1 = i1->get_array();
    int* array2 = i2->get_array();
    if(sign1 == 0){
        if(sign2 == -1){return true;}
        else{return false;}
    }
    if(sign2 == 0){
        if(sign1 == 1){return true;}
        else{return false;}
    }
    if(sign1 == 1 and sign2 == 1){
        if(size1 > size2){return true;}
        else if(size2 > size1){return false;}
        else{
            for(int i = 0; i < size1; i++){
                if(*(array1+i) > *(array2+i)){return true;}
                else if(*(array1+i) < *(array2+i)){return false;}
                else{continue;}
            }   
            return true;
        }
    }
    if(sign1 == 1 and sign2 == -1){return true;}
    if(sign1 == -1 and sign2 == 1){return false;}
    if(sign1 == -1 and sign2 == -1){
        if(size1 > size2){return false;}
        else if(size2 > size1){return true;}
        else{   
            for(int i = 0; i < size1; i++){
                if(*(array1+i) > *(array2+i)){return false;}
                else if(*(array1+i) < *(array2+i)){return true;}
                else{continue;}
            }   
            return true;
        }
    }
    return true;
}

UnlimitedInt* gcd(UnlimitedInt* i1, UnlimitedInt* i2){

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    UnlimitedInt* m = new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_size());
    UnlimitedInt* n = new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_size());
    if(sign1 == 0){
        if(i2->get_sign() == 0){
            return i2;
        }
        return n;
    }else{
        UnlimitedInt* p = new UnlimitedInt(0);
        if(grtr(m,n) == true){
            p = gcd(p->mod(m,n),n);
            return p;
        }else{
            p = gcd(p->mod(n,m),m);
            return p;
        }
    }
}

UnlimitedRational::UnlimitedRational(){}
UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
    p = num;
    q = den;
}

UnlimitedRational::~UnlimitedRational(){
    p->~UnlimitedInt();
    q->~UnlimitedInt();
}

UnlimitedInt* UnlimitedRational::get_p(){
    UnlimitedInt* gcdofnumden = gcd(p,q);
    UnlimitedInt* c = new UnlimitedInt(0);
    UnlimitedInt* newnum = c->div(p,gcdofnumden);
    return newnum;
}

UnlimitedInt* UnlimitedRational::get_q(){
    UnlimitedInt* gcdofnumden = gcd(p,q);
    UnlimitedInt* c = new UnlimitedInt(0);
    UnlimitedInt* newden = c->div(q,gcdofnumden);
    c = newden;
    return c;
}

string UnlimitedRational::get_p_str(){
    if(p->to_string() == "0"){
        return "0";
    }
    UnlimitedInt* gcdofnumden = gcd(p,q);
    UnlimitedInt c(0);
    UnlimitedInt* newnum = c.div(p,gcdofnumden);
    return newnum->to_string();
}

string UnlimitedRational::get_q_str(){
    if(q->to_string() == "0"){
        return "0";
    }
    
    UnlimitedInt* gcdofnumden = gcd(p,q);
    UnlimitedInt c(0);
    UnlimitedInt* newden = c.div(q,gcdofnumden);
    return newden->to_string();
}

string UnlimitedRational::get_frac_str()
{return get_p_str() + "/" + get_q_str();}


UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){   
    string s1 = i1->get_frac_str();
    string s2 = i2->get_frac_str();
    if(s1 == "0/0" or s2 == "0/0"){
        UnlimitedInt q(0);
        UnlimitedRational* p = new UnlimitedRational(&q,&q);
        return p;
    }else{
        UnlimitedInt* num1 = i1->get_p();
        UnlimitedInt* num2 = i2->get_p();
        UnlimitedInt* den1 = i1->get_q();
        UnlimitedInt* den2 = i2->get_q();
        UnlimitedInt c(0);

        UnlimitedInt* sum1 = c.mul(num1,den2);
        UnlimitedInt* sum2 = c.mul(num2,den1);

        UnlimitedInt* finalsum = c.add(sum1,sum2);

        UnlimitedInt* step2den = c.mul(den1,den2);

        UnlimitedInt* gcdofnumden = gcd(finalsum, step2den);

        UnlimitedInt* finalnum = c.div(finalsum,gcdofnumden);
        UnlimitedInt* finalden = c.div(step2den,gcdofnumden);

        UnlimitedRational* q = new UnlimitedRational(finalnum,finalden);
        c.~UnlimitedInt();
        return q;
    }

    return nullptr;
}

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    string s1 = i1->get_frac_str();
    string s2 = i2->get_frac_str();
    if(s1 == "0/0" or s2 == "0/0"){
        UnlimitedInt q(0);
        UnlimitedRational* p = new UnlimitedRational(&q,&q);
        return p;
    }else{
        UnlimitedInt* num1 = i1->get_p();
        UnlimitedInt* num2 = i2->get_p();
        UnlimitedInt* den1 = i1->get_q();
        UnlimitedInt* den2 = i2->get_q();
        UnlimitedInt c(0);

        UnlimitedInt* sum1 = c.mul(num1,den2);
        UnlimitedInt* sum2 = c.mul(num2,den1);

        UnlimitedInt* finalsum = c.sub(sum1,sum2);

        UnlimitedInt* step2den = c.mul(den1,den2);

        UnlimitedInt* gcdofnumden = gcd(finalsum, step2den);

        UnlimitedInt* finalnum = c.div(finalsum,gcdofnumden);
        UnlimitedInt* finalden = c.div(step2den,gcdofnumden);

        UnlimitedRational* q = new UnlimitedRational(finalnum,finalden);
        return q;
    }
    return nullptr;
}

UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
    string s1 = i1->get_frac_str();
    string s2 = i2->get_frac_str();
    if(s1 == "0/0" or s2 == "0/0"){
        UnlimitedInt q(0);
        UnlimitedRational* p = new UnlimitedRational(&q,&q);
        return p;
    }else{
        UnlimitedInt* num1 = i1->get_p();
        UnlimitedInt* num2 = i2->get_p();
        UnlimitedInt* den1 = i1->get_q();
        UnlimitedInt* den2 = i2->get_q();
        UnlimitedInt c(0);

        UnlimitedInt* mul1 = c.mul(num1,num2);
        UnlimitedInt* mul2 = c.mul(den1,den2);

        UnlimitedInt* gcdofnumden = gcd(mul1, mul2);

        if(gcdofnumden->to_string() =="0"){
            UnlimitedRational* q = new UnlimitedRational(&c,&c);
            return q;
        }else{
            UnlimitedInt* finalnum = c.div(mul1,gcdofnumden);
            UnlimitedInt* finalden = c.div(mul2,gcdofnumden);
            UnlimitedRational* q = new UnlimitedRational(finalnum,finalden);
            return q;
        }
    }
    return nullptr;
}

UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
    string s1 = i1->get_frac_str();
    string s2 = i2->get_frac_str();
    if(s1 == "0/0" or s2 == "0/0"){
        UnlimitedInt q(0);
        UnlimitedRational* p = new UnlimitedRational(&q,&q);
        return p;
    }else{
        UnlimitedInt* num1 = i1->get_p();
        UnlimitedInt* num2 = i2->get_p();
        UnlimitedInt* den1 = i1->get_q();
        UnlimitedInt* den2 = i2->get_q();
        UnlimitedInt c(0);

        if(num1->to_string() == "0"){
            UnlimitedInt q(0);
            UnlimitedInt s("1");
            UnlimitedRational* p = new UnlimitedRational(&q,&s);
            return p;
        }
        if(num2->to_string() == "0"){
            UnlimitedInt q(0);
            UnlimitedRational* p = new UnlimitedRational(&q,&q);
            return p;
        }else{
            UnlimitedInt* mul1 = c.mul(num1,den2);
            UnlimitedInt* mul2 = c.mul(den1,num2);

            UnlimitedInt* gcdofnumden = gcd(mul1, mul2);

            UnlimitedInt* finalnum = c.div(mul1,gcdofnumden);
            UnlimitedInt* finalden = c.div(mul2,gcdofnumden);
            UnlimitedRational* q = new UnlimitedRational(finalnum,finalden);
            return q;
        }
    }
    return nullptr;
}
