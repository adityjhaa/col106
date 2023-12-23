/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "../include/eppcompiler.h"

EPPCompiler::EPPCompiler(){
}

EPPCompiler::EPPCompiler(string out_file,int mem_limit){
    memory_size = mem_limit;
    output_file = out_file;
    mem_loc.assign(mem_limit,-9);
}

vector<string> a;

string ger(ExprTreeNode* head, Parser parse){
    if(head->type == "ADD"){
        return "ADD";
    }else if(head->type == "DIV"){
        return "DIV";
    }else if(head->type == "MUL"){
        return "MUL";
    }else if(head->type == "SUB"){
        return "SUB";
    }else if(head->type == "VAL"){
        return "PUSH " + to_string(head->num);
    }else if(head->type == "VAR"){
        int memindex = parse.symtable->search(head->id);
        return "PUSH mem[" + to_string(memindex)+"]";
    }
    return "";
    
}

void const postord(ExprTreeNode* root, const Parser parse){
    if(root == NULL){
        return;
    }else{
        postord(root->right,parse);
        postord(root->left,parse);
        a.push_back(ger(root,parse));
    }
}

void EPPCompiler::compile(vector<vector<string>> code){
    ofstream outf(output_file);
    outf.clear();
    for(int i = 0; i < code.size(); i++){
        vector<string> aux;
        aux.push_back(code[i][0]);
        aux.push_back(code[i][1]);
        for(int j = 2; j < code[i].size(); j++){
            if(code[i][j].length() > 1 and isdigit(code[i][j][0]) != 1){
                for(int k = 0; k < code[i][j].length(); k++){
                    aux.push_back(code[i][j].substr(k,1));
                }
                
            }else{aux.push_back(code[i][j]);}
        }

        targ.parse(aux);
        ExprTreeNode* root = targ.expr_trees[targ.expr_trees.size()-1];
        if(root->left->type == "VAR"){
            int ind = 0;
            for(int i = 0; i < mem_loc.size(); i++){
                if(mem_loc[i] == -9){
                    ind = i;
                    break;
                }  
            }
            if(targ.symtable->search(root->left->id) == -1){
                targ.symtable->assign_address(root->left->id,ind);
                mem_loc[i] = 9;
            }
        }else if(root->left->type == "DEL"){
            int fff = targ.symtable->search(root->left->id);
            if( fff != -2){
                targ.symtable->remove(root->right->id);
                mem_loc[fff] = -9;
            }
            
        }
        vector<string> w = generate_targ_commands();
        write_to_file(w);
    }
}


vector<string> EPPCompiler::generate_targ_commands(){
    ExprTreeNode* s =  targ.expr_trees[targ.expr_trees.size()-1];
    vector<string> out;
    Parser pars(targ);
    postord(s->right,pars);
    for(int i = 0; i < a.size(); i++){
        out.push_back(a[i]);
    }
    if(s->left->type == "VAR"){
        int memind = targ.symtable->search(s->left->id);

        string k = "mem["+to_string(memind)+"] = POP";
        out.push_back(k);
    }else if(s->left->type == "DEL"){
        out.clear();
        int memind = targ.symtable->search(s->right->id);
        string k = "DEL = mem["+to_string(memind)+"]";
        out.push_back(k);
    }else if(s->left->type == "RET"){
        int memind = targ.symtable->search(s->left->id);
        string k = "RET = POP";
        out.push_back(k);
    }
    a.clear();
    return out;
}

void EPPCompiler::write_to_file(vector<string> commands){
    ofstream outfile(output_file, fstream::app);
    for(int i = 0; i < commands.size(); i++){
        outfile << commands[i] + "\n";
    }
    outfile << "\n";
    
}

void destruction(ExprTreeNode* root){
    if(root == NULL){
        return;
    }else{
        destruction(root->left);
        destruction(root->right);
        delete(root);
        root = NULL;
    }
}


EPPCompiler::~EPPCompiler(){
    delete (targ.symtable);

    targ.symtable = NULL;
    for(int i = 0; i < targ.expr_trees.size(); i++){
        destruction(targ.expr_trees[i]);
    }
}
