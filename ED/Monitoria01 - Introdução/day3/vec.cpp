#include<iostream>
using namespace std;

//func recursiva que soma os elementos de um vetor

// Soma([1,4,6,8,9]) = 29
/*
    [1,4,6,8,9]         | 9 + SomaR([1,4,6,8], 4)
    [1,4,6,8]       9]  | 8 + SomaR([1,4,6], 3)
    [1,4,6,]      8,9]  | 6 + SomaR([1,4], 2)
    [1,4]       6,8,9]  | 4 + SomaR([1], 1)
    [1]       4,6,8,9]  | 1 + SomaR([], 0)
    []      1,4,6,8,9]  | SomaR([], 0) = 0
    
*/

int somaR(int*v, int n){
    //caso base
    if(n==0) return 0;
    //chamada da recursão
    else{
        
        return v[n-1] + somaR(v,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int res = somaR(v,n);
    cout<<"R: "<<res<<"\n";




    return 0;
}