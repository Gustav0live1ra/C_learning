#include<stdio.h>

int main(void)
{
    float peso,altura;
    puts("digite seu peso: ");
    scanf("%f", &peso);
    puts("digite sua altura: ");
    scanf("%f", &altura);

    float imc = peso / (altura*altura);
    printf("seu IMC equivale a: %.2f \n", imc);

    if (imc <= 18.5){
        puts("voce esta abaixo do peso");
    }else { 
        if (imc > 30){
            puts("voce esta obeso");
        }else if (imc > 25){
            puts("voce esta acima do peso");
        }else {
            puts("voce esta no peso certo");
        }
    }
    return 0;
}
