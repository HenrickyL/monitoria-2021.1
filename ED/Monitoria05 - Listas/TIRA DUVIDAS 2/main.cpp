#include<iostream>
#include "List.h"
using namespace std;

int main(){

    List* l = new List;
    cout<<"vazia? "<< l->empty()<<"\n";
    l->push_back(4);
    l->push_back(2);
    l->push_back(6);
    l->push_back(2);
    l->push_back(9);
    l->push_back(3);
    l->push_back(1);
    cout<<"size: "<< l->size()<<"\n";
    l->print();
    l->pop_back();
    l->pop_back();
    cout<<"size: "<< l->size()<<"\n";
    l->print();
    cout<<"Copia: ";
    List* nova = l->copy();
    cout<<"iguais: "<< l->equal(*nova)<<"\n";
    nova->print();
    nova->push_back(-15);
    nova->print();
    l->print();
    cout<<"iguais: "<< nova->equal(*l)<<"\n";



    
    delete l;
    delete nova;





    return 0;
}