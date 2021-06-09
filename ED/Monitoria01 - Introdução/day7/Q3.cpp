#include<iostream>
using namespace std;


void printV(int *v, int n){
    for(int i=0; i< n; i++){
        if(i< n-1)
            cout<<v[i]<<",";
        else
            cout<<v[i];

    }
    cout<<"\n";
}

void triangulo(int *v,int n){
    //caso base
    //chamada da recursão
    if(n>=0){
        //criar um vetor e atribuir os elementos comos endo a soma
        int w[n-1];
        for(int i=0; i<n-1; i++){
            w[i] = v[i]+ v[i+1];
        }
        //
        triangulo(w,n-1);//*
        printV(v,n);
    }
}




int main(){
    int n;
    cin>>n;
    int v[n];

    for(int i=0; i<n;i++){
        cin>>v[i];
    }

    triangulo(v,n);








    return 1;
}