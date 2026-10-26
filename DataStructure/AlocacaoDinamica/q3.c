#include <stdio.h>
#include <stdlib.h>

//fazer v = realloc(v * sizeof(int)), caso o pedido falhe vai retornar NULL, e vai atribuir NULL ao ponteiro v.
//o bloco de memória do vetor vai continuar existindo mas não vamos ter mais a referencia para ele, ou seja, não 
//conseguiriamos nem dar free e nem acessar mais o bloco de memória do array. Vazamento de memória.

//No programa atual, para ler 1000 valores, o realloc seria chamado 10 vezes, que daria cerca de 1000 cópias.
// Se a capacidade crescesse de 1 em 1, o realloc seria chamado 999 vezes e isso resultaria em cerca de 500 mil cópias.


int verificaCapacidade(int capacidade, int cont){
    if(cont == capacidade) return 1;
    return 0;
}

void dobraCapacidade(int **vetor, int *cap){
    *cap *= 2;
    int *dobroVetor = realloc(*vetor, *cap * sizeof(int));
    if (dobroVetor == NULL) {
        free(*vetor);
        exit(1);
    }
    *vetor = dobroVetor;
}

int main(){
    int n;
    int cap = 2; //capacidade
    int contador=0, contaRealloc=0, soma=0;
    int *vetor = malloc(cap * sizeof(int));
    if(vetor == NULL) return 1;

    while(1){
        scanf("%d", &n);
        if(n == -1) break;
        vetor[contador] = n;
        soma += n;
        contador++;
        if(verificaCapacidade(cap,contador)){
            dobraCapacidade(&vetor, &cap);
            contaRealloc++;
        }
    }
    printf("tam %d cap %d reallocs %d soma %d", contador, cap, contaRealloc, soma);

    
}