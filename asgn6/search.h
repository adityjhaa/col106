// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine
{
private:
    // You can add attributes/helper functions here
    class sent
    {
    public:
        string s;
        int length;
        int book_code, page, paragraph, sentence_no;
        sent() {}
        sent(string s, int book_code, int page, int paragraph, int sentence_no)
        {
            this->book_code = book_code;
            this->s = s;
            this->page = page;
            this->paragraph = paragraph;
            this->sentence_no = sentence_no;
            length = s.size();
        }
    };

    sent *sd;
    int curr_size;
    int tot_size;

public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node *search(string pattern, int &n_matches);

    /* -----------------------------------------*/
};