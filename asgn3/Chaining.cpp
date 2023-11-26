#include "Chaining.h"
using namespace std;

void merge(vector<int> &arr, int s, int e, int m){
    vector<int> merged;
    int a,b;
    a=s;
    b=m+1;
    while(a<=m and b<=e){
        if(arr[a]>=arr[b]){
            merged.push_back(arr[a]);
            a++;
        }else{
            merged.push_back(arr[b]);
            b++;
        }
    }
    while(a<=m){
        merged.push_back(arr[a]);
        a++;
    }
    while(b<=e){
        merged.push_back(arr[b]);
        b++;
    }
    for(int i =s; i<=e ;i++){
        arr[i]=merged[i-s];
    }
}

void sort(vector<int> &arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        sort(arr,s,m);
        sort(arr,m+1,e);
        merge(arr,s,e,m);
    }
}

Chaining::Chaining(){
    bankStorage2d.resize(300023);
    size=0;
}

void Chaining::createAccount(std::string id, int count) {
    if(!doesExist(id)){
        int t = hash(id);
        Account a;
        a.balance=count;
        a.id=id;
        bankStorage2d[t].push_back(a);
        size++;
    }
}

std::vector<int> Chaining::getTopK(int k) {
    vector<int> ans;
    for(int i =0; i<bankStorage2d.size();i++){
        for(int j = 0; j<bankStorage2d[i].size();j++){
            ans.push_back(bankStorage2d[i][j].balance);
        }
    }
    sort(ans,0,size-1);
    if(k>=size){
        return ans;
    }
    ans.resize(k);
    return ans;
}

int Chaining::getBalance(std::string id) {
    if(doesExist(id)){
        int t = hash(id);
        for(int i =0; i<bankStorage2d[t].size();i++){
            if(bankStorage2d[t][i].id==id){
                return bankStorage2d[t][i].balance;
            }
        }
    }
    return -1;
}

void Chaining::addTransaction(std::string id, int count) {
    if(doesExist(id)){
        int t = hash(id);
        for(int i =0; i<bankStorage2d[t].size();i++){
            if(bankStorage2d[t][i].id==id){
                bankStorage2d[t][i].balance+=count;
                return;
            }
        }
    }else{
        createAccount(id,count);
    }
}

bool Chaining::doesExist(std::string id) {
    int t = hash(id);
    for(int i =0; i< bankStorage2d[t].size();i++){
        if(bankStorage2d[t][i].id==id){
            return true;
        }
    }
    return false;
}

bool Chaining::deleteAccount(std::string id){
    if(doesExist(id)){
        int t = hash(id);
        for(int i =0; i< bankStorage2d[t].size();i++){
            if(bankStorage2d[t][i].id==id){
                bankStorage2d[t].erase(bankStorage2d[t].begin()+i);
                size--;
                return true;
            }
        }
    }
    return false;
}

int Chaining::databaseSize() {
    return size;
}

int Chaining::hash(std::string id) {
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%300023;
        pow = (pow*37)%300023;
    }
    return hashkey;
}
