#include <stdio.h>
#include <stdlib.h>

struct no
{
    int dado;
    struct no *prox;
};
typedef struct no* Lista;

Lista *criarLista(){
    Lista *head = malloc(sizeof(*head));
    if(head != NULL)
        *head = NULL;
    return head;
}

int insere_final(Lista *li, int valor){
    struct no *n = malloc(sizeof(*n));
    if(n == NULL) return 0;
    n->dado=valor;
    n->prox=NULL;
    if((*li == NULL)){
        *li = n;
        return 1;
    }
    struct no *p = *li;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = n;
    return 1;
}

int verifica_ordenada(Lista *li){
    if(li==NULL)return -1;
    if((*li) == NULL) return 1;
    if((*li)->prox == NULL) return 1;

    struct no *atual = *li, *prox = atual->prox;
    while(prox != NULL){
        if(prox->dado < atual->dado){
            return 0;
        }
        atual = prox;
        prox = atual->prox;
    }
    return 1;
}

int main(void){
    Lista *li = criarLista();
    insere_final(li,10);
    insere_final(li,20);
    insere_final(li,10);
    insere_final(li,40);
    int verdade = verifica_ordenada(li);
    printf("%d", verdade);

    return 0;
}