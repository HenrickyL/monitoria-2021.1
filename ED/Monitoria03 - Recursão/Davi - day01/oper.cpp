#include<iostream>
#include<vector>
using namespace std;


void vet(vector<int>& v,int n){
    //caso base - encerra

    //chamada da recursão
    if(n>0){
        vet(v,n-1);
        cout<<v[n-1] <<" ";
    }
}
void rvet(vector<int>& v,int n){
    //caso base - encerra

    //chamada da recursão
    if(n>0){
        cout<<v[n-1] <<" ";
        rvet(v,n-1);
    }
}
int sum(vector<int>& v,int n){
    //caso base:
    if(n==0){
        return 0;
    }
    //chamada da recursão:
    else{
        return v[n-1] + sum(v,n-1);
    }
}
int mult(vector<int>& v,int n){
    //caso base:
    if(n==0){
        return 1;
    }
    //chamada da recursão:
    else{
        return v[n-1] * mult(v,n-1);
    }
}
void min(vector<int>& v,int n, int& menor){
    //caso base:
    //chamda da recursão
    if(n>0){
        if(v[n-1]<menor){
            menor = v[n-1];
        }
        min(v,n-1,menor);
    }
}
void inv(vector<int>& v,int n,int i=0){
    //chamada da recursaão
        if(n>i){
            int aux = v[i];
            v[i] = v[n-1];
            v[n-1] = aux;

            inv(v,n-1,i+1);
        }
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++)
        cin>>v[i];

    vet(v,n);
    cout<<"\n";
    rvet(v,n);
    cout<<"\n";
    cout<<"Soma: "<<sum(v,n)<<"\n";
    cout<<"Mult: "<<mult(v,n)<<"\n";
    int menor = v[0];
    min(v,n,menor);
    cout<<"Menor: "<<menor<<"\n";
    inv(v,n);
    vet(v,n);
    cout<<"\n";




    return 0;
}