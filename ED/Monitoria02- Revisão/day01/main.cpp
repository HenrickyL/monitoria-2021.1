#include<iostream> //importando da pasta padrão
#include"Ponto.hpp"
#include"Circulo.hpp"
using namespace std;


// g++ main.cpp Ponto.cpp Circulo.cpp -o exe
// g++ -c Ponto.cpp ponto

int main(){
    Ponto p1(0,0);
    Ponto p2(1,1);
    Ponto p3(2,2);

    Circulo c1(p1.getX(),p1.getY(),1);
    Circulo c2(p2.getX(),p2.getY(),2);
    


    p1.print();
    p2.print();
    p3.print();
    c1.print();
    c2.print();
    cout<<"\n\ndistancia p2 p3:" << p2.distancia(p3)<<"\n";
    cout<<"distancia p1 p3:" << p1.distancia(p3)<<"\n";
    cout<<"\nArea c1: "<<c1.getArea()<<"\n";
    cout<<"Circunfencia c1: "<<c1.getCircunferencia()<<"\n";

    cout<<"\nArea c2: "<<c2.getArea()<<"\n";
    cout<<"Circunfencia c2: "<<c2.getCircunferencia()<<"\n";

    c1.interior(p3)? cout<<"p3 em c1\n": cout<<"p3 não está em c1\n";
    c2.interior(p3)? cout<<"p3 em c2\n": cout<<"p3 não está em c2\n";






    return 0;
}