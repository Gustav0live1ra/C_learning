#include<stdio.h>

int main(){
    int a,b;
    printf("digite os valores de a e b respectivamente: ");
    scanf("%d%d", &a,&b);

    if (a > b){
        int c;
        c = a;
        a = b;
        b = c;
    }else if (a==b){
        printf("os valores digitados são iguais, não foi possivel fazer a contagem.");
    }
    
    while(a <= b){
        printf("%d\n", a);
        a += 1;
    }
    printf("fim!");
    return 0;
}