#include <stdio.h>

int main()
{
    int a,b;

    printf("digite os valores de a e b respectivamente: ");
    scanf("%d%d", &a, &b);

    if (a == b){
        printf("o valor %d eh igual ao valor %d \n", a, b);
    } else{
        if (a < b)
        {
            printf("o valor %d eh menor que o valor %d \n", a, b);
        }else{
            printf("o valor %d eh menor que o valor %d \n", b, a);
        }
        
    }
    return 0;
}
