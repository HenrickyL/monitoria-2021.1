#include <iostream>
using namespace std;

void troca(int *i, int *j) {
    int *temp;
    *temp = *i;
    *i = *j;
    *j = *temp;
}

int main(){
    int x,y;
    x=10;
    y=-8;
    cout<<"x: "<<x<<"\n";
    cout<<"y: "<<y<<"\n";

    troca(&x,&y);
    cout<<"\nx: "<<x<<"\n";
    cout<<"y: "<<y<<"\n";


    return 0;
}