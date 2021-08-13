#include<iostream>
#include "Queue.h"

using namespace std;

int main(){
    Queue f;
    cout<<"vazia? "<<f.empty()<<"\n";
    f.push('a');
    f.push('b');
    f.push('c');
    std::cout<<"f: "<<f.first() << " l:"<<f.last()<<"\n";
    f.push('d');
    f.push('e');
    std::cout<<"f: "<<f.first() << " l:"<<f.last()<<"\n";
    cout<<"vazia? "<<f.empty()<<"\n";
    f.print();
    f.pop();
    f.pop();
    std::cout<<"f: "<<f.first() << " l:"<<f.last()<<"\n";

    f.print();
    f.clear();
    f.print();

    






    return 0;
}