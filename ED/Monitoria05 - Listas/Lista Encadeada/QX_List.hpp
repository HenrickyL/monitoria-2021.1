//header
#ifndef QX_LIST_H
#define QX_LIST_H

//simplesmente encadeao ou duplamente 
struct node;


class List{
private:
    node* head;
    int _size;
public:
    List();
    ~List();

    bool empty(); //O(1)
    int size();
    void add(int x);//O(n)  Omega(1)
    void pop_back();//O(n)
    void clear();//O(n)
    void print();//O(n)

};



#endif
