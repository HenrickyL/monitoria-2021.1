#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku{
public:
    int** _data;
private:
    bool _resolve=false;
    int _size=9;
    int _block_size =3;


    
    bool possible(int x, int y, int n);
    //criar o bloco
    //verificar se um valor é valido no bloco
    bool valueBlockPosible(int x,int y, int n);
    //diferentes de 0, logo foi criado
    bool isBlockOk(int x, int y);
public:
    Sudoku();
    ~Sudoku();
    void resetBlock(int x, int y);

    void createBlock(int x, int y);
    void create();
    void resolve();
    void remove(int n);
    void print();


    
};




#endif