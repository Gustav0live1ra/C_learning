#include <stdio.h>

                                        //parte inteira de um número//
int main(int argc, char const *argv[])
{
    float a = 0;
    printf("digite um número decimal: ");
    scanf("%f",&a);
    printf("a parte inteira de %f é: ", a);
    a = (int)a;
    printf("%.0f",a);
    return 0;
}
