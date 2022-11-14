#include <stdio.h>
#include <stdlib.h>


void insertion(int vet[], int n){
    int T=0, C=0,cont=1;
    for(int p = 1; p < n; p++){
        int x = vet[p];
        T++;
        int i = p-1;
        
        while(i >= 0 && x < vet[i]){
            cont++;
            vet[i+1] = vet[i];
            T++;
            i--;
            if(i<0) cont--;
            
        }

        C=C+cont;
        cont=1;
        vet[i+1] = x;
        T++;
        
    }
    
    printf("I %d %d %d\n", n, T, C);
}




void merge2(int vet[], int c, int f, int vet2[], int vet3[]){
    
    // Caso base: 
    if (c >= f) {
        // ou o vetor é de tamanho 0 ou de
        // tamanho 1, ou seja, já está ordenado
        return;   
    }

    // Cálculo da posição central do vetor:
    int m = (c + f) / 2;

    // Chamadas recursivas para as 2 metades:
    merge2(vet, c, m, vet2, vet3);
    merge2(vet, m + 1, f, vet2, vet3);

    // Inicialização dos apontadores para os vetores 
    // da esquerda e da direita, sabendo que o primeiro vetor
    // vai de c à m e que o segundo vetor de m + 1 à f:
    int i1 = c;
    int i2 = m + 1; 
    int j = 0;

    // Junção ordenada e estável dos 2 vetores:
   
    while (i1 <= m && i2 <= f) {
        vet3[1] = vet3[1] + 1;
        
        if (vet[i1] <= vet[i2]) {
            
            vet2[j] = vet[i1];
            vet3[0] = vet3[0] + 1;
            i1++;
        }
        else {
            
            vet2[j] = vet[i2];
            vet3[0] = vet3[0] + 1;
            i2++;
        }
        j++;
        /* if(i1>m){
            vet3[1] = vet3[1] - 1;
            
        } */
    }
    


    // Junção dos elementos restantes do primeiro
    // vetor (se ele não tiver terminado):
    while (i1 <= m) {
        //vet3[1] = vet3[1] + 1;
        vet2[j] = vet[i1];
        vet3[0] = vet3[0] + 1;
        i1++;
        j++;
        
    }

    // Junção dos elementos restantes do segundo
    // vetor (se ele não tiver terminado):
    while (i2 <= f) {
        
        vet2[j] = vet[i2];
        vet3[0] = vet3[0] + 1;
        i2++;
        j++;
        
    }

    // Cópia dos elementos ordenados de b para a:
    j = 0;
    for(int i = c; i <= f; i++) {
        
        vet[i] = vet2[j];
        vet3[0] = vet3[0] + 1;
        j++;
        
    }
    
}

void merge(int vet[], int n){
    int *vet3 = (int *) calloc(2, sizeof(int));
    // Alocação de memória extra para o vetor auxiliar b:
    int *vet2 = (int *) malloc (sizeof(int) * n);

    // Chamada inical da recursão:
    merge2(vet, 0, n-1, vet2, vet3);
    printf("M %d %d %d\n", n, vet3[0], vet3[1]);
    // Liberação de memória extra alocada para b:
    free(vet2);
    free(vet3);

}


int main(){
    int Q;
    scanf("%d", &Q); //quantidade de vetores
    int tam_vets[Q]; //vetor que guarda o numero de posições de cada vetor
    for(int i=0; i<Q; i++){
        scanf("%d", &tam_vets[i]);
    }

    for(int i=0; i<Q; i++){
        int vet[tam_vets[i]];
        for(int j=0; j<tam_vets[i]; j++){
            scanf("%d", &vet[j]);
        }
        int vet_cop[tam_vets[i]];
        for(int h=0;h<tam_vets[i]; h++){
            vet_cop[h] = vet[h];
        }
        /* for(int k=0; k<tam_vets[i];k++){
            printf("%d ", vet_cop[k]);
        } */
        insertion(vet, tam_vets[i]);
        merge(vet_cop, tam_vets[i]);
        
    }


    return 0;
}
