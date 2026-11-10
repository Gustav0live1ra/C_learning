#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila{
    int inicio, final, qnt;
    int capacidade;
    struct aluno *dados;
};


Fila* cria_Fila(int capacidade){
    if (capacidade <= 0) return NULL;
    Fila *fi = (Fila *) malloc(sizeof(Fila));
    if(fi == NULL) return NULL;
    fi->dados = (struct aluno*) malloc(capacidade * sizeof(struct aluno));
    if(fi->dados == NULL){
        free(fi); //pra nao ocorrer vazamento de mem.
        return NULL;
    }
    fi->capacidade = capacidade;
    fi->qnt = 0;
    fi->inicio = 0;
    fi->final = 0;
    return fi;
}

void libera_Fila(Fila *fi){
    if(fi != NULL){
        free(fi->dados);
        free(fi);
    }
}

int tamanho_Fila(Fila *fi){
    if(fi == NULL) return -1;
    return fi->qnt;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL) return -1;
    return fi->qnt == fi->capacidade;
}

int Fila_vazia(Fila *fi){
    if(fi == NULL) return -1;
    return fi->qnt == 0;
}

int insere_Fila(Fila *fi, struct aluno al){
    if(fi == NULL) return 0;
    if(fi->qnt == fi->capacidade)
        return 0; //lista cheia
    fi->dados[fi->final] = al;
    fi->final = (fi->final + 1) % fi->capacidade;
    fi->qnt++;
    return 1; 
}

int remove_Fila(Fila *fi){
    if(fi == NULL || fi->qnt == 0) return 0; //fila vazia

    fi->inicio = (fi->inicio+1) % fi->capacidade;
    fi->qnt--;
    return 1;
}

int consulta_Fila(Fila *fi, struct aluno *al){
    if(fi == NULL || fi->qnt == 0) return 0;

    *al = fi->dados[fi->inicio];
    return 1;
}