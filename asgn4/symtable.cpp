#include "symtable.h"

SymbolTable::SymbolTable(){
    size = 0;
    root = new SymEntry();
}

SymbolTable::~SymbolTable(){
    root->left->~SymEntry();
    root->right->~SymEntry();
    delete root; 
}

void SymbolTable::insert(string k, UnlimitedRational* v){
    if(size == 0){
        root->key = k;
        root->val = v;
        size++;
    }else{
        SymEntry* head = root;
        SymEntry* newnode = new SymEntry(k,v);
        while (head!= nullptr){
            if(head->key > k){
                if(head->left == nullptr){
                    head->left = newnode;
                    size++;
                    break;
                }else{
                    head = head->left;
                }
            }else{
                if(head->right == nullptr){
                    head->right = newnode;
                    size++;
                    break;
                }else{
                    head = head->right;
                }
            }
        }    
    }
}

void SymbolTable::remove(string k){
    SymEntry* head = root;
    SymEntry* parent = nullptr;
    while (head!= nullptr){
        if(head->key < k){
            parent = head;
            head = head->right;
        }else if(head->key > k){
            parent = head;
            head = head->left;
        }else if(head->key == k){
            break;
        }
    }
    if(head == nullptr){
        return;
    }
    if(head->left == nullptr and head->right == nullptr){
        head->~SymEntry();
        head = nullptr;
        size --;
    }
    if(head->left == nullptr and head->right != nullptr){
        SymEntry* temp = head;
        parent->right = head->right;
        temp->right = nullptr;
        temp->~SymEntry();
        size--;
        return;
    }

    if(head->left != nullptr and head->right == nullptr){
        SymEntry* temp = head;
        parent->left = head->left;
        temp->left = nullptr;
        temp->~SymEntry();
        size--;
        return;
    }

    if(head->left != nullptr and head->right != nullptr){

        SymEntry* self = head;
        SymEntry* self_r = head->right;

        while(self_r->left != nullptr){
            self = self_r;
            self_r = self_r->left;
        }
        if(self != head){
            self->left = self_r->right;
        }else{self->right = self_r->right;}
        head->key = self_r->key;
        head->val = self_r->val;
        delete self_r;
    }
}
 
UnlimitedRational* SymbolTable::search(string k){
    SymEntry* head = root;
    while (head!= nullptr){
        if(head->key < k){
            head = head->right;
        }else if(head->key > k){
            head = head->left;
        }else if(head->key == k){
            return head->val;
            break;
        }
    }
    return nullptr;
}

int SymbolTable::get_size(){return size;}

SymEntry* SymbolTable::get_root(){return root;}
