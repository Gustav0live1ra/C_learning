#ifndef FILALISTA_H
#define FILALISTA_H

#include "ListaDinEncad.h"

typedef struct fila Fila;

Fila* cria_Fila(void);
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_cheia(Fila* fi);
int Fila_vazia(Fila* fi);
int insere_Fila(Fila* fi, struct tarefa tf);
int remove_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct tarefa *tf);

#endif