#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
#include <string.h>

/*Protótipos da lista implementados a partir da linha 220*/

struct elemento{
    struct tarefa dados;
    struct elemento *prox;
};

typedef struct elemento Elem;


ListaTarefas *cria_lista(void){
    ListaTarefas *li =(ListaTarefas*) malloc(sizeof(*li));
    if(li != NULL)
        *li = NULL; //lista comeca vazia
    return li;

}

void libera_lista(ListaTarefas *li){
    if(li != NULL) {
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int tamanho_lista(ListaTarefas *li){
    if(li == NULL) return -1;
    int cont=0;
    Elem *no = *li; //no inicia apontando para o primeiro elemento da lista
    while(no != NULL){ //enquanto houver no's validos
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(ListaTarefas *li){
    if(li == NULL) return -1;
    return *li == NULL; //inicio é nulo
}

int lista_cheia(ListaTarefas *li){
    (void) li;
    return 0;
}

int insere_tarefa_inicio(ListaTarefas *li, struct tarefa t){
    if(li == NULL) return 0;
    
    Elem *no = (Elem*) malloc(sizeof(*no));
    if(no == NULL) return 0;

    no->dados = t;
    no->prox = (*li);
    *li = no;
    return 1;

}
int insere_tarefa_final(ListaTarefas *li, struct tarefa t){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(*no));
    if(no == NULL) return 0;
    no->dados = t;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia
        (*li) = no;
    }
    else{
        Elem *aux = *li;
        while((aux->prox) != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_tarefa_ordenada(ListaTarefas *li, struct tarefa t){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(*no));
    if(no == NULL) return 0;
    no->dados = t;

    if((*li) == NULL){ //lista vazia
        no->prox = NULL;
        *li = no;
        return 1;
    }
    Elem *ant = NULL;
    Elem *atual = *li;
    while(atual != NULL && t.prioridade > atual->dados.prioridade){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == (*li)){ //insere inicio 
        no->prox = (*li); //no->prox aponta para o primeiro elem
        *li = no; 
    }
    else {//t.prioridade é menor que prioridade atual
        no->prox = atual;
        ant->prox = no;
    }
    return 1;
}

int remove_tarefa_inicio(ListaTarefas *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;

}
int remove_tarefa_final(ListaTarefas *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li; 
    Elem *ant = NULL;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)){ //lista unitaria
        *li = NULL;
    }
    else
        ant->prox = NULL;
    free(no);
    return 1;
    
}

int remove_tarefa(ListaTarefas *li, int codigo){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    Elem *ant = NULL;
    while(no != NULL && codigo != no->dados.codigo){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //codigo não encontrado
        return 0;
    
    if(no == (*li)) //primeiro elemento
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);
    return 1;
}

int busca_tarefa_pos(ListaTarefas *li, int pos, struct tarefa *t){
    if(li==NULL || pos <= 0) return 0;

    Elem *no = *li;
    int i=1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    
    *t = no->dados;
    return 1;
    
}

int busca_tarefa_cod(ListaTarefas *li, int codigo, struct tarefa *t){
    if(li==NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no != NULL && no->dados.codigo != codigo){
        no = no->prox;
    }
    if(no == NULL)
        return 0;

    *t = no->dados;
    return 1;

}

/* versão usando no->prox->prox (desafio de sala) */

int remove_tarefa_final2(ListaTarefas* li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;

    if(no->prox == NULL) //so tem 1 elemento
        *li = no->prox;
        free(no);
        return 1;
    while(no->prox->prox != NULL){ 
        no = no->prox;
    }
    
    free(no->prox); //libera ultimo no
    no->prox = NULL; //faz penultimo apontar para nulo
    
    return 1;

}

/*-------------------------------------------------------------*/
                /*protótipos a implementar*/

int conta_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if(li == NULL) return -1;
    if((*li) == NULL) return 0;

    Elem *no = *li;
    int contador=0;
    while(no != NULL){
        if(no->dados.prioridade == prioridade){
            contador++;
        }
        no = no->prox;
    }
    return contador;
}

int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t){
    if(li == NULL || (*li) == NULL ) return 0;

    Elem *no = *li;
    Elem *menor = *li;
    while(no != NULL){
        if(no->dados.prioridade < menor->dados.prioridade){
            menor = no;
        }
        no = no->prox;
    }
    *t = menor->dados;
    return 1;
}

int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t){
    if(li == NULL || (*li) == NULL) return 0;
    
    Elem *no = *li;
    while(no != NULL){
        if(strstr(no->dados.descricao, texto)){
            *t = no->dados;
            return 1;
        }
        no = no->prox;
    }
    return 0; //não encontrou nenhuma descricao
    
}

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(*no));
    no->dados = t;
    Elem *atual = *li, *ant = NULL;
    while(atual != NULL && t.prioridade <= atual->dados.prioridade){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == (*li)){
        no->prox = (*li);
        *li = no;
    } else {
        no->prox = atual;
        ant->prox = no;
    }
    return 1;
}

int remove_tarefas_prioridade(ListaTarefas* li, int prioridade){
    if(li == NULL) return -1;
    if((*li) == NULL) return 0;

    int contador=0;
    Elem *atual = *li;
    Elem *ant= NULL;

    while(atual != NULL){
        if(atual->dados.prioridade == prioridade){
            Elem *remover = atual;
            if(atual == *li){ //precisa atualizar inicio da lista
                *li = atual->prox;
                atual = (*li); //atualiza atual
            } 
            else {
                ant->prox = atual->prox;
                atual = ant->prox;
            }
            free(remover);
            contador++;
        }else{
            ant = atual;
            atual = atual->prox;
        }
    }
    
    return contador;
}

int inverte_lista(ListaTarefas* li){
    if(li == NULL) return 0;
    if((*li) == NULL || (*li)->prox == NULL) return 1;

    Elem *atual = *li;
    Elem *ant = NULL;
    Elem *prox; 
    while(atual != NULL){
        
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *li = ant;
    return 1;

}

int remove_tarefa_pos(ListaTarefas* li, int pos){
    if(li == NULL || (*li) == NULL || pos <= 0) return 0;

    Elem *no = *li;
    Elem *ant = NULL;
    int i=1;
    while(no != NULL && i<pos){
        ant = no;
        no = no->prox;        
        i++;
    }
    if(no == NULL) return 0;
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);
    return 1;
    
}

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src){
    if(dst == NULL || src == NULL) return -1;

    if((*dst) == NULL){
        *dst = *src;
    } else {
        Elem *no = *dst;
        while(no->prox != NULL && no != NULL){
            no = no->prox;
        }
        no->prox = *src; //ultimo de dst aponta pra inicio de src
    }

    int contador=0;
    Elem *no = *src;
    while(no != NULL){
        no = no->prox;
        contador++;
    }
    *src = NULL;
    return contador;
}

int insere_tarefa_final_rapido(ListaTarefas* li, struct tarefa t, ListaTarefas *final){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(*no));
    if(no == NULL) return 0;
    no->dados = t;
    no->prox = NULL;
    if((*li) == NULL)//lista vazia
        *li = no;
    else
        (*final)->prox = no;
    *final = no;
    return 1;
}