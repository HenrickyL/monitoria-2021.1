#include<iostream>
#include "qx_vector.hpp"
using namespace std;


int main(){
    Qx_vector<int> v(10);
    v.add(2);
    v.add(3);
    v.add(4);
    v.add(-1);
    v.add(9);
    v.add(7);
    v.add(8);
    v.add(10);
    v.add(-4);
    v.add(15);
    v.add(21);

    v.print();

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.print();






    return 0;
}