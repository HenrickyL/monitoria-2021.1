//implementação
#include<iostream>
#include"Circulo.hpp"

#include<math.h>


Circulo::Circulo(int x, int y, int r){
    _centro.setX(x);
    _centro.setY(y);
    _raio = r;
    // std::cout<<"Circulo Criado!\n";
}
Circulo::~Circulo(){
    // std::cout<<"Circulo Destruido!\n";
}
float Circulo::getArea(){
    return _pi*_raio*_raio;
}
float Circulo::getCircunferencia(){
    return 2*_pi*_raio;
    
}
bool Circulo::interior(Ponto q){
    int px = _centro.getX();
    int py = _centro.getY();
    int qx = q.getX();
    int qy = q.getX();


    if( qx >= px-_raio && qx<=px+_raio && 
        qy >=py-_raio && qy <= py+_raio){
            return true;
        }else{
            return false;
        }
}
void Circulo::print(){
    std::cout<<"C: centro: "<<" distancia: "<< this->_raio<< " Centro: ";
    _centro.print();


}

Ponto Circulo::getCentro(){
    return _centro;
}
int Circulo::getRaio(){
    return _raio;
}
int Circulo::getX(){
    return _centro.getX();
}
int Circulo::getY(){
    return _centro.getY();
}

void Circulo::setCentro(Ponto p){
    _centro = p;
}
void Circulo::setRaio(int valor){
    _raio = valor;
}
void Circulo::setX(int x){
    _centro.setX(x);
}
void Circulo::setY(int y){
    _centro.setY(y);

}