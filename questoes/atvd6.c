#include <stdio.h>
#include <stdlib.h>

int shell(int v[], int n, int operacoes) {
    
    int copias=0;
    int comparacoes=0;

    int gap = 1;

    while(gap <= n) {

        gap *= 2;

    }

    gap = gap / 2 - 1;

    while(gap > 0) {

            for (int i = gap; i < n; i+=gap){

                int x = v[i];
                copias += 1;

                int j = i - gap;


                //condição para verificar curto circuito:
                if(j>=0){
                    comparacoes += 1;
                }
                while(j >= 0 && v[j] > x) {
                    
                    v[j + gap] = v[j];
                    copias += 1;

                    j -= gap;

                    //condição para verificar curto circuito:
                    if(j>=0){
                        comparacoes += 1;
                    }

                }

                v[j + gap] = x;
                copias+=1;

            }

        gap /= 2;
    }
    operacoes = operacoes + copias + comparacoes;

    return operacoes;
}

int quick(int v[], int f, int l) {
        
        int operacoes = 0;

        if (f >= l) {

                return operacoes;

        }

        int m = (l + f)/2;   //elemento do meio

        int pivot = v[m];   //definindo o pivot
        operacoes += 1;

        int i = f;  //começo

        int j = l;  //fim

        while(1) {

            operacoes += 1;
            while(v[i] < pivot) {
                i++;
                
                operacoes +=1;
            }

            operacoes += 1;
            while(v[j] > pivot) {
                j--;
                
                operacoes +=1;
            }

            if (i >= j) {

                break;

            }

            int aux = v[i];

            v[i] = v[j];
            v[j] = aux;

            operacoes += 3;   

            i++;
            j--;

        }

        operacoes = operacoes + quick(v, f, j);
        operacoes = operacoes + quick(v, j+1, l);

        return operacoes;
}


int main(){

    int Q;
    scanf("%d", &Q);   //tamanho do vetor
    
    int vetor[Q];
    for(int i=0; i<Q; i++){
        scanf("%d", &vetor[i]);    //le e coloca os valores dentro do vetor
    }

   
    for(int i=1; i<=Q; i++){

        int subvetor[i];
        for(int j=0; j<i; j++){ 
            subvetor[j] = vetor[j];         //subvetor para o quick
        }

        int subvetorcopia[i];
        for(int j=0; j<i; j++){
            subvetorcopia[j] = vetor[j];    //subvetor para o shell
        }

        int operacoesQ=0;   //contador de operações do Quick
        int operacoesS=0;   //contador de operações do Shell
        
        operacoesQ = quick(subvetor, 0, i-1);
        operacoesS = shell(subvetorcopia, i, operacoesS);

        
        //compara e printa o metodo que se saiu melhor:
        if(operacoesQ==operacoesS){
            printf("- ");
        }else{ 
            if(operacoesQ>operacoesS){ 
                printf("S ");
            }
            else{ 
                if(operacoesQ<operacoesS) printf("Q ");
            }
        }

        
        
    }


    return 0;
}