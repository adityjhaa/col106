#include "eppcompiler.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr<<"Usage: ./e++ <input_file>"<<endl;
    return 1;
  }
  ifstream inp_file(argv[1]);
  if (!inp_file) {
    cerr << "Error opening the file: " << argv[1] << endl;
    return 1;
  }

  auto parseline = [](const string& inp){  
    vector<string> expr;
    istringstream iss(inp);
    string word;
    while (iss >> word) expr.push_back(word);
    return expr;
  };

  int cnt=0;
  string line;
  vector<vector<string>> code;

  auto is_valid = [&](const vector<string>& expr){
    int pre=0;bool flag=true;
    flag &= expr[1] ==":=";
    for(int i=0;i<expr.size();i++) (expr[i]=="("?pre++:expr[i]==")"?pre--:pre=pre),flag &= pre>=0; flag &= pre==0;
    if(!flag) cerr<<"Error: Invalid E++ expression at line "<<cnt<<endl; return flag;
  };

  while(getline(inp_file,line)){
    cnt++;
    if(line.empty() || all_of(line.begin(), line.end(), [](char c) {return isspace(c);})) continue;
    vector<string> expr = parseline(line);
    if(!is_valid(expr)) return 1;
    code.push_back(expr);
  }
  inp_file.close();
  if(code.size()==0) return 0;

  int var_count = 0;int max_var=0;
  for(const vector<string>& expr:code){
    if(expr[0]=="del") var_count --;
    else if(expr[0]=="ret") continue;
    else var_count++;
    max_var = max(max_var,var_count);
  }
  if(code.back()[0] != "ret"){
    cerr<<"Error: Last E++ expression should be of return type"<<cnt<<endl;
    return 1;
  }

  try{
    EPPCompiler eppc("targ.txt",max_var);
    eppc.compile(code);
  }
  catch(const exception& e){ 
    cerr<<"Error: The compiler threw the below error while compiling the code:"<<endl;
    cerr<<e.what()<<endl; 
    return 1;
  }
  
  cout<<"Targ code for file "<<argv[1]<<" generated successfully"<<endl;
  return 0;
}