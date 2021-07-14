#include<iostream>
#include"sudoku.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;



int main(){
   

    Sudoku s;
    // for(int i=0; i<9; i++){
    //     for(int j=0; j< 9;j++){
    //         cin>>s._data[i][j]; 

    //     }
    // }


    
    
    s.create();

    s.print();
    std::cout<<"\n--------------------\n";
    int x;
    cout<<"remover: ";
    cin>>x;
    s.remove(x);
    s.print();
    std::cout<<"\n--------------------\n";

    s.resolve();
    s.print();


    return 0;

}




