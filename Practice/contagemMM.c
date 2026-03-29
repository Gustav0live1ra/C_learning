#include<stdio.h>

int main(){
    int a = 1, maior = 0, menor = 10000000;

    while( a != 0 ){
        printf("digite um valor(digite 0 para parar): ");
        scanf("%d", &a);

        if( a != 0 ){
            if(a > maior){
                maior = a;
            }else if (a < menor){
                menor = a;
            }
            
        }
    }
    printf("o maior e menor valor digitados foram %d e %d", maior, menor);
    return 0;
}