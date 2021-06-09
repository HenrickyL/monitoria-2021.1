#include <iostream>
#include <cstdlib> //cin.ignore //cin.get(ponteiro, len)
using namespace std;


// abacatet
// abacaxi

int strcpm(char* a, char* b){
    for(int i=0; a[i] || b[i]; i++){
        if(a[i]<b[i]) return -1;
        else if(a[i]>b[i]) return 1;
    }
    return 0;
}

//ordenação
void ordena(char** v, int n){
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-1; j++){
            if( strcpm(v[j],v[j+1])==1 ){
                char* aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}


void strPrint(char* s){
    for(int i=0; s[i]!='\0' ; i++){
        cout<<s[i];
    }
    cout<<"\n";
}


int main(){
    int n;
    cin>>n;
    char** v = new char*[n];
    int l;
    for(int i=0;i<n;i++){
        cin>>l;
        v[i]= new char[l];
        cin.ignore();//limpar o buffer e permite 
        cin.get(v[i],l+2);
    }
    ///////////////
    cout<<"----------\n";
    ordena(v,n);
    for(int i=0;i<n;i++){
        strPrint(v[i]);
    }

    // char a[10];
    // char b[10];
    // cin>>a;
    // cin>>b;

    // cout<< strcpm(a,b)<<"\n";


    
    // limpeza
    for(int i=0; i<n;i++)
        delete[] v[i];
    delete[] v;
    
    return 0;
}