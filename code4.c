#include <stdio.h>


                                            //average//
int main()
{
    float c=0,e=0,d=0;
    printf("digite a primeira, segunda e terceira nota respectivamente: ");
    scanf("%f %f %f", &c,&e,&d);
    printf("a média do aluno: %.1f", (c+e+d)/3);
    return 0;
}
