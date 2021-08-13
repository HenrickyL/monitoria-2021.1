#include<iostream>
#include "Item.h"
#include "Stack.h"
using namespace std;

int main(){
    Stack p;
    cout<<"vazia? "<<p.empty()<<"\n";
    p.push('a');
    p.push('b');
    p.push('c');
    p.push('d');
    p.push('e');
    cout<<"vazia? "<<p.empty()<<"\n";
    cout<<"size: "<<p.size();
    p.print();
    cout<<"removeu: " << p.pop()<<'\n';
    cout<<"removeu: " << p.pop()<<'\n';
    
    p.print();






    return 0;
}