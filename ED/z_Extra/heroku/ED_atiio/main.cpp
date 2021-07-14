#include<iostream>
#include<vector>
using namespace std;


void printVec(vector<int> v, int killer=-1){
    cout<<"[ ";
    if(killer==-1){
        for(int i=0;i<v.size(); i++){
            cout<<v.at(i)<<"-";
        }
    }else{
        for(int i=0;i<v.size(); i++){
            if(i==killer)
                cout<<v.at(i)<<"> ";

            else   
                cout<<v.at(i)<<" ";
        }
    }
    cout<<"]\n";
}


int main(){
    int n;
    cin>>n;
    int killer;
    cin>>killer;
    killer--;

    vector<int> v;
//criar o vetor
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

    while(v.size()>0){
        killer = killer % v.size();
        
        
        printVec(v,killer);
        if(killer==v.size()-1){
            v.erase( v.begin()+0);
            killer = 0;

        }else{
            v.erase( v.begin()+killer+1);
            killer++;
        }
       

        
    }
    




}