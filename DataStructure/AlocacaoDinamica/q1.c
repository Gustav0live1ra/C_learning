#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ao passar diretamente o ponteiro de aluno para a funcao, seria criado uma cópia do ponteiro original, devido a passagem de parâmetros em C ser
// sempre por valor, de modo que se atribuirmos NULL ao parâmetro nada vai acontecer com o ponteiro original.
// precisamos de um ponteiro auxiliar que aponte para o endereço do ponteiro original e atribuir NULL ao ponteiro original via acesso indireto do ponteiro auxiliar.


typedef struct {
    int matricula;
    char nome[32];
    float media;
} Aluno;

Aluno *criarAluno(int matricula, char *nome, float media){
    Aluno *p = malloc(sizeof(*p)); //40 bytes na heap
    if(p == NULL) return NULL; 

    p -> matricula = matricula;
    strcpy(p->nome, nome);
    p-> media = media;

    return p;
}

void imprimirAluno(const Aluno *a){ //passamos 1 ponteiro ao invés da struct inteira, para que a funcao n precise copiar a struct toda
    if(a != NULL){
        printf("Aluno: %s\n", a->nome);
        printf("Matricula: %d\n", a->matricula);
        printf("Media(CRA): %.1f\n", a->media);
    }
}

void destruirAluno(Aluno **pa){
    free(*pa); //limpa a memória alocada na heap
    *pa = NULL; //coloca via novo ponteiro o ponteiro original como NULL
}

int main(void) {
    int matricula = 12345678;
    char nome[32] = "eduardo";
    float media = 7.8;

    Aluno *a = criarAluno(matricula, nome, media);
    imprimirAluno(a);
    destruirAluno(&a);
    destruirAluno(&a); //não gera liberação dupla pois nesse segundo caso o compilador faz free(NULL)
    if(a==NULL) printf("o aluno foi deletado!\n"); //mostrando que foi excluido de fato

    return 0;
}