#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,delta;
    
    printf("valor a: ");
    scanf("%d", &a);
    printf("valor b: ");
    scanf("%d", &b);
    printf("valor c: ");
    scanf("%d", &c);

    if (a == 0){
        puts("e impossivel descobrir as raizes dessa equacao do 2 grau, pois o coeficiente A e 0");
        return 1;
    }
    
    delta = (b * b) - (4 * a * c);

    if (delta <=0) {
        puts("o delta deu negativo ou igual a zero, logo nao tem raizes reais");
        return 2;
    }
    
    puts("as raizes dessa equacao do segundo grau sao: ");
    
                                // sqrt calcula a raiz quadrada //
    printf("x1 = %.0f \n", ( ((-1) *b + sqrt(delta)) / (2* a) ) );
    printf("x2 = %.0f \n", ( ((-1) *b - sqrt(delta)) / (2* a) ) );
    return 0;
}
