#include "Matriz.h"
#include <iostream>

struct node{
    int i,j;
    node* next;
    node* down;
    double value;
}



Matriz::Matriz(int l, int c){
    _l = l;
    _c = c;
    _head= new node;
    _head->i = -1;
    _head->j = -1;
    _head->next = _head;
    _head->down = _head;
    creteHead();
}
void Matriz::creteHead(){
    _col = _head;
    //colunas
    node* novo;
    for(int i=1; i<= _c; i++){
        novo = new node;
       _col->next = novo;
       novo->value = 555;
       novo->i=-1;
       novo->j=i;
       novo->down = novo;
       _col = _col->next;
     
    }
    //ajustar a circularidade
    _col->next = _head;

//////////////////////////////////////////
    _lin = _head;
    //linhas
    for(int i=1; i<= _c; i++){
        novo = new node;
       _col->down = novo;
       novo->value = 999;
       novo->i=i;
       novo->j=-1;
       novo->next = novo;
       _lin = _lin->down;
     
    }
    //ajustar a circularidade
    _lin->down = _head;

}


Matriz::~Matriz(){

}
void Matriz::insert(int l, int c, double x){
    node* novo = new node;
    novo->i = l;
    novo->j = c;
    novo->value = x;
    //verificar os casos de inserção
    _lin = _head->down;
    //mover para a linha certa
    while(_lin != _head){
        if(_lin->i == l){   
            break;
        }
        _lin = _lin->down;
    }
    //caso o num_lin > ultima linha
    if(_lin == _head){
        delete novo;
        return;
    }
    //inserir
    bool inseridoL = false;
        //simples
    if(_lin->next == _lin){
        _lin->next = novo;
        novo->next = _lin;
    }else{
        node* aux = _lin->next;
        while(aux->next != _lin){
            //verificar as posições
            if(aux->next->j > novo->j){
                node* prox = aux->next;
                aux->next = novo;
                novo->next = prox;
                inseridoL=true;
            }
            aux = aux->next;
        }
        if(!inseridoL){
            aux->next = novo;
            novo->next = _lin;
        }
    }


}
