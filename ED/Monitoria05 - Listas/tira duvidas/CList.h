/*
 * Lista Simplesmente Encadeada Circular com Node Cabeca Auxiliar
 * Esta lista contem apenas dois ponteiros auxilixares: head e atual.
 * Nesta implementacao, como usual, o ponteiro 'atual' aponta para o node 
 * anterior ao node da posicao atual.
 * Lembre-se que as posicoes na nossa lista variam de 0 a n-1.
 */
#ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include <cassert>

struct Node {
    int key;
    Node *next;

    Node(const int& k, Node *nextval) {
        key = k;
        next = nextval;
    }
};

class CList {
private:
    Node* head;     // Ponteiro para o primeiro elemento da lista
    Node *atual;    // Ponteiro para a posicao atual (aponta para o elemento anterior ao atual)
    int size;       // Tamanho da lista

    // Funcao auxiliar de inicializacao
    void init();

    // Libera todos os nos alocados, inclusive o node cabeca auxiliar
    void removeAll();
    
public:
    // Construtor
    CList();

    // Destrutor
    ~CList();

    // Deixa a lista vazia, com zero elementos
    void clear();

    // adiciona um elemento ao final da lista
    // item: o elemento int a ser inserido
    void append(const int& item);

    // Insere um elemento na posicao atual
    // Observe que a posicao atual nao muda apos inserir
    // item: o elemento a ser inserido
    void insert(const int& item);

    // Remove sempre o ultimo elemento da lista e devolve seu valor
    // Obs.: Apos executar essa funcao, o ponteiro atual passa
    // a apontar para o inicio da lista (head)
    // Um elemento so pode ser removido se a lista nao estiver vazia
    // Se a lista estiver vazia na ocasiao da chamada desta funcao, entao um erro deve ser gerado
    int remove_back();

    // Remove o elemento na posicao atual e devolve o seu valor
    // Um elemento so pode ser removido se a lista nao estiver vazia
    // Se a lista estiver vazia na ocasiao da chamada desta funcao, entao um erro deve ser gerado
    // Outra ocasiao de erro eh remover um elemento na posicao n
    int remove();
    
    // Configura a posicao atual para o inicio da lista (head)
    void moveToStart();

    // Configura a posicao atual para o final da lista
    void moveToEnd();

    // devolve 'true' a posicao atual estiver no final da lista e
    // 'false' caso contrario 
    // Funcao de complexidade constante O(1)
    bool inTheEnd();

    // Move a posicao atual uma posicao para tras.
    // Nada acontece se a posicao ja estiver no inicio da lista
    void prev();

    // Move a posicao atual uma posicao a frente.
    // Nada acontece se a posicao ja estiver no final da lista
    void next();

    // Devolve o numero de elementos da lista
    int length() const;

    // Devolve a posicao do elemento atual
    int posAtual() const;

    // Configura a posicao atual
    // Move o ponteiro atual para a posicao 'index'
    // Se o 'index' nao estiver em uma posicao valida, um erro eh gerado
    // posicoes validas para mover estao entre 0 e n neste caso
    void moveToPos(int index);
    
    // Devolve o valor do elemento na posicao atual
    // Se a posicao atual for igual a 'size', entao um erro deve ser gerado,
    // ja que nao existe elemento nessa posicao
    int& getValue() const;

    // Devolve true se cheia e false caso contrario
    bool empty() const;
};

CList::CList() {
    head = new Node(0, head);
    atual = head;
    size = 0;
}

CList::~CList() {
    
    atual = head->next;
    while(atual->next != head) {
        Node *aux = atual;
        atual = atual->next;
        delete aux;
    }
    delete atual;
    delete head;
    size = 0;
}

void CList::clear() {
    this->~CList();
    atual = head = new Node(0, head);
}

void CList::append(const int& item) {
    std::cout<<"Append "<<item<<"!\n";

    Node *novo = new Node(item, head);
    atual = head;
    //movendo para o ultimo
    while(atual->next != head)
        atual = atual->next;
    std::cout<<"rodou!\n";
    atual->next = novo;
    atual = head;
    size++;

}

void CList::insert(const int& item) {
    atual->next = new Node(item, atual->next);
    size++;
}

int CList::remove_back() {
    assert(head != head->next);
    while(atual->next->next != head)
        atual = atual->next;
    int num = atual->next->key;
    Node *lixo = atual->next;
    atual->next = atual->next->next;
    delete lixo;
    size--;
    atual = head;
    return num;
}

int CList::remove() {
    //assert(head != head->next);
    assert(atual->next != head);
    int num = atual->next->key;
    Node *lixo = atual->next;
    atual->next = atual->next->next;
    delete lixo;
    size--;
    return num;
}

void CList::moveToStart() {
    atual = head;
}

void CList::moveToEnd() {
    while(atual->next != head)
        atual = atual->next;
}

bool CList::inTheEnd() {
    return atual->next == head;
}

void CList::prev() {
    if(head != atual) {
        Node *temp = head;
        while(temp->next != atual) 
            temp = temp->next;
        atual = temp;
    }
}

void CList::next() {
    if(atual->next != head) {
        atual = atual->next;
    }    
}

int CList::length() const {
    return size;
}

int CList::posAtual() const {
    int i = 0;
    Node *temp = head;
    while(atual != temp) {
        temp = temp->next;
        i++;
    }
    return i;
}

void CList::moveToPos(int index) {
    assert(index >= 0 && index <= size);
    atual = head;
    for(int i = 0; i < index; i++) 
        atual = atual->next;
}

int& CList::getValue() const {
    assert(atual->next != head);
    return atual->next->key;
}

bool CList::empty() const {
    return head == head->next;
}

#endif