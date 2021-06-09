#include<iostream>
using namespace std;

//n! = n* (n-1)*(n-2)...3*2*1

int fatI(int n){
    int res = 1;
    for(int i=n; i>1 ; i--){
        res = res*i;
    }
    return res;
}
/*
    fat(n) = n* (n-1)*(n-2)...3*2*1
    fat(3) =3 *2 *10
    fat(1) = 1
    fat(0) = 1
    //recursiva
    fat(n) = n* fat(n-1)

    fat(4) = 4* 6 = 24
        fat(3) = 3* 2
        fat(2) = 2* 1 

*/


int fat(int n){
    //caso base:
    if(n==1 || n==0) return 1;
    //chamada da recursão
    else{
        return n * fat(n-1);
    }
    
}

int fib(int i){
    //caso base:
    if(i==0) return 0;
    else if(i==1) return 1;
    //chamada da recursão:
    else{
        return fib(i-1) +fib(i-2);
    }

}

// fib(n) = fib(n-1) + fib(n-2)
// fib(0) = 0
// fib(1) = 1
// fib(2) = fib(1) + fib(0) =1
// fib()
//0 1 1 2 3 5 8 ...

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cout<<fib(i) <<" ";
    cout<<"\n";

    // cout<<"fatI("<<n<<"): "<<fatI(n)<<"\n";
    // cout<<"fatR("<<n<<"): "<<fat(n)<<"\n";
    


    return 0;
}