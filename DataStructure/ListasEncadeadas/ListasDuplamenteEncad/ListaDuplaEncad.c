#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaEncad.h"

/*protótipos da lista a partir da linha 206*/

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;


Lista* cria_lista(){
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *no = *li;
        while(no != NULL){
            *li = no->prox;
            free(no);
            no = *li;
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int cont = 1;
    while(no->prox != NULL){
        no = no->prox;
        cont++;
    }
    return cont;
}

int lista_vazia(Lista* li){
    return ( li == NULL || (*li) == NULL );  
}

int lista_cheia(Lista* li){
    if(li == NULL) return 0;
    Elem *no = (Elem *) malloc(sizeof(*no));
    if(no == NULL) return 1; //a ideia é, se ele tentar alocar e o malloc devolver NULL, ent teoricamente a heap está cheia e consequentemente a lista também
    free(no);
    return 0;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL ) return 0;

    Elem *a = (Elem *) malloc(sizeof(Elem));
    if(a == NULL) return 0;
    a->dados = al;
    a->prox = NULL;
    if((*li) == NULL){ //lista vazia
        *li = a;
        a->ant = NULL;
    } else {
        Elem *no = *li;
        while(no->prox != NULL){
            no = no->prox;
        }
        no->prox = a;
        a->ant = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem *a = (Elem *) malloc(sizeof(Elem));
    if(a == NULL) return 0;
    a->ant = NULL;
    a->dados = al;
    a->prox = *li;
    if((*li) != NULL) //se tiver elementos
        (*li)->ant = a;
    *li = a;

    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem *a = (Elem *) malloc(sizeof(Elem));
    if(a == NULL) return 0;
    a->dados = al;
    if((*li) == NULL){ //lista vazia
        a->ant = NULL;
        a->prox = NULL;
        *li = a;
    } else {
        Elem *atual = *li, *ante = NULL; //ante pra facilitar a ligação do novo no na lista (principalmente na ultima posição)
        while(atual != NULL && al.matricula > atual->dados.matricula){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == (*li)){ //insere no inicio
            a->ant = NULL;
            a->prox = *li;
            (*li)->ant = a;
            *li = a;
        } else {
            a->ant = ante;
            a->prox = atual;
            ante->prox = a;
            if(atual != NULL)
                atual->ant = a;
        }
    }
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no != NULL && mat != no->dados.matricula){
        no = no->prox;
    }
    if(no == NULL) return 0; //mat não encontrada
    if(no == (*li)){ // excluir o inicio
        *li = (*li)->prox;
        if((*li) != NULL) //se a lista não tiver um unico elem
            (*li)->ant = NULL;
    }
    else {
        no->ant->prox = no->prox; 
        if(no->prox != NULL) //se não for o ultimo
            no->prox->ant = no->ant; 
    }
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    *li = (*li)->prox;
    if((*li) != NULL) //caso a lista só tenha um elem
        (*li)->ant = NULL;
    
    free(no);
    return 1;

}

int remove_lista_final(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    if(no == (*li))
        *li = NULL;
    else 
        no->ant->prox = no->prox;
    
    free(no);
    return 1;
    
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }   
    if(no == NULL) return 0; //mat não encontrada
    *al = no->dados;
    return 1;
}

int busca_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || (*li) == NULL) return 0;
    if(pos <=0 ) return 0;

    Elem *no = *li;
    pos--; //no ja começa no inicio
    while(no != NULL && pos--){
        no = no->prox;
    }
    if(no == NULL) return 0; //elem ausente
    *al = no->dados;
    return 1;
}


/*protótipos da lista*/


void imprime_lista_inversa(Lista *li){
    if(li == NULL || (*li) == NULL)
        printf("(Lista Vazia).\n");
    else {
        Elem *no = *li;
        while(no->prox != NULL){
            no = no->prox;
        }
        while(no != NULL){
            printf("%d ", no->dados.matricula);
            no = no->ant;
        }
        printf("\n");
    }
    //a funcao tem custo O(N), percorrendo a lista 2 vezes: indo e voltando
}

int lista_consistente(Lista *li){
    if(li == NULL) return 0;
    if( (*li) == NULL ) return 1;
    
    Elem *no = *li;
    int consistente = 1;
    while(no->prox != NULL){
        if(no->prox->ant != no){
            consistente = 0;
            break;
        }
        no = no->prox;
    }
    return ((*li)->ant == NULL && consistente);
}

