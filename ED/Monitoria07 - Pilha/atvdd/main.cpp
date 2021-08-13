#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};
void show(vector<string>& mat){
     for(string line : mat)
        cout << line << endl;
    getchar();
}
//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool buscar(vector<string>& mat, Pos inicio, Pos dest){
    stack<Pos> p;
    stack<Pos> c;

    p.push(inicio);
    c.push(inicio);

    while(!p.empty()){
        Pos atual = p.top();
        p.pop();
        if(atual.l == dest.l && atual.c == dest.c){
            return true;
        }else{
            mat[atual.l][atual.c]='.';
            show(mat);
            for(auto viz : get_vizinhos(atual)){
              if(mat[viz.l][viz.c]==' '){
                  p.push(viz);
              }  
            }
        }

    }
    return false;
     

}
// bool buscar(vector<string>& mat, Pos atual, Pos dest){
//     if(atual.l == dest.l && atual.c == dest.c){
//         return true;
//     }else //não poder andar
//         if(mat[atual.l][atual.c]!=' '){
//             return false;
//     }else{
//         //posso andar
//         mat[atual.l][atual.c]='.';
//         show(mat);
//         for(auto viz : get_vizinhos(atual)){
//            if( buscar(mat,viz,dest)){
//                return true;
//            }
//         }
//         mat[atual.l][atual.c]='x';
//         show(mat);
//         return false;
//     }
// }



int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }

    buscar(mat,inicio, fim);

    show(mat);
    for(string line : mat)
        cout << line << endl;
    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
}