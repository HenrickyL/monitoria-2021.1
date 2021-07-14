#ifndef QX_VECTOR_H
#define QX_VECTOR_H


template <typename T>
class Qx_vector{
private:
    T* _data;
    int _capacidade=0;
    int _size=0;


public: 
    Qx_vector(int capacidade);
    ~Qx_vector();

    void print();
    void add(T x);
    void pop_back();
    int size();


};


#endif