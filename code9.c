#include<stdio.h>

                                        //time conversor(second to hour)//
int main()
{   int s;
    printf("digite uma quantidade de seg para ver sua representaçao em horas: ");
    scanf("%d", &s);
    printf("%d segundos equivalem a: ",s);
    if (s/3600 > 0){ // como a variavel s é inteiro, entao se der decimal(como 0,55322344) ele vai pegar
                     // apenas a parte inteira, ou seja, 0
        printf("%d horas ", s/3600);
        s = s % 3600;
        printf("%d minutos ", s/60);
        s = s % 60;
        printf("%d segundos\n", s);
    }else{
        printf("0 horas ");
        s /=60;
        printf("%d minutos ",s);
        s = s % 60;
        printf("%d segundos\n",s);
    }
    
    return 0;
}
