#ifdef MATRIX2_H
#define MATRIX2_H

struct node;


Matriz *soma(Matriz *A, Matriz *B);
Matriz *multiplica(Matriz *A, Matriz *B);
Matriz *lerMatrizDeArquivo(std::string name_arq);


class Matriz{
private:
    int _l,_c;
    node* _head;
    node* _lin;
    node* _col;
    void creteHead();

public:
    Matrix(int l, int c);
    ~Matrix();
    void insert(int i, int j, double x);
    double getValue(int i, int j);
    void print();

};

#endif
