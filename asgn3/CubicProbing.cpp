#include "CubicProbing.h"
using namespace std;

#define ull unsigned long long

void merge4(vector<int> &arr, int s, int e, int m){
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

void sort4(vector<int> &arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        sort4(arr,s,m);
        sort4(arr,m+1,e);
        merge4(arr,s,e,m);
    }
}

CubicProbing::CubicProbing(){
    bankStorage1d.resize(300023);
    size=0;
}

void CubicProbing::createAccount(std::string id, int count) {
    int k = hash(id);
    ull h =k;
    int i =1;
    while(bankStorage1d[h].id!=""){
        h=(k+(i*i*i))%300023;
        i++;
    }
    bankStorage1d[h].id=id;
    bankStorage1d[h].balance=count;
    size++;
}

std::vector<int> CubicProbing::getTopK(int k) {
    vector<int> ans;
    for(int i =0; i< 300023;i++){
        if(bankStorage1d[i].id=="" or bankStorage1d[i].id=="X"){
            continue;
        }
        ans.push_back(bankStorage1d[i].balance);
    }
    sort4(ans,0,size-1);
    if(k>=size){
        return ans;
    }
    ans.resize(k);
    return ans;
}

int CubicProbing::getBalance(std::string id) {
    if(doesExist(id)){
        int k = hash(id);
        ull h =k;
        int i =1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i*i))%300023;
            i++;
        }
        return bankStorage1d[h].balance;
    }
    else{
        return -1;
    }
}

void CubicProbing::addTransaction(std::string id, int count) {
    if(doesExist(id)){
        int k =hash(id);
        ull h =k;
        int i=1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i*i))%300023;
            i++;
        }
        bankStorage1d[h].balance+=count;
        return;
    }else{
        createAccount(id,count);
    }
}

bool CubicProbing::doesExist(std::string id) {
    int k = hash(id);
    ull h =k;
    int i=1;
    while(bankStorage1d[h].id!=""){
        if(bankStorage1d[h].id==id){
            return true;
        }
        h=(k+(i*i*i))%300023;
        i++;
    }
    return false;
}

bool CubicProbing::deleteAccount(std::string id) {
    if(doesExist(id)){
        int k = hash(id);
        ull h = k;
        int i =1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i*i))%300023;
            i++;
        }
        bankStorage1d[h].id="X";
        bankStorage1d[h].balance=0;
        size--;
        return true;
    }
    return false;
}
int CubicProbing::databaseSize() {
    return size;
}

int CubicProbing::hash(std::string id) {
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%300023;
        pow = (pow*37)%300023;
    }
    return hashkey;
}
