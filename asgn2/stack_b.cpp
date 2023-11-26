#include"stack_b.h"
#include<iostream>
#include<stdexcept>
using namespace std;


Stack_B::Stack_B(){
    size=0;
    capacity=1023;
    stk = new int[1024];
}

Stack_B::~Stack_B(){
    delete []stk;
    stk = nullptr;
}

int Stack_B::get_size(){
    return size;
}

int* Stack_B::get_stack(){
    return stk;
}

void Stack_B::push(int data){
    if(size==capacity){
        capacity*=2;
        try{
            int* temp = new int[capacity];
            for(int i=0; i<size; i++){
            temp[i]=stk[i];
        }
        stk=temp;
        }catch(bad_alloc & ba){
            throw runtime_error("Out of Memory");
        }
        
        
    }
    stk[size]=data;
    size++;
}

int Stack_B::pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }
    int k = stk[size-1];
    if(size<=capacity/4){
        capacity/=2;
        int*temp = new int[capacity];
        for(int i=0; i< size; i++){
            temp[i]=stk[i];
        }

        stk=temp;
        
    }
    size--;
    return k;
}

int Stack_B::get_element_from_top(int idx){
    if(size-1-idx<0){
        throw runtime_error("Index out of range");
    }
    
    return stk[size-1-idx];
}

int Stack_B::get_element_from_bottom(int idx){
    if(idx+1>size){
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_B::print_stack(bool tb){
    if(tb){
        for(int i=size;i>0;i--){
            cout << stk[size-1]<<endl;
        }
    }
    else{
        for(int i=0;i<size;i++){
            cout << stk[i]<<endl;
        }
    }
}

int Stack_B::add(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_B::pop();
    int t2 = Stack_B::pop();
    Stack_B::push(t1+t2);  
    return t1+t2;
}

int Stack_B::subtract(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_B::pop();
    int t2 = Stack_B::pop();
    Stack_B::push(t2-t1);  
    return t2-t1;
}

int Stack_B::multiply(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_B::pop();
    int t2 = Stack_B::pop();
    Stack_B::push(t1*t2);  
    return t1*t2;
}

int Stack_B::divide(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    if(stk[size-1]==0){
        throw runtime_error("Divide by zero error");
    }
    int t1 = Stack_B::pop();
    int t2 = Stack_B::pop();
    int t =t2/t1;
    if(t1*t2<0 && t1%t2!=0){
        t--;
    }
    Stack_B::push(t);
    return t;
}

