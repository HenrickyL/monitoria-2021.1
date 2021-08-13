#ifndef QUEUE_H
#define QUEUE_H
#include "Item.h"
struct Node;


class Queue{
private:
    Node* _last;
    Node* _first;
    int _size;

public:
    Queue();
    ~Queue();
    bool empty();
    Item first();
    Item last();
    void push(int x);
    Item pop();
    void clear();
    void print();

};




#endif