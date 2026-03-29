#include <stdio.h>
#define linha "----------------------------------\n"


int main()
{
    int idade = 0, ano = 1980;
    printf(linha);
    printf("idade inicial vale: %d \n", idade);
    
    printf("digite a sua idade e seu ano de nascimento: ");
    scanf("%d %d", &idade, &ano);
    printf("sua idade e %d anos e sua data de nascimento é %d.\n", idade, ano);
    printf(linha);
    return 0;
}
