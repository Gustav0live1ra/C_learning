#include<stdio.h>

int main(void)
{
    float n1,n2, maiornota, menornota, notaUnidade, soma = 0;
    
    for (int i = 0; i < 3; ++i)
    {    
        printf("digite a nota da primeira disciplina: ");
        scanf("%f", &n1);
        printf("digite a nota da segunda disciplina: ");
        scanf("%f", &n2);
    
        if (n1 < n2){
            maiornota = n2;
            menornota = n1;
        } else{                 // atribuição para menor e maior nota//
            maiornota = n1;
            menornota = n2;
        }

        notaUnidade = (maiornota * 6 + menornota * 4) / (6 + 4);   // calculo da média da unidade
        soma += notaUnidade;

        printf("\na media ponderada da %d unidade foi de: %.1f \n\n", i + 1, notaUnidade);
        
    }
    float mediafinal;

    mediafinal = (soma / 3);      // media simples, fiz a soma das 3 medias ponderadas e dividi por 3

    printf("A media semestral desse aluno foi: %.1f ---> ", mediafinal);

    if (mediafinal < 5) {
        puts("classificacao: F");
    } else if (mediafinal < 9){
            if (mediafinal >= 8){
                puts("classificacao: B");
            } else if(mediafinal >= 7){
                puts("classificacao: C");
            } else if (mediafinal >= 6){
                puts("classificacao: D");
            } else{
                puts("classificacao: E");
            }
    } else{
        puts("classificacao: A");
    }
    
    return 0;
}
