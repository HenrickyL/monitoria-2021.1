//implementação
#include "QX_List.hpp"
#include <iostream>

struct node{
    int value;
    node* next=nullptr;
    //node* back;
};

List::List(){ //inicilizar, alocar 
    this->head = new node;
    this->_size =0;
    std::cout<<"<Lista Criada!>\n";
}

List::~List(){ //desalocar
    clear();
    delete head;
    std::cout<<"<Lista Destruida!>\n";

}
//retornar se a lista está vazia
bool List::empty(){
    return head->next == nullptr;
}
void List::add(int x){
    node* novo = new node;
    novo->value = x;
    
    if(this->empty()){
        head->next = novo;
    }else{
        node* aux = head->next;
        //mover o meu aux para o ultimo elemento
        while(aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = novo;
    }
    _size++;
}
void List::pop_back(){
    if(!empty()){
        node* aux = head->next;
        node* aux2 = aux;
        while(aux->next != nullptr){
            aux = aux->next;
            if(aux->next != nullptr){
                aux2 = aux;
            }
        }
        //aux2 penultimo
        //aux está no ultimo
        delete aux;
        aux2->next = nullptr;
        _size--;
    }
}


int List::size(){
    return this->_size;
}


void List::clear(){

    if(!empty()){
        node* aux = head->next;
        node* aux2;
        while(aux != nullptr){
            aux2 = aux->next;
            delete aux;
            aux = aux2;
        }
        head->next = nullptr;
    }
}


void List::print(){
    if(empty()){
        std::cout<<"[]\n";
    }else{
        std::cout<<"[ ";
        node* aux = head->next;
        while(aux != nullptr){
            std::cout<< aux->value<<", ";
            aux = aux->next;
        }
        std::cout<<"]\n";
    }
}