#include<iostream>
using namespace std;

void binario(int n){
    //caso base:
    if(n<0) n = -n;
    if(n==0) cout<<0;
    //chamada da recursão
    else if(n>0){
        int res = n%2;
        binario(n/2);
        cout<<res;
    }
}


int main(){
    int x;
    cin>>x;

    binario(x);



    return 0;
}