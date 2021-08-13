#include "List.h"
#include<iostream>

struct node{ //lista duplamente encadeada
    int value;
    node* next;
    node* back;
};



List::List(){
    _size = 0;
    _head = new node;
    _head->value =-999;
    //circularidade
    _head->next = _head;
    _head->back = _head;

    std::cout<<"Lista criada!\n";

}
List::~List(){
    clear();
    delete _head;
    std::cout<<"Lista Destruida!\n";

}

int List::size() const{
    return _size;
}


bool List::empty() const{ //O(1)
    return _head->next == _head;
}
void List::clear(){
    while(! this->empty()){
        pop_back();
    }
}
void List::push_back(int x){
    node* novo = new node;
    novo->value = x;
    node* last=_head->back;
   
    last->next = novo;
    novo->back = last;
    //operaçaõ do head
    novo->next = _head;
    _head->back = novo;
    _size++;


}
void List::pop_back(){
    if(!this->empty()){
        node* last = _head->back;
        //penultimo
        (last->back)->next = _head;
        _head->back = last->back;

        last->next = nullptr;
        last->back = nullptr;

        delete last;
        _size--;
    }
}
void List::print()const{
    std::cout<<"[";
    node* aux=_head->next;
    while(aux != _head){
        std::cout<<aux->value<<" ";
        aux = aux->next;
    }
    std::cout<<"]\n";
}

List* List::copy(){
    List* lst = new List;
    
    //verificar se a lista está vazia
    if(!this->empty()){
        node* aux = _head->next;
        while(aux != _head){
            lst->push_back(aux->value);
            aux = aux->next;
        }
    }
    return lst;
}

bool List::equal(const List& lst){
    if(this->empty() && lst.empty()){
        return true;
    }else if(this->empty() || lst.empty()){
        return false;
    }else if(this->size() != lst.size()){
        return false;
    }else{
        node *aux = this->_head->next;
        node *k = lst._head->next;
        while(aux != _head && k != lst._head){
            if(aux->value != k->value){
                return false;
            }
            //mover
            aux = aux->next;
            k = k->next;
        }


        return true;
    }
}

