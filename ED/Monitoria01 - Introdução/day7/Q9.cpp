#include<iostream>

using namespace std;

void min(int *v, int n, int* m){
    //caso base
    //chamada da Recursão
    if(n>=0){
        if(v[0] < *m){
            *m = v[0];
        }
        min(v+1,n-1,m);
    }
}

int min2(int *v, int n, int menor=9999){
    //caso base:
    if(n==0) return menor;
    //chamada da recursão
    else{
        if(v[n-1]< menor){
            menor= v[n-1];
        }

        return min2(v,n-1,menor);
    }
}

int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i< n; i++)
        cin>>v[i];
    
    int menor = min2(v,n);

    cout<<"menor: "<<menor<<"\n";
    return 0;
}