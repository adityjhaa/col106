#pragma once
#include "parser.h"
#include "minheap.h"
#include <vector>
#include <fstream>
using namespace std;

class EPPCompiler{
  private:
  Parser targ;
  int memory_size;
  string output_file;
  vector<int> mem_loc;
  MinHeap least_mem_loc;

  public:

  EPPCompiler();
  EPPCompiler(string out_file,int mem_limit);

  void compile(vector<vector<string>> code);
  vector<string> generate_targ_commands();
  void write_to_file(vector<string> commands);
  
  ~EPPCompiler();
};