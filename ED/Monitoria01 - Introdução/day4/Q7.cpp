#include<iostream>
using namespace std;

int main(){
    int lim = 10;//capacidade
    char* s = new char[10];
    // int len=0; // tamanho atual
    char aux=' ';

    char *novo;
    for(int i=0; aux != '\n'; i++){
        //so posso inserir se couber
        aux = std::getchar();
        if( i <= lim){
            s[i]=aux;

        }else{
            cout<<"*";
        //ajustar o tamanho
            lim+=10;
            //cria um novo vetor Maior
            novo = new char[i+10];
            //copia os elementos
            for(int j=0;j<i; j++){
                novo[j] = s[j];
            }
            //adicionamos o novo
            novo[i] = aux;
            //deletamos o antigo
            delete[] s;
            s = novo;
            novo=nullptr;
        }
    }

    cout<<"\n-----------------------\n";
    for(int i=0; s[i] ; i++)
        cout<<s[i];
    cout<<"\n";
    delete[] s;
}