#include"node.h"

Node::Node(bool sentinel){
    is_sentinel=sentinel;
    
    if(sentinel){
        next=prev=nullptr;
    }
    
}

Node::Node(int v, Node* nxt, Node* prv){
    value=v;
    next=nxt;
    prev=prv;
    is_sentinel=false;
}

bool Node::is_sentinel_node(){
    return is_sentinel;
}

int Node::get_value(){
    return value;
}
