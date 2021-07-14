#include<iostream>
#include"Minas.hpp"

using namespace std;

int main(){
    Minas m(8);
    m.print(0);
    cout<<"\n-----------------\n";
    m.addBomb(10);
    m.print(0);
    cout<<"\n-----------------\n";
    m.setLocations();
    m.print(1);






    
    return 0;
}