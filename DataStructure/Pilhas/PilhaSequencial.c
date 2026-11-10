#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"

struct pilha {
    int qnt;
    int capacidade;
    struct aluno *dados; //vetor alocado na heap
};

Pilha* cria_Pilha(int capacidade){
    if(capacidade <= 0) return NULL;
    Pilha *pi = (Pilha*) malloc(sizeof(*pi));
    if(pi == NULL) return NULL;
    pi->dados = (struct aluno*) malloc(capacidade * sizeof(struct aluno));
    if(pi->dados == NULL){
        free(pi);
        return NULL;
    }
    pi->capacidade = capacidade;
    pi->qnt = 0;
    return pi;
}

void libera_Pilha(Pilha *pi){
    if(pi != NULL){
        free(pi->dados);
        free(pi);
    }
}

int tamanho_Pilha(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->qnt;
}

int Pilha_cheia(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->qnt == pi->capacidade;
}

int Pilha_vazia(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->qnt == 0;
}

int insere_Pilha(Pilha *pi, struct aluno al){ //push
    if(pi == NULL) return 0;
    if(pi->qnt == pi->capacidade) return 0;
    pi->dados[pi->qnt] = al;
    pi->qnt++;
    return 1;
}

int remove_Pilha(Pilha *pi){ //pop
    if(pi == NULL) return 0;
    if(pi->qnt == 0) return 0;
    pi->qnt--; //o topo desce uma posição, o valor antigo continua lá como lixo para eventualmente ser sobrescrito
    return 1;
}

int consulta_topo_Pilha(Pilha *pi, struct aluno *al){
    if(pi == NULL) return 0;
    if(pi->qnt == 0) return 0;
    *al = pi->dados[pi->qnt - 1];
    return 1;
}

int esvazia_Pilha(Pilha *pi){
    if(pi == NULL) return 0;
    if(pi->qnt == 0) return 1;
    pi->qnt = 0;
    return 1;
}


int main(void){
    Pilha *pi = cria_Pilha(4);
    while(!Pilha_vazia(pi)){
        remove_Pilha(pi);
    }
}