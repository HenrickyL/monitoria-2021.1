#include<iostream>
#include "sudoku.hpp"
#include <cstdlib>
#include <ctime>

Sudoku::Sudoku(){
    _size=9;
    _block_size =3;
    _data = new int*[_size];
    for(int i=0;i<_size;i++){
        _data[i]=new int[_size];
        for(int j=0;j<_size;j++){
            _data[i][j]=0;
        }
    }
//criar os numeros
    //create();
}


Sudoku::~Sudoku(){
    for(int i=0;i<_size;i++) delete[] _data[i];
    delete _data;

}

bool Sudoku::valueBlockPosible(int x,int y,int n){
    for(int i=0; i<_size; i++)
        if(_data[x][i] ==n) return false;
    for(int i=0; i<_size; i++)
        if(_data[i][y] ==n) return false;
    int x0 = ((int) x/3)*3;
    int y0 = ((int) y/3)*3;
    for(int i=0; i<_block_size; i++){
        for(int j=0;j<_block_size;j++){
            if(_data[x][y] == n) return false;
        }
    }
    return true;
}

bool Sudoku::isBlockOk(int x, int y){
    int x0 = ((int) x/3)*3;
    int y0 = ((int) y/3)*3;
    for(int i=0; i<_block_size; i++){
        for(int j=0;j<_block_size;j++){
            if(_data[x0+i][y0+j] == 0) return false;
        }
    }
    return true;
}

void Sudoku::resetBlock(int x, int y){
    int x0 = ((int) x/3)*3;
    int y0 = ((int) y/3)*3;
    for(int i=0; i<_block_size; i++){
        for(int j=0;j<_block_size;j++){
            _data[x0+i][y0+j]=0;
        }
    }
}
int proximoValido(int* v, int *n){
    std::srand(std::time(0));
    if(*n>0){
        int i = rand()%*n;
        if(v[i]!=0){
            int aux = v[i];
            v[i]=0;
            std::swap<int>(v[i],v[*n-1]);
            *n-=1;   
            return aux;
        }else{
            return proximoValido(v,n);
        }
    }else {
        for(int k=0;k<9;k++) v[k]=k+1;
        *n=9;
        return 0;
    }
    
    
    
}

void Sudoku::createBlock(int x,int y){
    int x0 = ((int) x/3)*3;
    int y0 = ((int) y/3)*3;
        
    int vLen=9;
    int v[vLen]= {1,2,3,4,5,6,7,8,9};
    if(!isBlockOk(x,y)){
        for(int i=0; i<_block_size; i++){
            for(int j=0;j<_block_size;j++){
                int n = proximoValido(v,&vLen);
                if(valueBlockPosible(x0+i,y0+j,n) ){
                    _data[x0+i][y0+j]=n;
                }else{
                    j--;
                }
                
            }
        }
    }
}

void Sudoku::create(){
    // int valores[9]={1,2,3,4,5,6,7,8,9};
    std::srand(std::time(0));

    for(int i=0;i<_size;i++){
        for(int j=0; j<_size;j++){
            // int p = rand()%9+1;
            //achar um valor valido
            createBlock(i,j);        

        }
    }
    _resolve = true;
    std::cout<<"gerado!\n";

}

bool Sudoku::possible(int x, int y, int n){
    //colunas
    for(int i=0;i<_size;i++){
        if(_data[x][i]==n) return false;
    }
    //linhas
    for(int i=0;i<_size;i++){
        if(_data[i][y]==n) return false;
    }
    //bloco
    int x0 = ((int) x/3)*3;
    int y0 = ((int) y/3)*3;
    for(int i=0; i<_block_size; i++){
        for(int j=0; j<_block_size; j++){
            if(_data[x0+i][y0+j]==n)
                return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////
void Sudoku::resolve(){
    int tick =0;
    int vLen=9;
    int v[vLen]= {1,2,3,4,5,6,7,8,9};
    
    for(int i=0; i<_size; i++){
        for(int j=0;j<_size;j++){
            if(_data[i][j]==0){
                int n = proximoValido(v,&vLen);
                if(n==0) n = proximoValido(v,&vLen);
                tick++;
                if(possible(i,j,n)){
                    std::cout<<"Teste("<<i<<", "<<j<<"): "<<n<<"...\n";
                    _data[i][j]=n;
                }else{
                    j--;
                }
            }
        }
    }
    
    std::cout<<"resolvido!\n";
}
void Sudoku::remove(int n){
    srand(time(0));
    for(int i=0; i<n;i++){
        int x = rand()%9;
        int y = rand()%9;

        if(_data[x][y]!=0){
            _data[x][y]=0;
        }else{
            i--;
        }
    }
}
void Sudoku::print(){
    for(int i=0;i<_size;i++){
        for(int j=0; j<_size;j++){
            if((j+1)%_block_size==0 && j!=_size-1){
                std::cout<<_data[i][j]<<" | ";
            }else{
                std::cout<<_data[i][j]<<' ';
            }
        }
        std::cout<<"\n";

        if((i+1)%_block_size==0 && i!=_size-1){
            for(int k=1; k<=_size+2; k++)
                if((k)%(_block_size+1)==0)
                    std::cout<<" _";
                else
                    std::cout<<"__";

            std::cout<<"\n";

        }
    }
}
