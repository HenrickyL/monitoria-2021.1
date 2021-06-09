//cabeçalho
#ifndef PONTO_H
#define PONTO_H


class Ponto{
private: //todos os atributos
    int _x;
    int _y;

public://os metodos
    //construtor
    Ponto();
    Ponto(int x, int y);//inicializar as variaveis ou *p
    //destrutor
    ~Ponto(); // encerrar / desalocações
    //outros metodos
    
    //distancia do meu ponto atual
        //para o meu ponto p
    float distancia(Ponto p);
    void print();
    
public: //getter e setter
    int getX();
    int getY();
    void setX(int valor);
    void setY(int valor);

};


#endif