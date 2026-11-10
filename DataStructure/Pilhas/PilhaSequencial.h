#ifndef PILHASEQUENCIAL_H
#define PILHASEQUENCIAL_H

struct aluno {
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct pilha Pilha;

Pilha* cria_Pilha(int capacidade);
void libera_Pilha(Pilha *pi);
int tamanho_Pilha(Pilha *pi);
int Pilha_cheia(Pilha *pi);
int Pilha_vazia(Pilha *pi);
int insere_Pilha(Pilha *pi, struct aluno al); //push
int remove_Pilha(Pilha *pi); //pop
int consulta_topo_Pilha(Pilha *pi, struct aluno *al);


#endif

