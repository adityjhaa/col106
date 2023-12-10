#include "exprtreenode.h"

ExprTreeNode::ExprTreeNode(){
    type = "";
    id = "";
    val = nullptr;
    evaluated_value = nullptr;
    left = nullptr;
    right = nullptr;
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
    if(t != "(" or t != ")" ){
        
        if(t == ":="){
            id = "";
            type = "MOD";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;

        }else if(t == "+"){
            id = "";
            type = "ADD";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;
        }else if(t == "-"){
            id = "";
            type = "SUB";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;
        }else if(t == "/"){
            id = "";
            type = "DIV";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;
        }else if(t == "*"){
            id = "";
            type = "MUL";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;
        }else if(isdigit(t[0]) ==1){
            id = "";
            type = "VAL";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedInt* b = new UnlimitedInt(t);
            UnlimitedRational* c = new UnlimitedRational(b,a);
            val = c;
            left = nullptr;
            right = nullptr;
            evaluated_value = c;
        }else if((t[0] == '-' and isdigit(t[1]) == 1)){
            id = "";
            type = "VAL";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedInt* b = new UnlimitedInt(t);
            UnlimitedRational* c = new UnlimitedRational(b,a);
            val = c;
            left = nullptr;
            right = nullptr;
            evaluated_value = c;
        }else{
            id = t;
            type = "VAR";
            UnlimitedInt* a = new UnlimitedInt("1");
            UnlimitedRational b = UnlimitedRational(a,a);
            val = &b;
            left = nullptr;
            right = nullptr;
            evaluated_value = &b;
        }
    }    
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){}

ExprTreeNode::~ExprTreeNode(){
    delete val;
    delete evaluated_value;
    delete left;
    delete right;
}