/*   questão 3
a) remove_lista(li, 33), sobre  33, 23, 16: O caso de remoção do primeiro elemento não foi tratado, ou seja, ele vai perder a referencia da lista, pois não atualizou o *li antes do free. 
sem contar que, sem sequer verificar se no->ant é NULL, ele acessa no->ant->prox, que nesse caso de remover o primeiro vai dar erro.
*/
/*b) remove_lista(li,23), sobre a mesma lista: Vai percorrer o while uma vez, e vai fazer no->ant->prox = no->prox, que nesse caso até funciona, mas falta a ligação voltando, 
isto é, no->prox->ant = no->ant, perdendo assim a caracteristica de duplamente encadeada, por isso lista_consistente retorna 0, mas tamanho_lista ainda devolve o tamanho correto pois ainda é possivel percorrer a lista pra frente.
Essa implementação atual só daria certo no caso de remover o ultimo.  
*/
/*c) correção: 
int remove_lista(Lista *li, int mat){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem* no = *li;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if(no == NULL) return 0;
    if(no == *li){
        *li = no->prox;
        if(*li != NULL)
            (*li)->ant = NULL;

    } else {
        no->ant->prox = no->prox;
        if(no->prox != NULL)
            no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}*/


int remove_lista_pos(Lista *li, int pos){
    if(li == NULL || (*li) == NULL) return 0;
    if(pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && pos > i){
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;

    if(no == (*li)){ //remover inicio
        if(no->prox == NULL){ //só tem 1 elemento
            *li = NULL;
        }
        *li = no->prox;
        (*li)->ant = NULL;

    } else {
        no->ant->prox = no->prox;
        if(no->prox != NULL)
            no->prox->ant = no->ant;
    }

    free(no);
    return 1;
    //custo O(N)
}

int move_para_inicio(Lista* li, int mat){
    if(li == NULL || (*li) == NULL) return 0;
    
    Elem *no = *li;
    while(no->prox != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == (*li)) return 1;
    if(no->dados.matricula != mat) return 0;

    no->ant->prox = no->prox;
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    no->prox = *li;
    no->ant = NULL;
    (*li)->ant = no;
    *li = no;
    return 1;
    //6 campos de ponteiro quando o elemento está no meio da lista e 5 quando está no final
}

int remove_todos(Lista *li, int mat){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int qnt = 0;
    while(no != NULL){
        if(no->dados.matricula == mat){
            if(no == (*li)){
                *li = no->prox;
                if (*li != NULL)
                    (*li)->ant = NULL;
                free(no);
                no = *li;
                
            } else {
                no->ant->prox = no->prox;
                if(no->prox != NULL)
                    no->prox->ant = no->ant;
                Elem *aux = no->prox;
                free(no);
                no = aux;
            }
            qnt++;
            
        }
        else 
            no = no->prox;
    }

    return qnt;
} 

void inverte_lista(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li, *aux;
    while(no != NULL){
        aux = no->ant;
        no->ant = no->prox;
        no->prox = aux;

        if(no->ant == NULL){
            *li = no; //desloca o inicio para o antigo final
        }
        no = no->ant; //avança na lista
            
    }
    return 1;
    //como em uma lista duplamente encadeada os nós tem dois ponteiros ant e prox, basta trocá-los em cada elem da lista até chegar no fim(deslocando pelo novo prox: no->ant) e fazer *li apontar pro novo inicio,
    //pois o inicio antigo virou o final, logo os nó's que vem dps dele precisam ser nó's anteriores a ele. E fazendo isso em todos os nó's e atualizando o *li, obtemos uma lista totalmente invertida. custo O(N).  
} 

int eh_palindromo(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 1; 

    Elem *atual = *li, *ult = *li;
    int tam = 1;
    while(ult->prox != NULL){
        ult = ult->prox;
        tam++;
    }
    if(tam == 1) return 1; //lista com apenas um elemento é palindromo

    int palindromo = 1;
    int i = tam / 2; //pra lista de tam impar também funciona, pois o elemento do meio não precisa ser comparado
    while(i--){
        if(atual->dados.matricula != ult->dados.matricula){
            palindromo = 0;
            break;
        }
        atual = atual->prox;
        ult = ult->ant;
    }
    return palindromo;
    //custo O(N), com dois loops: um pra achar o ult e outro pra comparar uma metade da lista com a outra
    //não é possivel seguir essa estratégia na lista encadeada simples, pois dps de achar o ult não da pra voltar comparando, visto que não contém em seus nós o ponteiro ant.
}
