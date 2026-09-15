#include <stdio.h>


                                            //desconto//

int main(int argc, char const *argv[])
{   float p, d;
    printf("digite o preço do produto: ");
    scanf("%f", &p);
    printf("cupom de desconto: ");
    scanf("%f",&d);
    printf("o valor atual com cupom aplicado: %.2f R$\n", p - (p * d/100));
    return 0;
}
