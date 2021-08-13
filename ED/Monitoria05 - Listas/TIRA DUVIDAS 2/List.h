#ifndef LIST_H
#define LIST_H


struct node;


class List{
private:
    node* _head;
    int _size;

public:
    List(); // O(1)
    ~List(); // O(n)
    bool empty() const;//O(1)
    void clear();//O(n)
    void push_back(int x);//O(1)
    void pop_back();//O(1)
    void print() const;// O(n)
    int size() const;//O(1)
    List* copy();
    bool equal(const List& lst);

};


#endif