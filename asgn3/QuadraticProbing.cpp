#include "QuadraticProbing.h"
using namespace std;

#define ull unsigned long long

void merge3(vector<int> &arr, int s, int e, int m){
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

void sort3(vector<int> &arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        sort3(arr,s,m);
        sort3(arr,m+1,e);
        merge3(arr,s,e,m);
    }
}

QuadraticProbing::QuadraticProbing(){
    bankStorage1d.resize(200003);
    size=0;
}

void QuadraticProbing::createAccount(std::string id, int count) {
    int k = hash(id);
    ull h =k;
    int i =1;
    while(bankStorage1d[h].id!=""){
        h=(k+(i*i))%200003;
        i++;
    }
    bankStorage1d[h].id=id;
    bankStorage1d[h].balance=count;
    size++;
}

std::vector<int> QuadraticProbing::getTopK(int k) {
    vector<int> ans;
    for(int i =0; i< 200003;i++){
        if(bankStorage1d[i].id=="" or bankStorage1d[i].id=="X"){
            continue;
        }
        ans.push_back(bankStorage1d[i].balance);
    }
    sort3(ans,0,size-1);
    if(k>=size){
        return ans;
    }
    ans.resize(k);
    return ans;
}

int QuadraticProbing::getBalance(std::string id) {
    if(doesExist(id)){
        int k = hash(id);
        ull h =k;
        int i =1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i))%200003;
            i++;
        }
        return bankStorage1d[h].balance;
    }
    else{
        return -1;
    }
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    if(doesExist(id)){
        int k =hash(id);
        ull h =k;
        int i=1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i))%200003;
            i++;
        }
        bankStorage1d[h].balance+=count;
        return;
    }else{
        createAccount(id,count);
    }
}

bool QuadraticProbing::doesExist(std::string id) {
    int k = hash(id);
    ull h =k;
    int i=1;
    while(bankStorage1d[h].id!=""){
        if(bankStorage1d[h].id==id){
            return true;
        }
        h=(k+(i*i))%200003;
        i++;
    }
    return false;
}

bool QuadraticProbing::deleteAccount(std::string id) {
    if(doesExist(id)){
        int k = hash(id);
        ull h = k;
        int i =1;
        while(bankStorage1d[h].id!=id){
            h=(k+(i*i))%200003;
            i++;
        }
        bankStorage1d[h].id="X";
        bankStorage1d[h].balance=0;
        size--;
        return true;
    }
    return false;    
}

int QuadraticProbing::databaseSize() {
    return size;
}

int QuadraticProbing::hash(std::string id) {
    int hashkey =0;
    int pow = 1;
    
    for(char ch : id){
        hashkey = (hashkey + ch*pow)%200003;
        pow = (pow*37)%200003;
    }
    return hashkey;
}

