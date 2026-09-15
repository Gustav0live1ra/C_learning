#include <stdio.h>

int main(void)
{
    int valor, cedulas;

    printf("digite o valor a ser resgatado: ");
    scanf("%d", &valor);
    
    puts("voce recebera as seguintes cedulas para este valor:");

    cedulas = valor / 100;
    valor %= 100;
    printf("%d cedulas de 100\n", cedulas);

    cedulas = valor/50;
    valor %= 50;
    printf("%d cedulas de 50\n", cedulas);

    cedulas = valor / 20;
    valor %= 20;
    printf("%d cedulas de 20\n", cedulas);

    cedulas = valor / 10;
    valor %= 10;
    printf("%d cedulas de 10\n", cedulas);

    cedulas = valor / 5;
    valor %= 5;
    printf("%d cedulas de 5\n", cedulas);

    cedulas = valor / 1;
    printf("%d cedulas de 1\n", cedulas);
    return 0;
}
