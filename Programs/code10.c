#include<stdio.h>

int main()
{   int n, cont = 0;
    printf("digite um número qualquer: ");
    scanf("%d",&n);
    do {
        if (n < 0){
            n = -n;
        }
        n /= 10;
        ++cont;

    }while (n > 0);
    printf("o número de digitos desse número é: %d ",cont);    
    return 0;
}
