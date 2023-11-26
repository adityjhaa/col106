// Do NOT add any other includes
#include "search.h"

vector<int> computeLPSArray(string pat, int M, vector<int> lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M){
        if (pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMPSearch(string pat, string txt){
    vector<int> offset;
    int m = pat.size();
    int n = txt.size();
    vector<int> lps(m);
    lps = computeLPSArray(pat, m, lps);
    int i = 0,j=0;

    while((n-i)>=(m-j)){
        if (pat[j]==txt[i]){
            j++;
            i++;
        }

        if (j==m){
            offset.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i<n and pat[j]!=txt[i]){
            if (j != 0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return offset;
}

char to_lower(char c){
    return c - 'A' + 'a';
}

SearchEngine::SearchEngine(){
    sd = new sent[4];
    tot_size = 2;
    curr_size = 0;
}

SearchEngine::~SearchEngine(){
    delete[] sd;
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    for (int i = 0; i < sentence.size(); i++){
        if (sentence[i] >= 'A' and sentence[i] <= 'Z'){
            sentence[i] = to_lower(sentence[i]);
        }
    }

    if (curr_size >= tot_size - 1){
        tot_size *= 2;
        sent *temp = new sent[tot_size];

        for (int i = 0; i < curr_size; i++){
            sent t_sent = sd[i];
            temp[i] = t_sent;
        }

        delete[] sd;

        sd = temp;
    }

    sent curr(sentence, book_code, page, paragraph, sentence_no);
    sd[curr_size] = curr;
    curr_size++;
    return;
}

Node *SearchEngine::search(string pattern, int &n_matches){
    // Implement your function here
    Node *head = NULL;

    for (int i = 0; i < pattern.size(); i++){
        if (pattern[i] >= 'A' and pattern[i] <= 'Z'){
            pattern[i] = to_lower(pattern[i]);
        }
    }
    int a = pattern.size();

    for (int i = 0; i < curr_size; i++){
        int b = sd[i].length;
        string curr_sen = sd[i].s;
        if (a > b){
            continue;
        }
        else{
            vector<int> offsets = KMPSearch(pattern, curr_sen);
            if (offsets.size() == 0){
                // pattern does not match
                continue;
            }
            else{
                // pattern matches
                for (int j = 0; j < offsets.size(); j++){
                    Node *curr = new Node(sd[i].book_code, sd[i].page, sd[i].paragraph, sd[i].sentence_no, offsets[j]);
                    if (head == NULL){
                        head = curr;
                    }
                    else{
                        curr->right = head;
                        head->left = curr;
                        head = curr;
                    }
                    n_matches++;
                }
            }
        }
    }
    return head;
}
