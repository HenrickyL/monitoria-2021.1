//implementação
#include"Minas.hpp"
#include <cstdlib>
#include <ctime>
#include<vector>

Minas::Minas(int len){
    _n = len;
    criaMatriz();
}
Minas::~Minas(){

    for(int i=0; i< _n; i++){
        delete[] _mBomb[i];
    }
    delete[] _mBomb;

    for(int i=0; i< _n; i++){
        delete[] _mLoc[i];
    }
    delete[] _mLoc;
}
void Minas::print(int i){
    int** aux;
    i==0?aux=_mBomb:aux=_mLoc;


    for(int i=0; i< _n; i++){
        for(int j=0; j<_n; j++){
            if(aux[i][j]>=0){
                std::cout<<" "<<aux[i][j]<<" ";
            }else{
                std::cout<<aux[i][j]<<" ";

            }
        }
        std::cout<<"\n";
    }
}
void Minas::criaMatriz(){
    _mBomb = new int*[_n];
    for(int i=0;i<_n;i++){
        _mBomb[i] = new int[_n];
        for(int j=0; j<_n;j++)
            _mBomb[i][j]=0;
    }
     _mLoc = new int*[_n];
    for(int i=0;i<_n;i++){
        _mLoc[i] = new int[_n];
        for(int j=0; j<_n;j++)
            _mLoc[i][j]=0;
    }
}
void Minas::addBomb(int x){

    srand((unsigned)time(0));
    for(int i=0;i<x; i++){
        int l = rand()%_n;
        int c = rand()%_n;
        if(_mBomb[l][c]!=-1){
            _mBomb[l][c] = -1;
        }else{
            i--;
        }
    }
        
    
}


int Minas::setLocAt(int i, int j){
    int res =0;
    for(int k=-1; k<=1;k++){
        for(int l=-1; l<=1; l++){
            int valor = _mBomb[i+k][j+l];
            if(valor ==-1){
                res++;
            }
        }
    }
    return res;
}

void Minas::setLocations(){
    for(int i=1; i< _n-1; i++){
        for(int j=1; j<_n-1; j++){
            if(_mBomb[i][j]!=-1){
                _mLoc[i][j] = setLocAt(i,j);
            }
        }
    }
}