//busca
#include <iostream>
#include <iomanip>
using namespace std;

struct Aluno{
    int matricula;
    char *nome;
    float media; 
};


Aluno* criaAluno(){
    Aluno* a = new Aluno;
    cin>>a->matricula;
    a->nome = new char[100];
    cin.ignore();//limpa o buffer
    cin.get(a->nome, 100);
    cin>>a->media;

    return a;
}

void printAluno(Aluno* a){
    cout<<"\nNome: "<< a->nome<<"\n";
    cout<<"Matricula: "<< a->matricula<<"\n";
    cout<<"Media: "<< a->media<<"\n";
}

//função de busca 
int busca(Aluno** v,int n, int mat){
    for(int i=0; i<n; i++){
        Aluno* a = v[i];
        if( v[i]->matricula == mat ){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;//tamnho 
    cin>>n;  
    Aluno* v[n];//cria o vetor de alunos que armazena ponteiros
    //percorrer e salvar alunos 
    for(int i=0; i< n; i++){
        v[i] = criaAluno();
    }


    //faz a busca
    int matricula;
    // cout<<"buscar um aluno\n\tMatricula: ";
    cin>>matricula;
        //retornar o indice do aluno que busquei ou -1
    int res = busca(v,n,matricula);


    if(res>=0){
        printAluno(v[res]);
    }else{
        cout<<"NAO ENCONTRADA\n"; 
    }


    for(int i=0; i< n; i++){
        delete v[i]->nome;//deleto o char
        delete v[i];//deleto o ponteiro
    }

    return 0;
}

// cin.ignore();
// cin.get(turma[i].nome, 100);