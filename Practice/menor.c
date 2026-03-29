#include<stdio.h>

int main(void)
{
    int n1,n2;

    printf("digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("digite o segundo numero: ");
    scanf("%d", &n2);

    if (n1 < n2){
        printf("%d e menor que %d", n1, n2);
    }

    if (n2 < n1){
        printf("%d e menor que %d", n2, n1);
    }

    else if (n1 == n2){
        printf("os valores digitados sao iguais.");
    }
    return 0;
}
