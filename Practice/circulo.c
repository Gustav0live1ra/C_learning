#include <stdio.h>

int main(void)
{
    float diametro, raio;

    printf("digite na tela o diâmetro do circulo: ");
    scanf("%f", &diametro);

    raio = diametro/2;    //calculo do raio
    printf("o raio do circulo é: %.2f\n", raio);

    printf("a area desse circulo é: %.2f\n", 3.14 * (raio*raio)); //calculo da area pi * r² 

    printf("a circunferencia do circulo é: %.2f\n", 2 * (3.14 * raio)); //calculo da circunferencia

    return 0;
}
