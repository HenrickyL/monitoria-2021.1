#ifndef SUDOKU_H
#define SUDOKU_H
/*
        CONHECIMENTOS
    * numeros aleatorios
    * Alocação de matriz
    * Basico de classe se for fazer com classe
    * Leitura e escrita em arquivo
    * Parametros da main (int argc, char** argsv[])
        - $ ./Sudoku --generate 10 
    * Trabalhar com string para verificar as flags
        - --generate --remove --solver
    * Uso do makefile (provavelmente)
*/


class Sudoku{
private:
   

    int** _m;
    int _size;
    bool _solved=true;//não tem valores removidos

    //gerar os numeros
    void gerar();
public:
    //Construtor - aloca a matriz e gera os numeros
    Sudoku();
    //Destrutor - desalocar a matriz 
    ~Sudoku();
    //remover numeros -  alterando o valor (1-9) para 0
    void remove(int qtd);
    //resolve o sudoku
    void resolve();
    //salvar em arquivo
    void salvar(char index);//sol_sudoku{index}.txt
    //printa o sudoku
    void print();
};


#endif
