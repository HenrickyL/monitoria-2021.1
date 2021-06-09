#include <iostream>
using namespace std;


int fat(int n){

    //caso base:
    if(n==0|| n==1) return 1;
    //chamada da recursão
    else
        return n*fat(n-1);
}

int somaV(int* v, int n){
    //caso base:
    if(n<1) return 0;
    //chamada da recursão:
    else{
        return v[0]+somaV(v+1,n-1);
    }
}


int somaV2(int* v, int n){
    //caso base:
    if(n<1) return 0;
    //chamada da recursão:
    else{
        return v[n-1]+somaV(v,n-1);
    }
}

void printReverse(int n){
    //caso base:
    //chamada da Recursão
    if(n>=0){
        if( n%2==0){
            printReverse(n-2);
            cout<<n<<" ";
        
        }else{
            printReverse(n-1);
        }

    }
}

int main(){
    int n;
    cin>>n;
    
    printReverse(n);

    // cout<<"soma:" << somaV(v,n)<<"\n";
    
    return 0;
}