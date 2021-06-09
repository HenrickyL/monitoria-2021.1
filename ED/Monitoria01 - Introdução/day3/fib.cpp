#include<iostream>
using namespace std;

int fib(int n){
    //caso base://parada da recursão
    if(n==0 || n==1 ) return 1;
    //chamada da recursão
    else 
        return fib(n-1)+ fib(n-2);
}

/*
    fib(4): fib(3)+fib(2) = 3 + 2  = 5
        fib(3): fib(2)+fib(1) = 2 + 1
            fib(2): fib(1)+ fib(0) = 2
             
*/


int main(){
    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<"fib("<<i<<"): "<<fib(i)<<'\n';
    }
    cout<<"\n";

    
    return 0;   
}