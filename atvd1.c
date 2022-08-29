#include <stdio.h>
#include <string.h>

void selecao(int vet[], int n){
    int menor, aux;
    printf("\n");
    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            printf("C %d %d\n", menor, j);
            if(vet[i] > vet[j]){
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
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);

    }
}


void bolha(int vet[], int n){
    int cont, aux, sent;
    sent = n;
    printf("\n");

    for(cont = 0; cont<n-1; cont++){
        for(int i=0; i<sent-1; i++){
            printf("C %d %d\n", i, i+1);
            if(vet[i]>vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                printf("T %d %d\n", i, i+1);
            }
           
        }
        sent--;
        
    }

    printf("\n");
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

    return 0;
}
