//implementação
#include"Ponto.hpp"
#include<iostream>
#include<math.h>

Ponto::Ponto(){
    _x = -1;
    _y= -1;
    // std::cout<<"Ponto Criado*!\n";

}
Ponto::Ponto(int x, int y){
    _x = x;
    _y = y;
    // std::cout<<"Ponto Criado!\n";
}
Ponto::~Ponto(){
    // std::cout<<"Ponto Destruido!\n";
}

void Ponto::print(){
    std::cout<<"P( "<<_x<<", "<<_y<<")\n";
}

float Ponto::distancia(Ponto p){
    float auX = (p._x - this->_x)*(p._x - this->_x);
    float auxY=(p._x - this->_y)*(p._x - this->_y);
    
    return std::sqrt( auX + auxY);
}

int Ponto::getX(){
    return _x;
}
int Ponto::getY(){
    return _y;
}
void Ponto::setX(int valor){
    _x = valor;
}
void Ponto::setY(int valor){
    _y = valor;
}