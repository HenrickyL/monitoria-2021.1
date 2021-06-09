#include<iostream>
using namespace std;

int strcmp(char *str1, char *str2){
    for(int i=0; str1[i] && str2[i] ; i++){
        if(str1[i] > str2[i])
            return 1;
        else if(str1[i] < str2[i])
            return -1;
    }
    return 0;
}

int strLen(char* s){
    int size=0;
    for(int i=0; s[i]!='\0' ; i++){
        size++;
    }
    return size;
}

/*

    abacaxi
    abacate


*/


int main(){
    char s1[25],s2[25];
    cin>>s1;
    cin>>s2;

    cout<<"S1: "<<s1<<  '\n';
    cout<<"S2: "<<s2<<  '\n';

    cout<<"\nres: "<< strcmp(s1,s2)<<"\n";



    
}