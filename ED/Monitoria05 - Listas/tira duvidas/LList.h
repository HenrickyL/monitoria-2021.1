#ifndef LLIST_H
#define LLIST_H
#include <iostream>
#include <cassert>

struct Node {
    int key;
    Node *next;

    // Construtor do struct Node
    // Obs.: Em C++ os structs tambem podem ter construtores,
    // destrutores ou quaisquer outras funcoes que voce quiser.
    Node(const int& k, Node *nextval) {
        key = k;
        next = nextval;
    }
};

class LList {
private:
    Node *head;     // Ponteiro para a cabeca da lista
    Node *tail;     // Ponteiro para o ultimo elemento da lista
    Node *atual;    // Ponteiro para o elemento atual
    int size;       // Tamanho da lista

    // Funcao auxiliar de inicializacao dos 
    // atributos privados
    void init();

    // Libera todos os nos alocados, inclusive o no cabeca
    void removeAll();
    Node* auxReverse(Node* no);
    
public:
    LList(); // Construtor
    
    ~LList(); // Destrutor

    // Deixa a lista vazia, com zero elementos
    void clear();
    void print();
    void printReverse();


    // Insere um elemento na posicao atual
    // item: o elemento a ser inserido
    void insert(const int& item);

    // adiciona um elemento ao final da lista
    // item: o elemento a ser inserido
    void append(const int& item);

    // Remove o elemento atual e devolve o seu valor
    int remove();

    // Remove sempre o ultimo elemento da lista 
    // e devolve o seu valor
    // Apos essa operacao, o ponteiro 'atual' pode acabar
    // apontando para qualquer posicao valida da lista
    int remove_back();

    // Configura a posicao atual para o inicio da lista
    void moveToStart();

    // Configura a posicao atual para o final da lista
    void moveToEnd();

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
    void moveToPos(int newpos);

    // Devolve o elemento atual
    int getValue() const;

    // Devolve true se cheia e false caso contrario
    bool empty() const;

    // operador[] sobrecarregado
    // devolve uma referencia para o elemento na posicao i da lista
    int& operator[](const int& index);

    // Devolve 'true' se a posicao atual estiver no ultimo elemento
    // e devolve 'false' caso contrario. Operacao O(1)
    bool inTheEnd();

    // remove da lista todas as ocorrencias do inteiro x
    // Restricao: Esta funcao deve ter complexidade O(n) no pior caso
    // Obs.: Apos a execucao dessa funcao, o ponteiro 'atual' pode terminar
    // apontando para qualquer node da lista resultante.
    void removeAll(const int& x);

    // Devolve um ponteiro para uma copia desta lista
    // Esta funcao deve ter complexidade O(n) no pior caso
    LList *copy();

    // Copia os elementos do array v[0..n-1] para o final da lista. 
    // Esta funcao deve ter complexidade O(n) no pior caso 
    void appendArray(int v[], int n);

    // Determina se a lista lst, passada por parametro, eh igual 
    // a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho 
    // e o valor do k-esimo elemento da primeira lista eh igual ao k-esimo valor da segunda lista.
    bool equal(const LList& lst);

    // Inverte a ordem dos nos (o primeiro no passa a ser o ultimo, 
    // o segundo passa a ser o penultimo, etc.) 
    // Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
    // Voce pode criar ponteiros auxiliares, mas nao pode alocar novos nodes.
    void reverse();
};


/************************************
 * Implementacao da classe LList
 ************************************/
void LList::init() {       
    atual = tail = head = new Node(0, nullptr); // alocacao do no cabeca
    size = 0;
}

void LList::removeAll() {  
    while(head != nullptr) {
        atual = head;
        head = head->next;
        delete atual;
    }
    tail = atual = nullptr;
}

LList::LList() { 
    init();
}

LList::~LList() { 
    removeAll();
}

void LList::clear() {
    removeAll();
    init();
}

void LList::insert(const int& item) {
    atual->next = new Node(item, atual->next);
    if(tail == atual)
        tail = atual->next;
    size++;
}

void LList::append(const int& item) {
    tail->next = new Node(item, nullptr);
    tail = tail->next;
    size++;
}

