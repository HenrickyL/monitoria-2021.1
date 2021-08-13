#include "Stack.h"
#include <iostream>

struct node{
    Item value;
    node* next=nullptr;
};


Stack::Stack(){
    _size=0;
    _top = nullptr;
}
Stack::~Stack(){
    std::cout<<"destruindo...\n";
    while(!empty()){
        pop();
    }
}
bool Stack::empty(){
    return _top == nullptr;
}
Item Stack::top(){
    return _top->value;
}
void Stack::push(Item x){
    node* novo = new node;
    novo->value = x;
    novo->next = _top;
    _top = novo;
    _size++;
}
Item Stack::pop(){
    if(!empty()){
        Item valor = _top->value;
        node* aux = _top;
        _top = _top->next;
        aux->next = nullptr;
        delete aux;
        _size--;
        return valor;
    }
    return -99;

}

void Stack::print() const{
    std::cout<<"_\n";
    node* aux = _top;
    while(aux!= nullptr){
        std::cout<<aux->value<<"\n";
        aux= aux->next;
    }
    std::cout<<"_\n";

}


int Stack::size(){
    return _size;
}
