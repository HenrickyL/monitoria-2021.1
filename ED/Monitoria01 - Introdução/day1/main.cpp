#include <iostream>

using namespace std;

bool primo(int n){
    for(int i=2;i< sqrt(n); i++){
        if( n%i == 0 ){
            return false;
        }
    }
    return true;
}


int main(){
   int A,B;
   cout<<"A:";
   cin>>A;
   cout<<"B:";
   cin>>B;

   for(int i=A; i<=B; i++ ){
       if( primo(i) ){
           cout<<i  << ' ';
       }
   }
   cout<<"\n";
    


    return 0;
}
