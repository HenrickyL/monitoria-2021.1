#include<iostream>
using namespace std;


void inverte(int *v, int n){
    //caso base:
    //chamada da recursão:
    if(n>1){
        int aux = v[0];
        v[0] = v[n-1];
        v[n-1]=aux;
        inverte(v+1,n-2);
    }
}

void printV(int*v, int n){
    //caso base:
    //chamada da recursão:
    if(n>0){
        cout<<v[0]<<' ';
        printV(v+1,n-1);
    }
}


int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++) cin>>v[i];

    printV(v,n);
    cout<<"\n";
    inverte(v,n);
    printV(v,n);
    cout<<"\n";



    return 0;
}