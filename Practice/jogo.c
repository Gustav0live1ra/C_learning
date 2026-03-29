#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, correto, cont_palpites=5;

	srand(time(NULL));
	correto = rand() % 100;

	palpite = -1;
	do {
        printf("Adivinhe o numero: ");
        scanf("%d", &palpite);

            if (palpite > correto){
                puts("Palpite alto!");
            }else if (palpite < correto){
                puts("Palpite foi baixo!");
            }
        cont_palpites-=1;
        printf("sua quantidade de tentativas: %d\n", cont_palpites);

	} while(palpite != correto && cont_palpites >= 1);
    
    if(cont_palpites >0){
        printf("Voce acertou! sua quantidade total de chutes foi %d", cont_palpites);
    }else{
        printf("voce nao conseguiu acertar, sinto muito. O valor correto era %d", correto);
    }
	return 0;
}