#include <stdio.h>
#include <stdlib.h>

//para n = 100, ele chamaria malloc 1 vez pra alocar os ponteiros no vetor e depois chamaria malloc para a linha de cada ponteiro
//resultando em 101 chamadas de malloc. Normalmente, o programa executa n+1 chamadas de free, 101 também, porque desaloca linha por linha e dps o vetor

//não seria possível descobrir o tamanho do vetor sem passa-lo como parâmetro. Se usarmos sizeof por exemplo, 
//ele não pegaria a quantidade de bytes total do vetor, mas sim a quantidade de bytes do tipo do valor,
// se fazemos sizeof(m) ele vai dar 8 pq m é um ponteiro para ponteiros, se fazemos sizeof(*m) também da 8 pq tbm é um ponteiro, e se fazemos sizeof(**m) acessamos um valor int e ele retorna o tam de int que é 4.

int **criarMatriz(int lin, int col){
    if(lin == 0 || col == 0) return NULL;
    int **matriz = malloc(lin * sizeof(int  *));  //vetor de ponteiros, um ponteiro para cada linha
    
    for (int i = 0; i < lin; i++){
        matriz[i] = malloc(col * sizeof(int)); 
        if( matriz[i] == NULL) {
            for (int j = 0; j < i; j++){
                free(matriz[j]);
            }
            return NULL;
        }
    }
    return matriz;
    
}

void destruirMatriz(int **m, int lin){
    for (int i = 0; i < lin; i++){
        free(m[i]);
    }
}

long somaDiagonal(int **m, int n){
    long soma = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j){
                soma += m[i][j];
            }
        }
    }
    return soma;
}

int main(void){
    int n;
    scanf("%d", &n);

    int **m = criarMatriz(n,n);
    if(m == NULL) return 1;

    for (int i = 0; i < n; i++){
        for(int j=0; j < n; j++){
            m[i][j] = i * n + j;
        }
    }

    printf("A soma dos elementos da diagonal principal eh: %ld", somaDiagonal(m, n));
    destruirMatriz(m,n);
    free(m);
    m = NULL;
    
    return 0;
}  