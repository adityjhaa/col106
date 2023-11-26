#include"stack_c.h"
#include<iostream>
#include<stdexcept>
using namespace std;

Stack_C::Stack_C(){
    stk = new List();
    
}

Stack_C::~Stack_C(){
    delete stk;
    stk = nullptr;
}

void Stack_C::push(int data){
    try{
        stk->insert(data);
    }catch(bad_alloc & ba){
        throw runtime_error("Out of Memory");
    }
}

int Stack_C::pop(){
    if(stk->get_size()==0){
        throw runtime_error("Empty Stack");
    }
    return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx){
    if(idx>stk->get_size()-1){
        throw runtime_error("Index out of range");
    }
    Node* temp = stk->get_head();
    for(int i=0;i<stk->get_size()-idx;i++){
        temp=temp->next;
    }
    return temp->get_value();
};

int Stack_C::get_element_from_bottom(int idx){
    if(idx>stk->get_size()-1){
        throw runtime_error("Index out of range");
    }
    Node* temp = stk->get_head();

    for(int i=0; i<=idx; i++){
        temp=temp->next;
    }
    return temp->get_value();
}

void print_top(List* stk){
    if(stk->get_size()==0){
        return ;
    }
    int k = stk->delete_tail();
    cout << k<< endl;
    print_top(stk);
    stk->insert(k);
}

void print_bottom(List* stk){
    if(stk->get_size()==0){
        return ;
    }
    int k = stk->delete_tail();
    print_bottom(stk);
    cout << k<< endl;
    stk->insert(k);
}

void Stack_C::print_stack(bool top_or_bottom){
    if(top_or_bottom){
        print_top(stk);
    }else{
        print_bottom(stk);
    }
};

int Stack_C::add(){
    if(stk->get_size()==1){
        throw runtime_error("Not Enough Arguements");
    }
    int t1 = Stack_C::pop();
    int t2 = Stack_C::pop();
    Stack_C::push(t1+t2);
    return t1+t2;
};

int Stack_C::subtract(){
    if(stk->get_size()==1){
        throw runtime_error("Not Enough Arguements");
    }
    int t1 = Stack_C::pop();
    int t2 = Stack_C::pop();
    Stack_C::push(t2-t1);
    return t2-t1;
};

int Stack_C::multiply(){
    if(stk->get_size()==1){
        throw runtime_error("Not Enough Arguements");
    }
    int t1 = Stack_C::pop();
    int t2 = Stack_C::pop();
    Stack_C::push(t2*t1);
    return t2*t1;
};

int Stack_C::divide(){
    if(stk->get_size()==1){
        throw runtime_error("Not Enough Arguements");
    }
    if(Stack_C::get_element_from_top(0)==0){
        stk->delete_tail();
        stk->delete_tail();
        throw runtime_error("Divide by zero error");
    }
    int t1 = Stack_C::pop();
    int t2 = Stack_C::pop();
    int t =t2/t1;
    if(t1*t2<0 && t1%t2!=0){
        t--;
    }
    Stack_C::push(t);
    return t;
}; 

List* Stack_C::get_stack(){
    return stk;
};

int Stack_C::get_size(){
    return stk->get_size();
};
