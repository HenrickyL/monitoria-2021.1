#include<iostream>
using namespace std;

void rotDir(int*v, int n, int k){
    //reajustar o k
    k = k%n;
    for(int j=0; j< k; j++){
        int aux = v[n-1];//salvo o ultimo
        for(int i=n-1; i>=0; i--){
            if(i!=0){  
                v[i] = v[i-1];
            }else{
                v[0]=aux;
            }
        }
    }
}


void print(int* v, int n){
    cout<<"[ ";
    for(int i=0; i< n; i++) 
        cout<<v[i]<<" ";
    cout<<"]\n";

}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int v[n];
    for(int i=0; i< n; i++) v[i]=i+1;
    
    
    
    rotDir(v, n, k);

    print(v,n);


    return 0;
}