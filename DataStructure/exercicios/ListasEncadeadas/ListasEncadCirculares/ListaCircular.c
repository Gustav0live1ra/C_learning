#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

//funcões da lista implementadas a partir da linha 239

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(*li));
    if(li != NULL) 
        (*li) = NULL;
    return li;

}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *no = *li, *destroi;
        do{
            destroi = no;
            no = no->prox;
            free(destroi);
        }while(no->prox != (*li));
        
        free(no);
        free(li);
    }
}

int busca_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Elem *no = *li;
    int contador = 1;
    while(no->prox != (*li) && contador < pos){
        no = no->prox;
        contador++;
    }
    if(contador==pos)
        *al = no->dados;
        return 1;
    return 0;
    
}

int busca_lista_mat(Lista *li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no->prox != (*li) && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no->dados.matricula == mat)
        *al = no->dados;
        return 1;
    return 0;

}

int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL) return 0;

    Elem *a = (Elem*) malloc(sizeof(*a));
    if(a == NULL) return 0;
    a->dados = al;
    
    if((*li) == NULL){ //lista vazia
        *li = a;
        a->prox = *li;
    }
    else{
        Elem *no = *li;
        while(no->prox != (*li)){
            no= no->prox;
        }
        a->prox = *li;
        no->prox = a; //faz o no final apontar pro novo no
    }
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL) return 0;

    Elem *a = (Elem *) malloc(sizeof(*a));
    if(a == NULL) return 0;
    a->dados = al;

    if((*li) == NULL){
        *li = a;
        a->prox = *li;
    }
    else{
        Elem *no = *li;
        while(no->prox != (*li)){
            no = no->prox;
        }
        a->prox = *li; //antigo inicio
        *li = a; 
        no->prox = *li; //novo inicio
    }
    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al){
    if(li == NULL) return 0;

    Elem *a = (Elem*) malloc(sizeof(*a));
    if(a == NULL) return 0;
    a->dados = al;

    if((*li) == NULL){ //lista vazia
        *li = a;
        a->prox = *li;
        return 1;
    }
    
    if(al.matricula < (*li)->dados.matricula){ //inicio
        Elem *atual = *li;
        while(atual->prox != (*li)){
            atual = atual->prox;
        }
        atual->prox = a;
        a->prox = *li;
        *li = a;
        return 1;
    }

    Elem *atual = (*li)->prox , *ant = *li;
    while(atual != (*li) && atual->dados.matricula < al.matricula){
        ant = atual;
        atual = atual->prox;
    }

    a = atual;
    ant = a;
    return 1;
}

int remove_lista(Lista *li, int mat){
    if(li == NULL || (*li) == NULL) return 0;

    if((*li)->dados.matricula == mat){ //remover do inicio
        Elem *no = *li;
        if(no->prox == no){ //se for unitária
            free(no);
            *li = NULL;
        }
        else{
            Elem *ult = *li;
            while(ult->prox != (*li)){
                ult = ult->prox;
            }
            *li = no->prox;
            ult->prox = *li;
            free(no);
            
        }
        return 1;
    }

    Elem *atual = (*li)->prox, *ant = *li;
    while(atual != (*li) && atual->dados.matricula != mat){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == (*li)) return 0; //chave ausente

    ant->prox = atual->prox;
    free(atual);
    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li, *ult = *li;
    while(ult->prox != (*li)){
        ult = ult->prox;
    }
    if(ult == (*li)) //só tem um elemento
        *li = NULL;
    else{
        *li = no->prox;
        ult->prox = *li;
    }
    free(no);
    return 1;

}

int remove_lista_final(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li, *ant = NULL;
    while(no->prox != (*li)){
        ant = no;
        no = no->prox;
    }
    if(ant == NULL)  //só um elemento
        *li = NULL; 
    else 
        ant->prox = *li;
    free(no);
    return 1;
    
}

int tamanho_lista(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int contador=1;
    while(no->prox != (*li)){
        contador++;
        no = no->prox;
    }
    return contador;
}

int lista_vazia(Lista *li){
    if(li == NULL) return 1; //lista invalida
    return (*li) == NULL;
}

int lista_cheia(Lista *li){
    return 0;
}


        /*IMPLEMENTAÇÃO DOS PROTÓTIPOS DA LISTA*/

void imprime_lista(Lista *li){
    if(li != NULL && (*li) != NULL){
        Elem *no = *li;
        do{
            printf("%d ", no->dados.matricula);
            no=no->prox;
        }while(no != (*li));
        printf("\n");
    }
}

int maior_matricula(Lista *li, int *mat){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int maior = no->dados.matricula;
    do{
        no=no->prox;
        if(no->dados.matricula > maior)
            maior = no->dados.matricula;

    }while(no != (*li));
    *mat = maior;
    return 1;
}

int conta_aprovados(Lista* li){
    //o primeiro erro da versão do código com defeito é a condição do while (no != NULL) que vai gerar um loop infinito, pois como a lista é circular, não existe no nulo
    //o segundo erro é que não é feita a verificação da lista ser inválida ou vazia, ele ja acessa direto a lista na atribuição *no = *li. Se ocorrer de a lista ser inválida ele vai tentar acessar uma região de memória que não existe e o programa vai quebrar
    /*versão corrigida*/
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int cont=0;
    do{
        float media = (no->dados.n1+no->dados.n2+no->dados.n3) / 3;
        if(media >= 7)
            cont++;
        no=no->prox;
    } while(no != (*li));
    return cont;
}

