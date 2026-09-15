#include<stdio.h>

int main()
{
    int idade;

    printf("digite a idade da pessoa: ");
    scanf("%d", &idade);

    if (idade < 18){
        if (idade < 5 && idade > 0){
            puts("bebe");
        }else if(idade <= 14){
            puts("crianca");
        }else{
            puts("adolescente");
        }
    }
    else{
        if (idade <= 60 ){
            puts("adulto");
        }else{
            puts("idoso");
        }
    }
    
    return 0;
}
