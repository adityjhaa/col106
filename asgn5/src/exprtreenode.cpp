/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "../include/exprtreenode.h"


ExprTreeNode::ExprTreeNode(){
}

ExprTreeNode::ExprTreeNode(string t,int v){
    if(t == ":="){
        id = ":=";
        type = "DIV";
        num = -5;
    }else if(t == "+"){
        id = "";
        type = "ADD";
        num = -5;
    }else if(t == "-"){
        if(t.length() > 1){
            id = "";
            type = "VAL";
            num = stoi(t);
        }else{
            id = "";
            type = "SUB";
            num = -5;
        }
    }else if(t == "/"){
        id = "";
        type = "DIV";
        num = -5;
    }else if(t == "*"){
        id = "";
        type = "MUL";
        num = -5;
    }else if(t == "ret"){
        id = "";
        type = "RET";
        num = -5;
    }else if(t == "del"){
        id = "";
        type = "DEL";
        num = -5;
    }else if(isdigit(t[0]) == 1){
        id = "";
        type = "VAL";
        num = stoi(t);
    }else{
        id = t;
        type = "VAR";
        num = -5;
    }
   
}


ExprTreeNode::~ExprTreeNode(){  
}
