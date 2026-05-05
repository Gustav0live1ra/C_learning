#include <stdio.h>
#include <string.h>

int main(){
    char sheldon[11], raj[11];
    int q, n=0;
    scanf("%d", &q);

    while(n++ < q){
        scanf("%s %s", sheldon, raj);

        // 1. Verifica empate. Se strings forem iguais, empatou.
        if(!strcmp(sheldon, raj)){
            printf("Caso #%d: De novo!\n", n);
        }
        // 2. Verifica todas as condições em que o sheldon vence
        else if(
            (!strcmp(sheldon, "tesoura") && (!strcmp(raj, "papel")   || !strcmp(raj, "lagarto"))) ||
            (!strcmp(sheldon, "papel")   && (!strcmp(raj, "pedra")   || !strcmp(raj, "Spock")))   ||
            (!strcmp(sheldon, "pedra")   && (!strcmp(raj, "lagarto") || !strcmp(raj, "tesoura"))) ||
            (!strcmp(sheldon, "lagarto") && (!strcmp(raj, "Spock")   || !strcmp(raj, "papel")))   ||
            (!strcmp(sheldon, "Spock")   && (!strcmp(raj, "tesoura") || !strcmp(raj, "pedra")))
        ){
            printf("Caso #%d: Bazinga!\n", n);
        }
    
        else {
            printf("Caso #%d: Raj trapaceou!\n", n);
        }
    }

    return 0;
}