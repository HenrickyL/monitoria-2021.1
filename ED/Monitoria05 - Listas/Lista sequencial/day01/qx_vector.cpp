#include "qx_vector.hpp"
#include<iostream>

template<typename T>
Qx_vector<T>::Qx_vector(int capacidade){
    this->_capacidade = capacidade;
    this->_data = new T[_capacidade];
    _size=0;
    std::cout<<"Vector Criado!\n";
}

template<typename T>
Qx_vector<T>::~Qx_vector(){
 delete[] _data;
}

template<typename T>
void Qx_vector<T>::add(T x){
    if(_size < _capacidade){
        _data[_size] = x;
        _size++;
    }else{
        std::cout<<"atingiu a capacidade!\n";
    }
}

template<typename T>
void Qx_vector<T>::pop_back(){
    if(_size>0){
        _size--;
    }else{
        std::cout<<"vetor ja está vazio!\n";
    }
}

template<typename T>
int Qx_vector<T>::size(){
    return _size;
}

template<typename T>
void Qx_vector<T>::print(){
    std::cout<<"[ ";
    for(int i=0; i< _size; i++){
        std::cout<<_data[i]<<',';
    }
    std::cout<<"]\n";

}