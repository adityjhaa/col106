/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

int maintainheight(SymNode* root){
    if(root == NULL){
        return -1;
    }else{
        int h = 1 + max(maintainheight(root->left),maintainheight(root->right));
        root->height = h;
        return h;
    }
}

SymNode::SymNode(){
    key = "";
    height = -1;
    address = -1;
    par = NULL;
    left = NULL;
    right = NULL;

}

SymNode::SymNode(string k){
    key = k;
    height = 0;
    address = -1;
    par = NULL;
    left = NULL;
    right = NULL;
}

SymNode* SymNode::LeftLeftRotation(){
    SymNode* y = right;
    if(y->left != NULL){
        right = y->left;
        y->left->par = this;
        y->left = NULL;
        y->par = NULL;
    }else{
        right = NULL;
        y->par = NULL;
    }
    if(par == NULL){
        par = y;
        y->left = this;
        
    }else if(par->left == this){
        par->left = y;
        y->par = par;
        par = NULL;
    }else{
        par->right = y;
        y->par = par;
        par = NULL;
    }
    par = y;
    y->left = this;

    SymNode* r = par;
    while(r->par != NULL){
        r = r->par;
    }
    maintainheight(r);
    return r;

}

SymNode* SymNode::RightRightRotation(){
    SymNode* x = left;

    if(x->right != NULL){
        left = x->right;
        x->right->par = this;
        x->right = NULL;
        x->par = NULL;
    }else{
        left = NULL;
        x->par = NULL;
    }

    if(par == NULL){
        par = x;
        x->right = this;
    }else if(par->right == this){
        par->right = x;
        x->par = par;
        par = NULL;
    }else{
        par->left = x;
        x->par = par;
        par = NULL;
    }

    par = x;
    x->right = this;

    SymNode* r = par;
    while(r->par != NULL){
        r = r->par;
    }
    maintainheight(r);
    return r;  
}

SymNode* SymNode::LeftRightRotation(){
    left->LeftLeftRotation();
    RightRightRotation();
    SymNode* r = par;
    while(r->par != NULL){
        r = r->par;
    }
    return r;
}

SymNode* SymNode::RightLeftRotation(){
    right->RightRightRotation();
    LeftLeftRotation();
    SymNode* r = par;
    while(r->par != NULL){
        r = r->par;
    }
    return r;
}


SymNode::~SymNode(){
}
