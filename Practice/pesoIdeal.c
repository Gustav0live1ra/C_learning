#include <stdio.h>

int main(void)
{
    char genero;
    float altura, pesoideal;

    printf("qual seu genero? [M/F] ");
    scanf("%c", &genero);
    printf("sua altura: ");
    scanf("%f", &altura);

    if (genero == 'M' || genero == 'm'){
        pesoideal = (72.7 * altura) - 58;
    }
    if (genero == 'F' || genero == 'f'){
        pesoideal = (62.1 * altura) - 44.7;
    }
    
    printf("o seu peso ideal e %.2f", pesoideal);
    
    return 0;
}
