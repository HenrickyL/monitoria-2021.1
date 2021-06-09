#include<iostream>
using namespace std;

int** criaMatriz(int n){
    //crio a matriz
    int **M = new int*[n];
    for(int i=0; i<n; i++){
        //criando os vetores
        M[i]= new int[n]; 
    }
    return M;
}

void setMatriz(int** M, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }
}

void printMatriz(int**M, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<< " ";
        }
        cout<<"\n";
    }
}

void deleteMatriz(int** M, int n){
    for(int i=0; i< n; i++)
        delete[] M[i];
    delete[] M;
}

int** somaMatriz(int** A, int** B, int n){
    //cria a matriz
    int** C = new int*[n];
    for(int i=0;i<n;i++){
        //cria os ponteiros internos
        C[i] = new int[n];
        for(int j=0;j<n;j++){
            //set valores 
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}


int main(){
    int n;
    cin>>n;
    int** A = criaMatriz(n); 
    setMatriz(A,n);
    int** B = criaMatriz(n);
    setMatriz(B,n);

    int** C = somaMatriz(A,B,n);


    cout<<"A\n";
    printMatriz(A,n);
    cout<<"B\n";
    printMatriz(B,n);
    cout<<"C=A+B\n";
    printMatriz(C,n);


    


    deleteMatriz(A,n);
    deleteMatriz(B,n);
    deleteMatriz(C,n);


    return 0;
}