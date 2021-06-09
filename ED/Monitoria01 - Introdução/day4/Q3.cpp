#include<iostream>
using namespace std;

void mm(int A[], int n, int *min, int *max){
    *min = A[0];
    *max = A[0];
    for(int i=1; i<n; i++){
        if(*max < A[i] ){
            *max = A[i];
        }else if(*min > A[i]){
            *min = A[i];
        }
    }
}


int main(){
    int n;
    cin>>n;
    int v[n];
    int Maior=-999, menor=-999;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    mm(v, n, &menor, &Maior);

    cout<<"M: "<<Maior << "\n";
    cout<<"m: "<<menor << "\n";


    return 0;
}