#include<iostream>
#include <iomanip>
using namespace std;

/*
    fat(n) = 1*2*3...*(n-1)*n
    fat(0)= 1
    fat(1) = 1
    fat(2) = 2
    fat(3) = 3*2*1 = 6

    fat(n) = n*fat(n-1)
    
    fat(3) = 3* fat(2)
                 2* fat(1)
                      1
*/


int fat(int n){
    //caso base - onde para
    if(n==1) return 1;
    //chamada da recursão
    return n*fat(n-1);
}

double euler(int n){
    double sum=1;
    for(int i=1; i<=n;i++){
        sum+= 1.0/fat(i);
    }
    return sum;
}

/*
    EulerR(0)= 1
    EulerR(1) = 1/1! + EulerR(0)
                        1
    EulerR(3) = 1/3! + EulerR(2)
                        1/2! + EulerR(1)
                                1/1 + eulerR(0)
                                        1
*/


double eulerR(int n){
    if(n==0) return 1;
    return 1.0/fat(n) + eulerR(n-1);
}


int main(){
    int n;
    cin>>n;
    double x = 1.836784954895747393;

    cout<<fixed;
    cout<<fixed<<"Euler("<<n<<"):"<<setprecision(6)<<euler(n)<<"\n";
    cout<<fixed<<"Euler("<<n<<"):"<<setprecision(6)<<eulerR(n)<<"\n";


    return 0;
}