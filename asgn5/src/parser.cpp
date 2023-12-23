/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "../include/parser.h"

Parser::Parser(){
    expr_trees = vector<ExprTreeNode*>();
    symtable = new SymbolTable;
    last_deleted = -4;
}

int indexofsign(vector<string> code,int initial, int final){
    int i = initial;
    int noofopen = 0;
    while(code[i] == "("){
        i++;
        noofopen++;
    }
    int index = i;
    if(noofopen != 0){
        for(int j = i; j < final-1; j++){
            if(noofopen == 1){
                break;
            }else if(code[j] == ")"){
                noofopen--;
            }
            index++;
        }
    }

    for(int j = index; j < final; j++){
        if(code[j] == "+" or code[j] ==  "-" or code[j] ==  "*" or code [j] == "/"){
            return j;
        }
    }
    return -1;
}

ExprTreeNode* build_tree(vector<string> code, int initial, int final){
    int k = indexofsign(code, initial , final);
    if(k == -1){
        ExprTreeNode* root = new ExprTreeNode(code[initial],-4);
        return root;
    }
    ExprTreeNode* root = new ExprTreeNode(code[k],-4);
    root->left = build_tree(code, initial+1,k-1);
    root->right = build_tree(code,k+1,final-1);
    return root;
}

void Parser::parse(vector<string> expression){
    ExprTreeNode* root = new ExprTreeNode(":=",-4);
    ExprTreeNode* left1 = new ExprTreeNode(expression[0],-4);
    root->left = left1;
    if(left1->type == "DEL"){
        ExprTreeNode* right1 = new ExprTreeNode(expression[2],-4);
        root->right = right1;
        expr_trees.push_back(root);
    }

    if(left1->type == "RET"){
        root->right = build_tree(expression,2,expression.size()-1);
        expr_trees.push_back(root);        
    }

    if(left1->type == "VAR"){
        root->right = build_tree(expression,2,expression.size()-1);
        expr_trees.push_back(root);
        
        if(symtable->search(expression[0]) == -2){
            symtable->insert(expression[0]);
        }
    }   
}

Parser::~Parser(){
}