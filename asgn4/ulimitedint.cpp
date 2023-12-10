#include "ulimitedint.h"

bool greatr(UnlimitedInt* i1, UnlimitedInt* i2){
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
        else if (size2 > size1){return false;}
        else{
            for (int i = 0; i < size1; i++){
                if (*(array1+i) > *(array2+i)){return true;}
                else if(*(array1+i) < *(array2+i)){return false;}
                else{continue;}
            }   
            return true;
        }
    }

    if(sign1 == 1 and sign2 == -1){
        return true;
    }

    if(sign1 == -1 and sign2 == 1){
        return false;
    }if(sign1 == -1 and sign2 == -1){
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

string multiplication(UnlimitedInt* i1, UnlimitedInt* i2){
    int size1 = i1->get_size();
    int size2 = i2->get_size();
    int* array1 = i1->get_array();
    int* array2 = i2->get_array();
    int ans[size1+size2-1] = {};
    for(int i = 0; i < size1; i++){
        int a = *(array1 + i);
        for(int j = 0; j < size2; j++){
            int b = *(array2 + j);
            int val = a*b;
            ans[i+j] += val;
        }
    }

    int ansinvert[size1+size2-1];
    for(int i = 0; i < size1+size2-1; i++){
        ansinvert[i] = ans[size1+size2-1 -1 -i];
    }
    int final[size1+size2];
    int index = 0;
    int carry = 0;
    int val = 0;

    for(int i = 0; i < size1+size2-1; i++){
        int val = ansinvert[index] + carry;
        final[index] = val%10;
        carry = val/10;
        index++;
    }

    if(carry > 0){
        final[index] = carry;
        index++;
    }
    string s = "";
    for(int i = 0; i < index; i++){
        s += std::to_string(final[index-1-i]);
    }
    return s;
}

string subtraction(UnlimitedInt* i1, UnlimitedInt* i2){
    int a = i1->get_size();
    int b = i2->get_size();
    int* p1 = i1->get_array();
    int* p2 = i2->get_array();
    int c = (a<b)?a:b;
    int d = (a>b)?a:b;
    int ans[d];
    int borrow = 0;
    int val = 0;
    int ind = 0;
    for(int i = 0; i < c; i++){
        int x = *(p1+a-1-i);
        int y = *(p2+b-1-i);

        int val = x-borrow - y;
        if(val >= 0){
            borrow = 0;
            ans[ind] = val;
            ind++;
        }else{
            borrow = 1;
            ans[ind] = 10+val;
            ind++;
        }

    }
    for(int i = c; i < d; i++){
        int x = *(p1+a-1-i);
        int val = x-borrow;
        if(val >= 0){
            borrow = 0;
            ans[ind] = val%10;
            ind++;
        }else{
            borrow = 1;
            ans[ind] = 10+val;
            ind++;
        }
    }

    string s = "";
    int q = 0;
    for(int i = 0; i < ind; i++){
        if(ans[ind-1-i] == 0){q++; continue;}
        else{break;}
    }

    for(int i = q; i < ind; i++){
        s += std::to_string(ans[ind -i - 1]);
    }
    if(s == ""){
        return "0";
    }
    return s;
}

string addition(UnlimitedInt* i1, UnlimitedInt* i2){
    int a = i1->get_size();
    int b = i2->get_size();
    int* p1 = i1->get_array();
    int* p2 = i2->get_array();
    int c = (a<b)?a:b;
    int d = (a>b)?a:b;
    int ans[d+1];
    int index = 0;
    int carry = 0;
    int val = 0;
    for(int i = 0; i < c; i++){
        int x = *(p1+a-1-i);
        int y = *(p2+b-1-i);

        val = (x+y + carry)%10;
        carry = (x+y + carry)/10;

        ans[index] = val;
        index++;
    }
    if(c == a){
        for(int i = c; i < b; i++){
            int y = *(p2+b-1-i);
            val = (y + carry)%10;
            carry = (y + carry)/10;

            ans[index] = val;
            index++;
        }
        
    }else if(c == b){
        for(int i = c; i < a; i++){
            int x = *(p1+a-1-i);
            val = (x+ carry)%10;
            carry = (x+ carry)/10;
            ans[index] = val;
            index++;
        }
        
    }
    if(ans[index-1] > 9){
        int e = ans[index-1];
        ans[index-1] = e%10;
        index++;
        ans[index-1] = e/10;
    }
    string s = "";
    for(int i = 0; i < index; i++){
        s += std::to_string(ans[index-1-i]);
    }

    return s;
}

string division(UnlimitedInt* i1, UnlimitedInt* i2){
    UnlimitedInt* a = new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_size());
    UnlimitedInt* b = new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_size());
    if(greatr(a,b) == false){
        a->~UnlimitedInt();
        b->~UnlimitedInt();
        return "0";
    }
    string r = b->to_string();
    int k = 0;
    for(int i = 0; i < i1->get_size()-i2->get_size()-1; i++){
        r += "0";
    }
    UnlimitedInt* a1 = new UnlimitedInt(r);
    while(greatr(a,a1)){
        UnlimitedInt acopy(a->get_array(),a->get_capacity(),a->get_sign(),a->get_size());
        a->~UnlimitedInt();
        *a = acopy;
        string sub1 = subtraction(a,a1);
        k++;
        UnlimitedInt* a2 = new UnlimitedInt(sub1);
        a = a2;
    }
    string r1 = std::to_string(k);
    for(int i = 0; i < i1->get_size()-i2->get_size()-1; i++){
        r1 += "0";
    }
    UnlimitedInt aux1(r1);
    UnlimitedInt aux2(division(a,b));
    if(greatr(a,b)){
        return addition(&aux1,&aux2);
    }
    a->~UnlimitedInt();
    b->~UnlimitedInt();
    a1->~UnlimitedInt();
    return r1;
}

