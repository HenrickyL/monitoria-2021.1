#ifndef PILHA_H
#define PILHA_H

#include "Item.h"

struct node;

class Stack{
private:
    node* _top;
    int _size;
public:
    Stack();
    ~Stack();
    bool empty();
    Item top();
    void push(Item x);
    Item pop();
    void print() const;
    int size();

};



#endif