/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "../include/minheap.h"

MinHeap::MinHeap(){

}

HeapNode* lastelement(HeapNode* root){
    HeapNode* lastel = root;
    if(root->par = NULL){
        while(lastel->left){
            
        }
    }
    return lastel;
}

void MinHeap::push_heap(int num){
    if(size == 0){
        HeapNode* newnode = new HeapNode(num);
        root = newnode;
        size++;
    }else{
        HeapNode* head = root;
        HeapNode* newnode = new HeapNode(num);
        while(true){
            if(head->left == NULL and head->right == NULL){
                head->left = newnode;
                size++;
                break;
            }else if(head->left != NULL and head->right == NULL){
                head->right = newnode;
                size++;
                break;
            }
        }    
    }
}

int MinHeap::get_min(){
    return root->val;
}

void MinHeap::pop(){
}

MinHeap::~MinHeap(){
}