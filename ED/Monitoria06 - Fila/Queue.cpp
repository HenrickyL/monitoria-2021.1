#include "Queue.h"
#include <iostream>
struct Node{
    Item value;
    Node* next;
};




Queue::Queue(){
    _first = nullptr;
    _last= nullptr;
    _size=0;
}
Queue::~Queue(){
    clear();
}
bool Queue::empty(){
    return _first ==_last && _first == nullptr;
}

Item Queue::first(){
    return _first->value;
}
Item Queue::last(){
    return _last->value;

}
void Queue::push(int x){
    Node* novo = new Node;
    novo->value = x;
    if(empty()){
        _first = novo;
        _last = novo;
    }else{
        _last->next = novo;
        _last = novo;
    }
    _size++;
}
Item Queue::pop(){
    Item res;
    if(!empty()){
        Node* aux = _first;
        if(_first == _last){
            _last = nullptr;
        }
        _first = _first->next;
        res = aux->value;
        delete aux;
    }
    _size--;
    return res;
}
void Queue::clear(){
    while(!empty()){
        pop();
    }
    std::cout<<"lista limpa\n";
}
void Queue::print(){
    Node* aux = _first;
    std::cout<<"[";
    while(aux != nullptr){
        std::cout<<aux->value << ' ';
        aux = aux->next;
    }
    std::cout<<"]\n";

}