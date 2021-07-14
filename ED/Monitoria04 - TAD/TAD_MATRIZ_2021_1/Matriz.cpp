// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Matriz.h"

// Aloca espaco para matriz n por m
Matriz::Matriz(int n, int m) {
	this->_c = m;
	this->_l = n;
	//alocar as matriz
	_M = new int*[n];
	for(int i=0; i<_l; i++){
		_M[i] = new int[m];
	}
}   

// Destrutor: Libera a memoria da matriz
Matriz::~Matriz() {
	for(int i=0; i<_l; i++)
		delete[] _M[i];
	delete[] _M;
}     

// Retorna o valor do elemento [i][j]
int Matriz::valor(int i, int j) {
	return _M[i][j];
} 

// Atribui valor ao elemento [i][j]
void Matriz::atribui(int valor, int i, int j) {
	_M[i][j] = valor;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
// TODO
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
// TODO
}

// Imprime matriz --- Ja esta codificado 
void Matriz::imprime(int largura) {
	for (int linha = 0; linha < _l; linha++) {
		for (int coluna = 0; coluna < _c; coluna++) {
			std::cout << std::setw(largura) << _M[linha][coluna];
		}
		std::cout << std::endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz *B) {
	int lin, col;
	//verificação da maior linha e maior coluna
	lin = (this->_l > B->_l) ? this->_l :  B->_l;
	col = (this->_c > B->_c) ? this->_c :  B->_c;
	std::cout<<"\n\nL: "<<lin <<" - Col:" << col <<"\n";
	//criar uma nova matriz para retornar

	Matriz* C = new Matriz(lin,col);

	int MA, MB;
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			if(i < this->_l && i < B->_l  && j < this->_c && j < B->_c )
				C->_M[i][j] = this->_M[i][j] + B->_M[i][j];
			else if(i < this->_l && j < this->_c)
				C->_M[i][j] = this->_M[i][j]  + 0;
			else if(i < B->_l && j < B->_c)
				C->_M[i][j] = 0 + B->_M[i][j];		
		}
	}
	return C;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz *B) {
	//verificar a validade
	if(this->_l == B->_c && this->_c == B->_l){
		int lin, col;
		//verificação da maior linha e maior coluna
		lin = (this->_l > B->_l) ? this->_l :  B->_l;
		col = (this->_c > B->_c) ? this->_c :  B->_c;
		//criar uma nova matriz para retornar
		Matriz* C = new Matriz(lin,col);
		int soma;

		//verificar o menor entre linha e coluna
		int aux = this->_l < this->_c ? this->_l : this->_c;


		//fazer a operação
		for(int i=0; i<lin; i++){
			for(int j=0; j<col; j++){
				 soma= 0;
				 for(int k =0; k<aux; k++){
					 std::cout<<this->_M[i][k]<<"*"<<B->_M[k][j]<<" +";
					 soma += this->_M[i][k]*B->_M[k][j];
				 }
				 std::cout <<'\t';
				
				
				C->_M[i][j]=soma;
			}
			std::cout<<"\n";
		}
		return C;


	}else{
		return nullptr;
	}



	
}
