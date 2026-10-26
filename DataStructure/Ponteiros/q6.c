#include<stdio.h>

//Ao fazer o teste de colocar o tamanho de stringCopia menor que o de string, me deparei com um comportamento bem inesperado.
//Acontece que ocorreu um buffer overflow, o espaço alocado para o vetor stringCopia era menor que a quantidade de elementos de string,
//então os chars de string foram copiados para espaços de memória adjacentes na stack, fora do espaço alocado para stringCopia.
//como o sistema operacional não monitora cada acesso a pilha, ele não avisa e nem barra esse comportamento.

int meuStrLen(const char *p){
    int cont = 0;
    while(*p != '\0'){
        cont++;
        p++;
    }
    return cont;
}

void meuStrCpy(char *destino, const char *origem){
    while(*origem != '\0'){
        *destino = *origem;

        origem++;
        destino++;
    }
}


int main(void){
    char string[] = "Estrutura de dados";
    char stringCopia[21];
    meuStrCpy(stringCopia, string);
    int tamanho = meuStrLen(stringCopia);

    printf("%s | %d", stringCopia, tamanho);
}