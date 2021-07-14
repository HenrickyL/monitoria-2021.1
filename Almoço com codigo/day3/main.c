#include <stdio.h>

//Jogardor -> 2pedras >= 10m && distancia



int main(){
    int n=0;
    //-1 não tem ganhador
    int ganhador=-1;
    int distGanhador=-1;
    int arrem1=0;
    int arrem2=0;
    int distancia = 0;
    scanf("%d",&n);
    //percorrer as informações
    for(int i=0;i<n; i++){
        scanf("%d %d",&arrem1, &arrem2);
        
        //verificar se foi classificado:
        if(arrem1>=10 && arrem2>=10){
            distancia = arrem2 - arrem1;
            //ajuste de sinal
            if(distancia<0){
                distancia = -distancia;
            }
            
            //definir um ganhador
            if(ganhador==-1){
                ganhador = i;
                distGanhador = distancia;
            }else{ //faz a comparação
                //verificar as distancias
                if(distGanhador > distancia){
                    ganhador=i;
                    distGanhador= distancia;
                }
            }   
        }
    }


    //verificar se houve ganhador
    if(ganhador>=0){
        printf("%d\n", ganhador);
    }else{
        printf("sem ganhador\n");
    }

    return 0;
}