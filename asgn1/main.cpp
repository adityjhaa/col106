#include<iostream>
#include<vector>
using namespace std;


//some basic functions
int minus_1(){
    return -1;
}

int search(vector<int> x, int k){
    int l=x.size();
    int s=0;
    int e=l-1;
    while(s<=e){
        int m=(s+e)/2;
        if(x[m]==k){
            return 1;
        }else if(x[m]>k){
            e=m-1;
        }else{
            s=m+1;
        }        
    }
    return 0;
}

void insertx(vector<int> &a,int d){
    if(a.size()==0){
        a.push_back(d);
    }
    if(search(a,d)==0){
        if(a[a.size()-1]<d){
            a.push_back(d);
        }
        else{
            int i=0;
            while(i<a.size()){
                if(a[i]>d){
                    a.insert(a.begin()+i,d);
                    break;
                }
                i++;
            }
        }
    }
}


// defining the SET data structure
class SET{
    public:
    vector<int> a;
    SET(){}

    // member functions
    int ithelement(int i){
        return a[i];
    }

    int belongsto(int k){
        int l=a.size();
        int s=0;
        int e=l-1;
        while(s<=e){
            int m=(s+e)/2;
            if(a[m]==k){
                return 1;
            }else if(a[m]>k){
                e=m-1;
            }else{
                s=m+1;
            }        
        }
        return 0;
    }

    int insert0(int d){
        if(a.size()==0){
            a.push_back(d);
            return 1;
        }
        if(search(a,d)==0){
            if(a[a.size()-1]<d){
                a.push_back(d);
            }
            else{
                int i=0;
                while(i<a.size()){
                    if(a[i]>d){
                        a.insert(a.begin()+i,d);
                        break;
                    }
                    i++;
                }
            }
        }
        return a.size();
    }

    int remove(int d){
        if(a.size()==0) return 0;
        if(search(a,d)==1){
            int i=0;
            while(i<a.size()){
                if(a[i]==d){
                    a.erase(a.begin()+i);
                    break;
                }
                i++;
            }
        }
        return a.size();
    }

    int size0(){
        return a.size();
    }

    int union0(SET b){
        for(int i=0;i<b.size0();i++){
            if(search(a,b.ithelement(i))==0){
                insertx(a,b.ithelement(i));
            }
        }
        return a.size();
    }

    int intersection(SET b){
        vector<int> c;
        for(int i=0;i<a.size();i++){
            if(b.belongsto(a[i])==1){
                c.push_back(a[i]);
            }
        }
        a=c;
        return a.size();
    }

    int difference(SET b){
        vector<int> c;
        for(int i=0;i<a.size();i++){
            if(b.belongsto(a[i])==0){
                c.push_back(a[i]);
            }
        }
        a=c;
        return a.size();
    }

    int symmetricdiff(SET b){
        vector<int> c;
        for(int i=0;i<a.size();i++){
            if(b.belongsto(a[i])==0){
                c.push_back(a[i]);
            }
        }
        for(int i=0;i<b.size0();i++){
            if(search(a,b.ithelement(i))==0){
                insertx(c,b.ithelement(i));
            }
        }
        a=c;
        return a.size();
    }

    void print(){
        if(a.size()>0){
            for(int i=0;i<a.size()-1;i++){
                cout << a[i]<<",";
            }
            cout << a[a.size()-1];
        }
        cout << endl;
    }

};


// creating a vector to store the different SETs
vector<SET> vector_set;
void create(int n){
    if((n+1)> vector_set.size()){
    SET*b = new SET();
    vector_set.push_back(*b);
    }
}


// the main function
int main(){
    int a,b,c;
    // input via while loop
    while(cin >> a){
        
        // cases for a
        if(a==6 or a==9){
            cin >> b;
            
            switch(a){

            case 6: 
                create(b);
                cout << vector_set[b].size0()<<endl;
            break;
            case 9:

                if(b+1>vector_set.size()){
                    cout << endl;
                }else{
                    vector_set[b].print();
                }
            break;
            }
        }else{
            cin >> b >> c;

            switch(a){

                case 1:
                    create(b);
                    cout << vector_set[b].insert0(c)<<endl;
                break;
                case 2:

                    if(b+1>vector_set.size()){
                        cout << minus_1()<< endl;
                    }else{
                        cout << vector_set[b].remove(c)<<endl;
                    }
                break;
                case 3:

                    if(b+1>vector_set.size()){
                        cout << minus_1()<< endl;
                    }else{
                        cout << vector_set[b].belongsto(c)<<endl;
                    }
                break;
                case 4:

                    create(b);
                    create(c);
                    cout << vector_set[b].union0(vector_set[c])<<endl;
                break;
                case 5:

                    create(b);
                    create(c);
                    cout << vector_set[b].intersection(vector_set[c])<<endl;
                break;
                case 7:

                    create(b);
                    create(c);
                    cout << vector_set[b].difference(vector_set[c])<<endl;
                break;
                case 8:
                
                    create(b);
                    create(c);
                    cout << vector_set[b].symmetricdiff(vector_set[c])<<endl;
                break;
                default:
                break;
            }
        }
        
    }

    return 0;
}