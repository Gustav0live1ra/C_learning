#include<stdio.h>

// como o tipo primitivo int ocupa 4 bytes na memória, o ponteiro desloca 4 bytes a cada p++
// se fosse double o ponteiro deslocaria 8 bytes.

int somaVetor(int *p, int n){
    int sum=0;
    for (int i = 0; i < n; i++){
        sum += *p;
        p++;
    }
    return sum;
}

int main(void){
    int array[5] = {12,7,30,4,18};
    int *v = array;

    int soma = somaVetor(v, 5);
    printf("%d", soma);
}