#include <stdio.h>

int main(){
    int c = 1, soma = 0, cont = 0; 

    while(c != 0 ){
        printf("digite um valor(digite 0 para parar): ");
        scanf("%d", &c);

        if(c != 0){
            soma += c;
            cont += 1;
        }
        
    }

    printf("a media total dos valores digitados foi: %.2f", (soma * 1.0) / cont);

    return 0;
}