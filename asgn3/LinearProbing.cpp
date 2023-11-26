#include "LinearProbing.h"
using namespace std;

void merge2(vector<int> &arr, int s, int e, int m){
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

void sort2(vector<int> &arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        sort2(arr,s,m);
        sort2(arr,m+1,e);
        merge2(arr,s,e,m);
    }
}

LinearProbing::LinearProbing(){
    bankStorage1d.resize(300023);
    size=0;
}

int LinearProbing::get_idx(string id){
    int h = hash(id);
    int k = h;
    while(bankStorage1d[h].id!=""){
        if(bankStorage1d[h].id==id){
            return h;
        }
        h=(h+1)%300023;
        if(h==k){
            return -1;
        }
    }
    return -1;
}

void LinearProbing::createAccount(std::string id, int count) {
    if(!doesExist(id)){
        int k = hash(id);
        while(bankStorage1d[k].id!=""){
            k=(k+1)%300023;
        }
        
        bankStorage1d[k].id=id;
        bankStorage1d[k].balance=count;
        size++;
        return;
    }
    bankStorage1d[get_idx(id)].balance += count;
    return;
}

std::vector<int> LinearProbing::getTopK(int k) {
    vector<int> ans;
    for(int i =0; i< 300023;i++){
        if(bankStorage1d[i].id=="" or bankStorage1d[i].id=="X"){
            continue;
        }
        ans.push_back(bankStorage1d[i].balance);
    }
    sort2(ans,0,size-1);
    if(k>=size){
        return ans;
    }
    ans.resize(k);
    return ans;
}

int LinearProbing::getBalance(std::string id) {
    if(get_idx(id)==-1){
        return -1;
    }
    return bankStorage1d[get_idx(id)].balance;
}

void LinearProbing::addTransaction(std::string id, int count) {
    if(get_idx(id)==-1){
        createAccount(id,count);
        return;
    }
    bankStorage1d[get_idx(id)].balance += count;
    return;
}

bool LinearProbing::doesExist(std::string id){
    if(get_idx(id)==-1){
        return false;
    }
    return true;
}

bool LinearProbing::deleteAccount(std::string id) {
    if(get_idx(id)==-1){
        return false;
    }
    int k = get_idx(id);
    bankStorage1d[k].id="X";
    bankStorage1d[k].balance=0;
    size--;
    return true;
}

int LinearProbing::databaseSize() {
    return size;
}

int LinearProbing::hash(std::string id) {
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%300023;
        pow = (pow*37)%300023;
    }
    return hashkey;
}



