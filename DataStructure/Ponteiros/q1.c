#include <stdio.h>

// acontece que a passagem de parâmetro para função em C é sempre uma cópia do valor da variável original,
// isso significa que a alteração que for feita na função não modificará o valor real fora do seu escopo, isso se chama passagem por valor

void dobrar(int *n){
    *n *= 2;
}

int main(void){
    int n = 21;
    dobrar(&n);
    printf("%d\n", n);
    return 0;
}