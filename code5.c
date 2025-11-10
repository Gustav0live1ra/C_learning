#include <stdio.h>

                                //convertion from 'm' to 'km' and 'mm'//
int main()
{   float m;
    printf("digite um valor em metros: ");
    scanf("%f", &m);
    printf("%.2f m equivale a %.2f mm \n%.2f m em km equivale a: %.2f", m, m*1000,m,m/1000);
    return 0;
}
