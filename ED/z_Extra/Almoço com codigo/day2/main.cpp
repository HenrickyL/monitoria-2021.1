#include<iostream>
using namespace std;

int fat(int n){
    //caso base: // caso de parada
    if(n==1 || n==0) return 1;
    //chamada da recursão
    else
        return n*fat(n-1);
}

int somaVR1(int v[], int n){
    //caso base:
    if(n<1) return 0;
    //chamada da recursão
    else{
        return v[n-1] + somaVR1(v,n-1);
    }
}  
int somaVR2(int v[], int n){
    //caso base:
    if(n<1) return 0;
    //chamada da recursão
    else{
        return v[0] + somaVR1(v+1,n-1);
    }
}  



void min(int v[], int n, int* m){ //v[0]
    //caso base:
    //chamada da recursão:
    if(n>1){
        if(v[n-1] < *m){
            *m = v[n-1];
        }
        min(v,n-1, m);
    }
}

void min2(int v[], int n, int* m){ //v[0]
    //caso base:
    //chamada da recursão:
    if(n>0){
        if(v[0] < *m){
            *m = v[0];
        }
        min2(v+1,n-1, m);
    }
}





int main(){
    int n;
    cin>>n;
    int v[n];
    int m;
    for(int i=0; i<n; i++)
        cin>>v[i];
    m = v[n-1];

    // min(v,n,&m);
    min(v,n,&m);


    cout<<"menor: " << m<<'\n';
 


    return 0;
}