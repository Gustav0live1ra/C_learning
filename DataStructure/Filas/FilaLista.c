#include "FilaLista.h"
#include <stdio.h>
#include <stdlib.h>

struct fila{
    ListaTarefas *inicio, final; //ListaTarefas é ponteiro pra no
    int qnt;
};

Fila* cria_Fila(void){
    Fila *fi = (Fila *) malloc(sizeof(*fi));
    if(fi == NULL) return NULL;
    fi->inicio = cria_lista();
    if(fi->inicio == NULL){ 
        free(fi);
        return NULL;
    }
    fi->final = NULL;
    fi->qnt = 0;
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        libera_lista(fi->inicio);
        free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) return -1;
    return fi->qnt;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL) return -1;
    return lista_cheia(fi->inicio);
}

int Fila_vazia(Fila* fi){
    if(fi == NULL) return -1;
    return lista_vazia(fi->inicio);
}

int insere_Fila(Fila* fi, struct tarefa tf){
    if(fi == NULL) return 0;
    if(!insere_tarefa_final_rapido(fi->inicio, tf, &fi->final)) return 0;
    fi->qnt++;
    return  1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL) return 0;
    if(!remove_tarefa_inicio(fi->inicio)) return 0;
    fi->qnt--;
    if(fi->qnt == 0)
        fi->final = NULL;
    return 1;
}

int consulta_Fila(Fila* fi, struct tarefa *tf){
    if(fi == NULL) return 0;
    if(!busca_tarefa_pos(fi->inicio,1, tf)) return 0;
    return 1;
}

int main(void){
    Fila *fi = cria_Fila();
    struct tarefa tf;
    for(int i = 10; i < 41; i += 10){ //insere 10 20 30 40
        tf.codigo = i;
        insere_Fila(fi, tf);
    }

    remove_Fila(fi);
    remove_Fila(fi);
    
    for(int i = 50; i < 81; i += 10){ //insere 50 60 70 80
        tf.codigo = i;
        insere_Fila(fi, tf);
    }
    remove_Fila(fi);
    insere_Fila(fi, tf); //insere 80
    libera_Fila(fi);
    return 0;
}