UnlimitedInt::UnlimitedInt(){
    size = 0;
    capacity = 0;
    unlimited_int = nullptr;
    sign = 0;
}

UnlimitedInt::UnlimitedInt(string s){
    capacity = s.length();
    unlimited_int = new int[capacity];
    if(s[0] == '0'){
        size = 1;
        sign = 0;
        unlimited_int[0]= 0;
    }
    else if (s[0] == '-'){
        size = 0;
        sign = -1;
        for(int i = 0; i < s.length()-1; i++){
            unlimited_int[i] = s[i+1] - '0';
            size ++;
        }
    }else{
        size = 0;
        sign = 1;
        for(int i = 0; i < s.length(); i++){            
            unlimited_int[i] = s[i] - '0';
            size ++;        
        }
    }
}

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
    capacity = cap;
    sign = sgn;
    size = sz;
    unlimited_int = new int[capacity];
    for(int i = 0; i < size; i++){
        unlimited_int[i] = ulimited_int[i];
    }
}

UnlimitedInt::UnlimitedInt(int i){
    string s = std::to_string(i);
    capacity = s.length();
    unlimited_int = new int[capacity];
    if(s[0] == '0'){
        size = 1;
        sign = 0;
        unlimited_int[0]= 0;
    }
    else if(s[0] == '-'){
        size = 0;
        sign = -1;
        for(int i = 1; i < s.length(); i++){
            unlimited_int[i-1] = s[i] - '0';
            size ++;
        }
    }else{
        size = 0;
        sign = 1;
        for(int i = 0; i < s.length(); i++){
            unlimited_int[i] = s[i] - '0';
            size ++;        
        }
    }
}

UnlimitedInt::~UnlimitedInt(){
    if (this != nullptr){
        delete [] unlimited_int;
        unlimited_int = nullptr;
    }
}

int UnlimitedInt::get_capacity(){return capacity;}

int UnlimitedInt::get_size(){return size;}

int UnlimitedInt::get_sign(){return sign;}


UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    if(sign1*sign2 > 0){
        if(sign1 == -1 and sign2 == -1){
            string s = "-" + addition(i1,i2);
            UnlimitedInt* q = new UnlimitedInt(s);
            return q;
        }
        if(sign1 == 1 and sign2 == 1){
            string s = addition(i1,i2);
            UnlimitedInt* q = new UnlimitedInt(s);
            return q;
        }
    }

    if(sign1*sign2 == 0){
        if(sign1 == 0){
            return i2;
        }
        else{
            return i1;
        }
    }

    if(sign1*sign2 < 0){
        if(sign1 < 0){
            UnlimitedInt* p = new UnlimitedInt(0);
            UnlimitedInt m(i1->get_array(),i1->get_capacity(),1,i1->get_size());
            p = p->sub(i2,&m);
            return p;
        }else{
            UnlimitedInt* p = new UnlimitedInt(0);
            UnlimitedInt n(i2->get_array(),i2->get_capacity(),1,i2->get_size());
            p = p->sub(i1,&n);
            return p;
        }
    }
    return nullptr;
}

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    if(i1->to_string() == i2->to_string()){
        UnlimitedInt *q = new UnlimitedInt(0);
        return q;
    }else if(sign1 == 1 and sign2 == 1){
        if(greatr(i1,i2)){
            string s = subtraction(i1,i2);
            UnlimitedInt* q = new UnlimitedInt(s);
            return q;
        }else{
            string s = "-"+ subtraction(i2,i1);
            UnlimitedInt* q = new UnlimitedInt(s);
            return q;
        }

    }else if(sign1 == -1 and sign2 == -1){
        UnlimitedInt m(i1->get_array(),i1->get_capacity(),1,i1->get_size());
        UnlimitedInt n(i2->get_array(),i2->get_capacity(),1,i2->get_size());
        UnlimitedInt* p = new UnlimitedInt();
        p = p->sub(&n,&m);
        return p;
    }else if(sign1 == 0 and sign2 == 1){
        UnlimitedInt* p = new UnlimitedInt("-" + i2->to_string());
        return p;
    }else if(sign1 == 0 and sign2 == -1){
        UnlimitedInt* p = new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_size());
        return p;
    }else if(sign2 == 0){
        return i1;
    }else if(sign1 == -1 and sign2 == 1){
        UnlimitedInt m(i1->get_array(),i1->get_capacity(),1,i1->get_size());
        UnlimitedInt* p = new UnlimitedInt();
        p = p->add(&m,i2);
        p->sign = -1;
        return p;
    }else if(sign1 == 1 and sign2 == -1){
        UnlimitedInt n(i2->get_array(),i2->get_capacity(),1,i2->get_size());
        UnlimitedInt* p = new UnlimitedInt();
        p = p->add(i1,&n);
        p->sign = 1;
        return p;
    }
    return nullptr;
}

