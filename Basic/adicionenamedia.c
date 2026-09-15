#include <stdio.h>

double AdicionenaMedia(double valor){
    double static soma = 0;
    int static contador = 0;
    double media;
    
    soma += valor;
    contador +=1;

    media = soma/contador;
    
    return media;
}


int main(){
    int n;
    printf("quantos valores serão digitados? ");
    scanf("%d", &n);

    for (int i=0; i < n; i++){
        double valor, media;
        printf("valor %d: ", i+1);
        scanf("%lf", &valor);

        media = AdicionenaMedia(valor);
        
        printf("media = %.2lf\n", media);


    }
return 0;
}