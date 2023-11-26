#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "Node.h"

using namespace std;

class QNA_tool {

private:

    // You are free to change the implementation of this function
    void query_llm(string filename, Node* root, int k, string API_KEY, string question);
    // filename is the python file which will call ChatGPT API
    // root is the head of the linked list of paragraphs
    // k is the number of paragraphs (or the number of nodes in linked list)
    // API_KEY is the API key for ChatGPT
    // question is the question asked by the user

    // You can add attributes/helper functions here

public:

    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    
    QNA_tool(); // Constructor
    ~QNA_tool(); // Destructor

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    // This function is similar to the functions in dict and search 
    // The corpus will be provided to you via this function
    // It will be called for each sentence in the corpus

    Node* get_top_k_para(string question, int k);
    // This function takes in a question, preprocess it
    // And returns a list of paragraphs which contain the question
    // In each Node, you must set: book_code, page, paragraph (other parameters won't be checked)

    std::string get_paragraph(int book_code, int page, int paragraph);
    // Given the book_code, page number, and the paragraph number, returns the string paragraph.
    // Searches through the corpus.

    void query(string question, string filename);
    // This function takes in a question and a filename.
    // It should write the final answer to the specified filename.

    /* -----------------------------------------*/
    /* Please do not touch the code above this line */

    // You can add attributes/helper functions here


// SymNode
class SymNode {
public:
    string key;
    int height;
    unsigned long long count = 0;
    double score = 0;
    
    SymNode* par = NULL;
    SymNode* left = NULL;
    SymNode* right = NULL;

    SymNode();
    // SymNode(SymNode&& source);
    // SymNode(SymNode& source);
    
    SymNode(const SymNode& other);
    SymNode(string k);

    SymNode* LeftLeftRotation(); // case 1
    SymNode* RightRightRotation(); // case 2
    SymNode* LeftRightRotation(); // case 3
    SymNode* RightLeftRotation(); // case 4

    ~SymNode();
    
};


// SymbolTable
class SymbolTable {
private:
    int size = 0;
    SymNode* root = NULL;

public: 

    SymbolTable();
    //SymbolTable(SymbolTable&& source);
    //SymbolTable(const SymbolTable& source);
    SymbolTable(const SymbolTable &source);
    SymNode* copyNodes(SymNode* node);
    ~SymbolTable();

    // Insert a key in the symbol table, there is no value now
    void insert(string k);

    // Remove a key (and it's memory address) in the symbol table
    void remove(string k);
 
    // Find the memory address corresponding to the variable in the symbol table
    unsigned long long search(string k);

    // Assigns a memory address to the key in the symbol table
    void assign_address(string k,int idx);

    // Get size
    int get_size();

    // Get root 
    SymNode* get_root();
};


vector<vector<vector<SymbolTable>>> mainobj;

struct scored_para
{
    int book_no;
    int page_no;
    int para_no;
    double score;
};

vector<scored_para> score_paragraphs(string sentence);

vector<pair<string, double>> scoring(string sentence);

void heapify(vector<scored_para>& arr, int n, int i);

void heapSort(vector<scored_para>& arr, int k);


 

};