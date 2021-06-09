#include<iostream>
using namespace std;

//v[1,2,3,4,5] => S(v) = 15

int somaVI(int *v, int n){
    int soma =0;
    for(int i=0; i<n; i++){
        soma+=v[i];
    }
    return soma;
}

int somaV(int *v, int n){
    //caso base:
    if(n==0) return 0;
    //chamada da recursão:
    else{
        return v[0]+somaV(v+1,n-1);
    }
}


int somaV2(int *v, int n){
    //caso base:
    if(n==0) return 0;
    //chamada da recursão:
    else{
        return v[n-1]+somaV(v,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int v[n];

    for(int i=0; i<n; i++){
        cin>>v[i];
    }


    cout<<"Soma =" <<somaVI(v,n)<<"\n";
    cout<<"SomaR ="<<somaV(v,n)<<"\n";
    cout<<"SomaR2 ="<<somaV2(v,n)<<"\n";




    return 0;
}
