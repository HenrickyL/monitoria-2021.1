//cabeçalhos / header
#ifndef CIRCULO_H
#define CIRCULO_H

#include"Ponto.hpp"
class Circulo{
private:
    Ponto _centro;
    int _raio;
    float _pi = 3.1415;
public:
    Circulo(int x, int y, int r);
    ~Circulo();
    float getArea();
    float getCircunferencia();
    bool interior(Ponto p);
    void print();


public: //getter e setters
    Ponto getCentro();
    int getRaio();
    int getX();
    int getY();

    void setCentro(Ponto p);
    void setRaio(int valor);
    void setX(int x);
    void setY(int y);
};


#endif