//pergunte a quantidade de Km percorridos por um carro alugado e a quantidade de dias pelos quais ele//
//foi alugado. Calcule o preço a pagar, sabendo que o carro custa R$'n' por dia e R$0,15 por Km rodado.//
#include <stdio.h>

int main()
{   
    int d_uteis;
    float diaria, km;
    printf("quantos dias você utilizou o carro? ");
    scanf("%d",&d_uteis);
    printf("digite o preço do aluguel diário do carro: ");
    scanf("%f", &diaria);
    printf("quantos km foram rodados? ");
    scanf("%f", &km);
    printf("O preço pelo aluguel desse carro é de: %.2fR$", (diaria * d_uteis) + (km * 0.15));
    return 0;
}
