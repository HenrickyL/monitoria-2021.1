#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<char> f;
    //salva os 16 times
    for(char i='A'; i<='A'+15; i++){
        f.push(i);
    }

    //atrasves dos resultados faço ...
    while(f.size() != 1){
        char time1, time2;
        int gols1, gols2;  
        cin>> gols1 >> gols2;
        time1 = f.front();
        f.pop();
        time2 = f.front();
        f.pop();
        if(gols1 > gols2){
            f.push(time1);
        }else{
            f.push(time2);
        }
    }
    cout<<f.front()<<'\n';
}