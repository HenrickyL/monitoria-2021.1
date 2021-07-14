//header - cabeçalho
#ifndef MINAS_H
#define MINAS_H
#include<iostream>

class Minas{
private:
    int** _mBomb;
    int** _mLoc;
    int _n;
    void criaMatriz();
    int setLocAt(int i, int j);
public:
    //inicializa variaveis e aloca variaveis
    Minas(int len);
    //desaloca
    ~Minas();
    void print(int i);
    void addBomb(int x);
    void setLocations();

    
};

#endif