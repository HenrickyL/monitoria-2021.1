#include <iostream>
#include "QX_List.hpp"
using namespace std;

int main(){
    List l;
    cout <<"Vazia? " <<l.empty()<<"\n";
    l.add(9);
    cout <<"Vazia? " <<l.empty()<<"\n";
    l.add(2);
    l.add(6);
    l.add(10);
    l.add(8);
    l.add(-1);
    l.print();
    l.pop_back();
    l.pop_back();
    l.print();


    l.clear();
    l.print();




    return 0;
}