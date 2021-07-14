#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


void show(string s){
    cout<<s<<"\n";
    getchar();
}




bool preencher(string& s, int prox, int& lim, int index=0){
    if(index == line.size()){
        return true;
    }else if(line[index]!='.'){
        return preencher(line, prox, lim, index+1);
    }else{
        
    }
}


int main(){
    ifstream arq("input.txt");
    string line;
    int prox;
    arq>> line >> prox;
    lim = 1; //0,1
    //tirar vazios
    preencher(line,prox, lim);


    



   

    return 0;
}