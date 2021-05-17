#include<iostream>
using namespace std;

/*

1 2 3
4 5 6
7 8 9

*/

int** lerMatriz(int n){
    int** m = new int*[n];
    for(int i=0;i<n;i++){
        m[i]= new int[n];
    }
    cout<<"matriz ("<<n<<'x'<<n<<") criada! \n";
    return m;
}

void setMatriz(int** m, int n){
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>m[i][j];
        }
    }
}

void printM(int** m, int n){
    cout<<"\n_ _ _ _ _\n";
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cout<<m[i][j]<< ' ';
        }
        cout<<"\n";
    }
    cout<<"_ _ _ _ _\n";

}

void destroiMatriz(int** m, int n){
    for(int i=0;i<n; i++){
        delete[] m[i];
    }
    delete[] m;
}

int sumLin(int* v, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += v[i];
    }
    return sum;
}
int sumCol(int** m, int n, int c){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=m[i][c];
    }

    return sum;
}
int sumDiaP(int** m, int n){
    int sum=0;

    for(int i=0;i<n;i++){
        sum+= m[i][i];
    }
    return sum;
}
int sumDiaS(int** m, int n ){
    int sum=0;
    for(int i=0;i<n;i++){
    sum+= m[i][n-1-i];
    }
    return sum;
}

bool QuadradoMagico(int**m, int n){
    int param = sumDiaP(m,n); // x
    int Ds = sumDiaS(m,n); // x
    if(param!= Ds)return false;
    int lin,col;
    for(int i=0;i<n;i++){
        lin = sumLin(m[i],n);
        col = sumCol(m,n,i);
        if(lin != param && col != param){
           return false; 
        }
    }

    return true;

}


int main(){
    int* v = new int[3];
    int** M = lerMatriz(3);
    setMatriz(M,3);
    printM(M,3);

    if(QuadradoMagico(M,3)){
        cout<<"sim\n";
    }else{
        cout<<"não\n";

    }



    destroiMatriz(M,3);
    return 0;
}