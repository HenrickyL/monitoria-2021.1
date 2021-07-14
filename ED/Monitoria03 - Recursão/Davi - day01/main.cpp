#include <iostream>
#include <vector>
using namespace std;

int count(string value, vector<string> &vet) {
    int cont = 0;
    for (string elem : vet)
        if(elem == value)
            cont++;
    return cont;
}

int main() {
    int size = 0;
    cin>>size;
    vector<string> info(size, 0);
    for(int i = 0; i < size; i++)
        cin >> info[i];

    int size_consulta;
    vector<string> consultas(size_consulta);
    for(int i = 0; i < size_consulta; i++)
        cin >> consultas[i];
    

    for(string value : consultas)
        cout << count(value, info) << " ";
}