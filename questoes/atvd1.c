#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selecao(int vet[], int n){
    int menor, aux;
    
    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            printf("C %d %d\n", menor, j);
            if(vet[menor] > vet[j]){
                menor = j;
            }
        }
        if(menor != i){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            printf("T %d %d\n", i, menor);

        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);

    }
}


void bolha(int vet[], int n){
    int aux, sent, led;
    sent = n -1;

    for(int cont = 0; cont<n; cont++){

        led=0;

        for(int i=0; i<sent; i++){
            /*if(vet[sent-2]==vet[sent-1]){
                sent--;
                break;
            }*/
            
            printf("C %d %d\n", i, i+1);
            if(vet[i]>vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                printf("T %d %d\n", i, i+1);
                led = i;
                
            } 
        }
        sent = led;


        /* if(led == 0){
            break;
        }
        else led = 1; */
        //sent--;
    }
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}


int main(){
    int n;

    char *tipo = calloc(128, sizeof(char));
    char sel[9] = "selecao\n";
    char bol[7] = "bolha\n";

    fgets(tipo, 128, stdin);
    scanf("%d", &n);

    int vet[n];

    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    
    }

    if(strcmp(tipo, sel) == 0){
        selecao(vet, n);
    }
    else{
        if(strcmp(tipo, bol)==0){
            bolha(vet, n);
        }
    }

    free(tipo);

    return 0;
}
