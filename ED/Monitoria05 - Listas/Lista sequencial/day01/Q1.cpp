#include<iostream>
#include<vector>
using namespace std;


bool strequal(char* a, char* b){
    for(int i=0; a[i] || b[i]; i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}



void matchingStrings(char** consultas, int n1, char** buscas, int n2){
    for(int i=0; i<n2; i++){
        int resI = 0;
        for(int j=0; j<n1; j++){
            if( strequal(buscas[i], consultas[j]) ){
                resI++;
            }
        }
        cout<<resI<<' ';
    }
    cout<<'\n';
}

void recebe(char** v,int n){
    for(int i=0; i<n; i++){
        char* aux = new char[20];
        cin>>aux;
        v[i]=aux;
    }
}
void printStr(char** v,int n){
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}
void deletar(char** v, int n){
    for(int i=0; i<n; i++)
        delete[] v[i];
    delete[] v;
}

int main(){
    int n1;
    cin>>n1;
    char** consultas =  new char*[n1];
    recebe(consultas,n1);
    printStr(consultas,n1);
    
    int n2;
    cin>>n2;
    char** buscas =  new char*[n2];
    recebe(buscas,n2);
    printStr(buscas,n2);
 
    matchingStrings(consultas,n1,buscas,n2);

    deletar(consultas,n1);
    deletar(buscas,n2);


    return 0;
}