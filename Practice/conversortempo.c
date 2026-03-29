#include<stdio.h>

                                        //time conversor(second to hour)//
int main()
{
    int segundos;
    
    printf("digite uma quantidade de segundos: ");
    scanf("%d", &segundos);

    puts("sua representacao em horas minutos e segundos equivale a: ");

    printf("%d horas ", segundos / 3600);     // 3600 equivale ao valor de 1 hora em segundos //
    segundos %= 3600;  // resto da divisão para não dividir pelo valor todo e resultar em algo como "147min"

    printf("%d minutos ", segundos / 60);
    segundos %= 60;

    printf("%d segundos ", segundos);

    return 0;
}