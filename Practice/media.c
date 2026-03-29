#include<stdio.h>

int main(void)
{
    float nota_1, nota_2, nota_3;
    
    printf("digite a sua primeira nota: ");
    scanf("%f", &nota_1);
    printf("digite a sua segunda nota: ");
    scanf("%f", &nota_2);
    printf("digite a sua terceira nota: ");
    scanf("%f", &nota_3);

    printf("a sua média é: %.2f", (nota_1 + nota_2 + nota_3) / 3); //média 
    return 0;
}
