#include<iostream>
#include<vector>
using namespace std;

void rotDir(vector<int>& v){
    int n= v.size()-1;
    int last = v[n];
    for(int i=n; i>0; i-- ){
        v[i] = v[i-1];
    }
    v[0] = last;
}


int main(){
    int n;
    cin>>n;
    int qtd;
    cin>>qtd;
    qtd = qtd%n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        int aux;
        cin>>aux;
        v[i]=aux;
    }

    for(int i=0; i<qtd; i++){
        rotDir(v);
    }


    cout<<"[ ";
    for(int aux : v)
        cout<<aux << ' ';
    cout<<"]\n";


    return 0;
}