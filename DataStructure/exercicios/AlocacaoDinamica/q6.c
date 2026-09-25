#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a quantidade de bytes alocada no calloc para a string é 19, pois são 18 da soma das duas strings +1 do \0.
// se n tivesse esse byte extra, o printf não iria encontrar o terminador da string, e continuaria lendo memória adiante até encontrar um \0.
// comportamento indefinido. 

//sizeof(a) retorna o tamanho do ponteiro, não a quantidade de caracteres da string a.

char *concatenar(const char *a,const char *b){
    int tamA = strlen(a), tamB = strlen(b);
    int tam = tamA + tamB + 1; // as duas strings + o \0

    char *stringConcat = calloc(tam, sizeof(char));  //calloc para zerar o bloco de memória da heap e impedir que ele faça a concatenação com o lixo
    if(stringConcat == NULL) return NULL;
    strcat(stringConcat, a);
    strcat(stringConcat, b);
    
    return stringConcat; 
}


int main(){
    char *t = concatenar("Estrutura de ", "Dados");
    if(t == NULL) return 1;
    printf("%s\n", t);
    printf("%lld",strlen(t));
    free(t);
    return 0;
}
