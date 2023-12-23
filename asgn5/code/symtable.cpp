/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

int maintainheights(SymNode* root){
    if(root == NULL){
        return -1;
    }else{
        int h = 1 + max(maintainheights(root->left),maintainheights(root->right));
        root->height = h;
        return h;
    }
}

int balancefactor(SymNode* root){
    if(root == NULL){
        return -1;
    }else{
        return ((root->right == NULL)?0:root->right->height) - ((root->left == NULL)?0:root->left->height);      
    }
}

SymbolTable::SymbolTable(){
    
}

void SymbolTable::insert(string k){
    SymNode* newnode = new SymNode(k);
    if(size == 0){
        root = newnode;
        size++;
    }else{
        SymNode* head = root;
        while(head != NULL){
            if(head->key > k){
                if(head->left == NULL){
                    head->left = newnode;
                    newnode->par = head;
                    size++;
                    break;
                }else{
                    head = head->left;
                }
            }else{
                if(head->right == NULL){
                    head->right = newnode;
                    newnode->par = head;
                    size++;
                    break;
                }else{
                    head = head->right;
                }
            }
        }
        maintainheights(root);
        SymNode* traversal = newnode;
        while(true){
            int e = balancefactor(traversal);
            if(e == 2 or e == -2){
                break;
            }else{
                if(traversal->par != NULL){
                    traversal = traversal->par;
                }else{
                    traversal = traversal->par;
                    break;
                }
            }
        }
        
        if(traversal == NULL){
            return;
        }

        SymNode* y;
        if(traversal->key > k){
            y = traversal->left;
        }else{y = traversal->right;}

        SymNode* x;
        if(y->key > k){
            x = y->left;
        }else{x = y->right;}

        if(traversal->left == y and y->left == x){
            root = traversal->RightRightRotation();
        }else if(traversal->left == y and y->right == x){
            root = traversal->LeftRightRotation();
        }else if(traversal->right == y and y->right == x){
            root = traversal->LeftLeftRotation();
        }else{root = traversal->RightLeftRotation();}
        maintainheights(root);
    }
}

void SymbolTable::remove(string k){
    SymNode* head = root;
    while(head!= nullptr){
        if(head->key < k){
            head = head->right;
        }else if(head->key > k){
            head = head->left;           
        }else if(head->key == k){
            break;
        }
    }

    SymNode* parent = head->par;
    
    if(head == NULL){
        return;
    }

    if(head->left == NULL and head->right == NULL){
        if(parent->left == head){
            parent->left = NULL;
        }else{parent->right = NULL;}
        size--;
    }else if(head->left == NULL and head->right != NULL){
        SymNode* temp = head;
        parent->right = head->right;
        temp->right = NULL;
        parent->right->par = parent;
        temp->par = NULL;
        free(temp);
        size--;
    }else if(head->left != nullptr and head->right == nullptr){
        SymNode* temp = head;
        parent->left = head->left;
        temp->left = NULL;
        parent->left->par = parent;
        temp->par = NULL;
        free(temp);
        size--;
    }else if(head->left != nullptr and head->right != nullptr){
        SymNode* succ = head->right;
        while(succ->left != nullptr){
            succ = succ->left;
        }
        head->key = succ->key;
        head->address = succ->address;
        
        if(succ->right == NULL){
            free(succ);
            size--;
        }else{        
        parent = succ->par;
        parent->right = succ->right;
        succ->right = NULL;
        parent->right->par = parent;
        succ->par = NULL;
        size--;
        }
    }
    maintainheights(root);

    SymNode* traversal = parent;
    while(true){
        while(true){
            int e = balancefactor(traversal);
            if(e == 2 or e == -2){
                break;
            }else{
                if(traversal->par != NULL){
                    traversal = traversal->par;
                }else{
                    traversal = traversal->par;
                    break;
                }
            }
        }
        if(traversal == NULL){
            break;
        }
        
        SymNode* y;
        int h1 = (traversal->left == NULL)?0:traversal->left->height;
        int h2 = (traversal->right == NULL)?0:traversal->right->height;

        y = (h1>h2)?traversal->left:traversal->right;

        SymNode* x;
        int h11 = (y->left == NULL)?0:y->left->height;
        int h21 = (y->right == NULL)?0:y->right->height;

        y = (h11>h21)?y->left:y->right;

        if(traversal->left == y and y->left == x){
            root = traversal->RightRightRotation();
        }else if(traversal->left == y and y->right == x){
            root = traversal->LeftRightRotation();
        }else if(traversal->right == y and y->right == x){
            root = traversal->LeftLeftRotation();
        }else{
            root = traversal->RightLeftRotation();
        }
        
        maintainheights(root);
    }
}

int SymbolTable::search(string k){
    SymNode* head = root;
    while(head != NULL){
        if(head->key == k){
            break;
        }else if(head->key < k){
            head = head->right;
        }else{head = head->left;}

        if(head == NULL){
            break;
        }
    }

    if(head == NULL){
        return -2;
    }else{return head->address;}
    return 0;
}

void SymbolTable::assign_address(string k,int idx){
    SymNode* head = root;
    while(true){
        if(head->key == k){
            break;
        }else if(head->key < k){
            head = head->right;
        }else{head = head->left;}

        if(head == NULL){
            break;
        }
    }

    if(head == NULL){
        return;
    }else{
        head->address = idx;
        return;
    }
    
}

int SymbolTable::get_size(){
    return size;
}

SymNode* SymbolTable::get_root(){
    return root;
}

void destroy(SymNode* root){
    if(root != NULL){
        destroy(root->left);
        destroy(root->right);
        delete(root);
        root = NULL;
    }
}

SymbolTable::~SymbolTable(){
    destroy(root);
}
