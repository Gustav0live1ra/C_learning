#include<stdio.h>

int main(void)
{
    float base, altura;

    printf("digite o valor da base do triangulo: ");
    scanf("%f", &base);
    printf("digite o valor da altura do triangulo: ");
    scanf("%f", &altura);
    
    printf("a area desse triangulo e igual a %.2f", (base * altura) / 2);

    return 0;
}