int LList::remove() {
    assert(atual->next != nullptr);
    int value = atual->next->key;
    Node *temp = atual->next;
    if(tail == atual->next)
        tail = atual;
    atual->next = atual->next->next;
    delete temp;
    size--;
    return value;
}

int LList::remove_back() {
    assert(tail != head);
    int value = tail->key;
    for(atual = head; atual->next != tail; atual = atual->next);
    delete tail;
    tail = atual;
    tail->next = nullptr;
    size--;
    return value;
}

void LList::moveToStart() {
    atual = head;
}

void LList::moveToEnd() {
    atual = tail;
}

void LList::prev() {
    if(atual != head) {
        Node *temp = head;
        while(temp->next != atual) 
            temp = temp->next;
        atual = temp;
    }
}

void LList::next() {
    if(atual != tail) 
        atual = atual->next;
}

int LList::length() const {
    return size;
}

int LList::posAtual() const {
    int i = 0;
    Node *temp = head;
    while(atual != temp) {
        temp = temp->next;
        i++;
    }
    return i;
}

void LList::moveToPos(int newpos) {
    assert(newpos >= 0 && newpos <= size);
    atual = head;
    for(int i = 0; i < newpos; i++) 
        atual = atual->next;
}

int LList::getValue() const {
    assert(atual->next != nullptr);
    return atual->next->key;
}

bool LList::empty() const {
    return head == tail;
}

int& LList::operator[](const int& index) {
    assert(index >= 0 && index < size);
    Node *temp = head;
    for(int j = 0; j < index; j++) 
        temp = temp->next;
    return temp->next->key;
}

bool LList::inTheEnd() {
    return atual == tail;
}



// remove da lista todas as ocorrencias do inteiro x
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso
// Obs.: Apos a execucao dessa funcao, o ponteiro 'atual' pode terminar
// apontando para qualquer node da lista resultante.
void LList::removeAll(const int& x) {
//    Node *auxiliar = head;
    atual = head;

    while(atual->next != nullptr){
        // auxiliar = auxiliar->next;

        if(atual->next->key == x){
            // auxiliar = auxiliar->next;

            int lixo = remove();      
        }else{
            atual = atual->next;
            // auxiliar = atual->next;

        }
        
         
    }
}


// Devolve um ponteiro para uma copia desta lista
// Esta funcao deve ter complexidade O(n) no pior caso
LList *LList::copy() {
    // TODO
}


// Copia os elementos do array v[0..n-1] para o final da lista. 
// Esta funcao deve ter complexidade O(n) no pior caso
void LList::appendArray(int v[], int n) {
     for(int i=0; i < n; i++){
        append(v[i]);
    } 
}


// Determina se a lista lst, passada por parametro, eh igual 
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho 
// e o valor do k-esimo elemento da primeira lista eh igual ao k-esimo valor da segunda lista.
bool LList::equal(const LList& lst) {
    // TODO
}



// Inverte a ordem dos nos (o primeiro no passa a ser o ultimo, 
// o segundo passa a ser o penultimo, etc.) 
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares, mas nao pode alocar novos nodes.

Node* LList::auxReverse(Node* no){
    Node* aux;
    //caso base:
    if(no->next->next == nullptr){ //achar o penultimo
       atual = no->next;
       return no->next;
    }
    //chamada da recursão
    else{
        Node* k =auxReverse(no->next);
        
        aux = no->next;
        std::cout <<"atual: "<<no->key<<" k:" << k->key<<" aux:"<<aux->key<<"\n";
        k->next = aux;
        return aux;
        
    }
}

void LList::reverse() {
    std::cout <<"revertendo...\n";
    Node* last=auxReverse(head);    
    head->next = atual;
    last->next = nullptr;
    std::cout <<"revertido\n";

    // atual=head;
}


void auxPrint(Node* no){
    //caso base
    //chamada da recursão
    if(no!= nullptr){
        std::cout<<no->key<<" ";
        auxPrint(no->next);
    }
}

void LList::print(){
    // auxPrint(head->next);
    Node* aux = head->next;
    while(aux != nullptr){
        std::cout<<aux->key<<" ";
        aux = aux->next;
    }
    std::cout<<'\n';
}




#endif

