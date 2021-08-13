#include "LList.h"


void LList::removeAll(const int& x) { //Removendo errado??? 
    Node *auxiliar = head;
    atual = auxiliar;

    while(auxiliar != nullptr){
        

        if(atual->next->key == x){
            auxiliar = auxiliar->next;

            int lixo = remove();      
        }else{
            atual = atual->next;
            auxiliar = atual->next;

        }
        
        
    }
}