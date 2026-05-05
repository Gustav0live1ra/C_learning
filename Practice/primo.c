#include <stdio.h>

int main(){
    int n, cont=0;
    printf("digite um valor para verificar se ele e primo: ");
    scanf("%d", &n);

    for(int i = n; i > 0; i--){
        if(n % i == 0){
            cont+=1;
        }
    }

    if(cont == 2){
        printf("o numero %d e primo", n);
    }else{
        printf("o numero %d nao e primo", n);
    }
    return 0;
}