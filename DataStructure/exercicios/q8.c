#include<stdio.h>

//1. maiorValor() retorna o endereço de uma variável local, assim que sair da função o endereço não guardará mais o valor de maior.
// O comportamento de retornar esse endereço "vazio" na main é indefinido.

//2. Na linha 4, o calculo do tamanho do array está errado, pois sizeof(v) vai retornar o tamanho de 'int *' e não o tamanho 
// total do array em bytes, pq o int v[] é convertido automaticamente para um ponteiro. Sendo assim, o calculo que ele
// está realmente fazendo é 8/4 (sizeof(int *)/ sizeof(int)) = 2.

//3. Na linha 6, na condição de parada do for está sendo feito i <= n, isso acessa o array até o ultimo indice + 1 (se n estivesse calculado corretamente),
// acessando um elemento fora do espaço de memória alocado para o array. O comportamento gerado é imprevisível.

//4. Na linha  16, o ponteiro p não está sendo declarado como NULL, significa que ele já inicia apontando pra alguma coisa,
//e isso pode gerar comportamentos indesejados.

int *maiorValor(int v[], int n, int *maior){
    *maior = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] > *maior){
            *maior = v[i];
        }
    }
    return maior;
}

int main(void){
    int v[5] = {12, 7, 30, 4, 18};
    int *p= NULL;
    int maior=0;
    // printf("%d\n", *p);  printar um ponteiro null resulta em segmentation fault
    printf("%d\n", *maiorValor(v, 5, &maior));
    return 0;
}