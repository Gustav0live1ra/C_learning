#include<stdio.h>

int main()
{
    float media1,media2,media3,media4;
                                            // leitura das médias //
    printf("1° media: ");
    scanf("%f", &media1);
    printf("2° media: ");
    scanf("%f", &media2);
    printf("3° media: ");           
    scanf("%f", &media3);
    printf("4° media: ");
    scanf("%f", &media4);

                                        //calculo da média ponderada//

    media2*= 2;
    media3*= 3;
    media4*= 4;

                                    // impressão da média total na tela //

    printf("a média total do aluno foi %.1f \n", (media1 + media2 + media3 + media4) / 10); //soma das médias pela soma dos pesos
    
// bonus // 
    if ( (media1 + media2 + media3 + media4) / 10 >= 7 ){
        puts("aluno aprovado");
    }else if( (media1 + media2 + media3 + media4) / 10 < 5) {
        puts("aluno reprovado");
    }else{
        puts("aluno vai para final");
    }
    return 0;
}
