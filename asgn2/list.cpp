#include"list.h"
#include<stdexcept>


List::List(){
    size=0;
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->prev=nullptr;
    sentinel_head->next=sentinel_tail;
    sentinel_tail->next=nullptr;
    sentinel_tail->prev=sentinel_head;
};

void List::insert(int v){
    try{
        Node*t = sentinel_tail->prev;
        Node* temp= new Node(v,sentinel_tail,t);
        t->next=temp;
        sentinel_tail->prev=temp;   
        size++; 
    }catch(std::bad_alloc & ba){
        throw std::runtime_error("Out of Memory");
    }
     
};

int List::delete_tail(){
    
    Node*temp = sentinel_tail->prev;
    sentinel_tail->prev = sentinel_tail->prev->prev;
    sentinel_tail->prev->next=sentinel_tail;
    temp->next=temp->prev=nullptr;
    int k = temp->get_value();
    delete temp;
    size--;
    return k;
}

int List::get_size(){
    return size;
}; 

Node* List::get_head(){
    return sentinel_head;
};

List::~List(){
    for(int i =0; i<size; i++){
        delete_tail();
    }
    delete sentinel_head;
    delete sentinel_tail;
};

