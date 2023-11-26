#include "Comp.h"
using namespace std;

#define ull unsigned long long

void merge5(vector<int> &arr, int s, int e, int m){
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

void sort5(vector<int> &arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        sort5(arr,s,m);
        sort5(arr,m+1,e);
        merge5(arr,s,e,m);
    }
}

int Comp::get_idx2(string id){
    int h1 = hash(id);
    int h2 = hash2(id);
    int h = 0;
    int k = h;
    int i = 1;
    while(bankStorage1d[h].id!=""){
        if(bankStorage1d[h].id==id){
            return h;
        }
        h = (h + h1 + (i*h2))%300023;
        i++;
        if(h == k){
            return -1;
        }
    }
    return -1;
}


Comp::Comp(){
    bankStorage1d.resize(300023);
    size = 0;
}

void Comp::createAccount(std::string id, int count) {
    if(!doesExist(id)){
        int k1 = hash(id);
        int k2 = hash2(id);
        int i = 1;
        int k = 0;
        while(bankStorage1d[k].id!=""){
            k=(k + k1+ (i*k2))%300023;
            i++;
        }
        
        bankStorage1d[k].id=id;
        bankStorage1d[k].balance=count;
        size++;
        return;
    }
    bankStorage1d[get_idx2(id)].balance += count;
    return;
}

std::vector<int> Comp::getTopK(int k) {
    vector<int> ans;
    for(int i =0; i< 300023;i++){
        if(bankStorage1d[i].id=="" or bankStorage1d[i].id=="X"){
            continue;
        }
        ans.push_back(bankStorage1d[i].balance);
    }
    sort5(ans,0,size-1);
    if(k>=size){
        return ans;
    }
    ans.resize(k);
    return ans;

}

int Comp::getBalance(std::string id) {
    if(get_idx2(id)==-1){
        return -1;
    }
    return bankStorage1d[get_idx2(id)].balance;
}

void Comp::addTransaction(std::string id, int count) {
    if(get_idx2(id)==-1){
        createAccount(id,count);
        return;
    }
    bankStorage1d[get_idx2(id)].balance += count;
    return;
}

bool Comp::doesExist(std::string id) {
    if(get_idx2(id)==-1){
        return false;
    }
    return true;
}

bool Comp::deleteAccount(std::string id) {
    if(get_idx2(id)==-1){
        return false;
    }
    int k = get_idx2(id);
    bankStorage1d[k].id="X";
    bankStorage1d[k].balance=0;
    size--;
    return true;
}

int Comp::databaseSize() {
    return size;
}

int Comp::hash(std::string id) {
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%300023;
        pow = (pow*37)%300023;
    }
    return hashkey;
}

int Comp::hash2(string id){
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%300023;
        pow = (pow*41)%300023;
    }
    return hashkey;
}