string UnlimitedInt::to_string(){
    if(sign == 0){return "0";}
    else if(sign == -1){
        string s = "-";
        for(int i = 0; i < size; i++){
            int k = unlimited_int[i];
            s = s + std::to_string(k);
        }
        return s;
    }
    else{
        string s = "";
        for(int i = 0; i < size; i++){
            int k = unlimited_int[i];
            //string p = to_string(k);
            s = s + std::to_string(k);
        }

        return s;
    }

}
UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    if(sign1*sign2 == 1){
        string s = multiplication(i1,i2);
        UnlimitedInt* q = new UnlimitedInt(s);
        return q;
    }

    else if(sign1 == 0 || sign2 == 0){
        UnlimitedInt* q = new UnlimitedInt(0);
        return q;
    }

    else if(sign1*sign2 == -1){
        string s = multiplication(i1,i2);
        UnlimitedInt* q = new UnlimitedInt("-" + s);
        return q;
    } 

    return nullptr;

}
UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){
    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();
    if(sign1 == 0){
        UnlimitedInt* q = new UnlimitedInt("0");
        return q;
    }
    
    UnlimitedInt m(i1->get_array(),i1->get_capacity(),1,i1->get_size());
    UnlimitedInt n(i2->get_array(),i2->get_capacity(),1,i2->get_size());

    if(sign1*sign2 == 1){
        string a = division(&m,&n);
        UnlimitedInt* q = new UnlimitedInt(a);
        return q;

    }
    
    if(sign1*sign2 == -1){
        string a = division(&m,&n);
        UnlimitedInt* mod1 = UnlimitedInt::mod(&m,&n);
        if(mod1->get_sign() == 0){
            mod1->~UnlimitedInt();
            string b = "-"+a;
            UnlimitedInt* q = new UnlimitedInt(b);
            return q;

        }
        else{
            mod1->~UnlimitedInt();
            UnlimitedInt c1(a);
            UnlimitedInt c2("1");
            string e = "-" + addition(&c1,&c2);
            UnlimitedInt* q = new UnlimitedInt(e);
            return q;

        }

        
    }

    return nullptr;    
}

UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    UnlimitedInt m(i1->get_array(),i1->get_capacity(),1,i1->get_size());
    UnlimitedInt n(i2->get_array(),i2->get_capacity(),1,i2->get_size());

    string k = division(&m,&n);
    UnlimitedInt p1(k);
    string k1 = multiplication(&n,&p1);
    UnlimitedInt p2(k1);
    string k2 = subtraction(&m,&p2);
    if(m.to_string() == n.to_string()){
        UnlimitedInt* x = new UnlimitedInt("0");
        return x;
    }
    
    if(sign1 == 1 and sign2 == 1){
        UnlimitedInt* x = new UnlimitedInt(k2);
        return x;
    }

    if(sign1 == -1 and sign2 == -1){
        if (k2 == "0"){
            UnlimitedInt* x = new UnlimitedInt(k2);
            return x;
        }
        
        string fd = "-" + k2;
        UnlimitedInt* x = new UnlimitedInt(fd);
        return x;
    }

    if(sign1 == 1 and sign2 == -1){
        UnlimitedInt p3(k2);
        UnlimitedInt* gg = UnlimitedInt::sub(&p3,&n);
        string kk = gg->to_string();
        gg->~UnlimitedInt();
        UnlimitedInt* x = new UnlimitedInt(kk);
        return x;

    }
    
    if(sign1 == -1 and sign2 ==1){
        UnlimitedInt p3(k2);
        UnlimitedInt* gg = UnlimitedInt::sub(&n,&p3);
        string kk = gg->to_string();
        gg->~UnlimitedInt();
        UnlimitedInt* x = new UnlimitedInt(kk);
        return x;
    }
                                                                
    return nullptr;
    
}

int* UnlimitedInt::get_array(){
    return unlimited_int;
}
