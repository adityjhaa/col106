#include<iostream>
#include<stdexcept>
#include"stack_a.h"
using namespace std;


Stack_A::Stack_A(){
    size =0;   
}

int Stack_A::get_size(){
    return Stack_A::size;
}

int* Stack_A::get_stack(){
    return Stack_A::stk;
}

void Stack_A::push(int data){
    if(size==1024){
        throw runtime_error("Stack Full");
        return;
    }
    stk[size]=data;
    size++;
}

int Stack_A::pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }
    size--;
    return stk[size];
}

int Stack_A::get_element_from_top(int idx){
    if(size-1-idx<0){
        throw runtime_error("Index out of range");
    }
    
    return stk[size-1-idx];
}

int Stack_A::get_element_from_bottom(int idx){
    if(idx+1>size){
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_A::print_stack(bool tb){
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

int Stack_A::add(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_A::pop();
    int t2 = Stack_A::pop();
    Stack_A::push(t1+t2);  
    return t1+t2;
}

int Stack_A::subtract(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_A::pop();
    int t2 = Stack_A::pop();
    Stack_A::push(t2-t1);
    return t2-t1;
}

int Stack_A::multiply(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    int t1 = Stack_A::pop();
    int t2 = Stack_A::pop();
    Stack_A::push(t1*t2);
    return t1*t2;
}

int Stack_A::divide(){
    if(size==1){
        throw runtime_error("Not Enough Arguments");
    }
    if(stk[size-1]==0){
        throw runtime_error("Divide by zero error");
    }
    int t1 = Stack_A::pop();
    int t2 = Stack_A::pop();
    int t =t2/t1;
    if(t1*t2<0 && t2%t1!=0){
        t--;
    }
    Stack_A::push(t);
    return t;
}
