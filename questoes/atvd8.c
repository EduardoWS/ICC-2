//NOME: EDUARDO RIBEIRO RODRIGUES     NUSP: 13696679


#include <stdio.h>

void quick(int v[], int f, int l) {

        if (f >= l) {

                return;

        }

        int m = (l + f)/2;

        int pivot = v[m];

        int i = f;

        int j = l;

        while(1) {

                while(v[i] < pivot) {

                        i++;

                }

                while(v[j] > pivot) {

                        j--;

                }

                if (i >= j) {

                        break;

                }

                int aux = v[i];

                v[i] = v[j];

                v[j] = aux;

                i++;

                j--;

        }

        quick(v, f, j);
        quick(v, j+1, l);
}

//BUSCA BINARIA RECURSIVA:
int recursive_binary_search(int vector[], int begin, int end, int item)
{
    int i = (begin + end) / 2;

    if (begin > end) {
        return -1;
    }

    if (vector[i] == item) {
        return i;
    }

    if (vector[i] < item) {
        return recursive_binary_search(vector, i + 1, end, item);

    } else {  // vector[i] > item
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}



int main(){
    
    int N;
    scanf("%d", &N);
    int vet[N];

    for(int i=0; i<N; i++){
        scanf("%d", &vet[i]);
    }

    quick(vet, 0, N-1);

    int K;
    scanf("%d", &K);
    int vet2[K];

    for(int i=0; i<K; i++){
        scanf("%d", &vet2[i]);
    }

  
    int valor;

    for(int i=0; i<K; i++){
        valor = recursive_binary_search(vet, 0, N-1, vet2[i]);
        if(valor == -1){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    




    //BUSCA SEQUENCIAL:

    /* int led;
    for(int i=0; i<K; i++){
        led = 0;
        for(int j=0; j<N; j++){
            if(vet2[i] == vet[j]){
                led = 1;
            }
        }
        if(led == 1){
            printf("1\n");
        }
        else{
            printf("0\n");
        }

    } */



    return 0;
}