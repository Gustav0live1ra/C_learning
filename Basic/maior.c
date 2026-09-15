#include <stdio.h>

int main()
{
    int a, b, c;

    printf("digite 3 valores: ");
    scanf("%d%d%d", &a,&b,&c);

    if (a > b){
        if (a > c)
        {
            printf("%d e o maior valor", a);
        }else{
            printf("%d e o maior valor", c);
        }
    }
    else{
        if (b > c){
            printf("%d e o maior valor", b);
        }else{
            printf("%d e o maior valor", c);
        }
    }
    return 0;
}
