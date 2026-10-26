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
        Elem *inicio = *li;
    do{
        destroi = no;
        no = no->prox;
        free(destroi);
    }while(no != inicio);
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
    if(contador==pos){
        *al = no->dados;
        return 1;
    }
    return 0;
    
}

int busca_lista_mat(Lista *li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    while(no->prox != (*li) && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no->dados.matricula == mat){
        *al = no->dados;
        return 1;
    }
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

    a->prox = atual;
    ant->prox = a;
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

int buscaCiclica(Lista *li, int k, struct aluno *al){
    if(li == NULL || (*li) == NULL || k <= 0) return 0;

    Elem *no = *li;
    int tam = tamanho_lista(li);
    int qnt_i = (k-1) % tam; //pq no ja inicia com o primeiro elem
    while(qnt_i--) 
        no = no->prox;
    
    *al = no->dados;
    return 1;
}

int remove_lista_pos(Lista *li, int pos){
    if(li == NULL || (*li) == NULL) return 0;
    if(pos > tamanho_lista(li) || pos <= 0) return 0;

    if(pos == 1)
        remove_lista_inicio(li); //ja cobre o caso da lista ser unitária
    else{
        Elem *no = (*li)->prox, *ant = *li;
        pos -= 2; //no ja começa no segundo elem
        while(pos--){
            ant = no;
            no = no->prox;
        }
        ant->prox = no->prox; //também funciona para o último elem
        free(no);
    }
    return 1;
}

int rotaciona_lista(Lista *li, int k){
    if(li == NULL || (*li) == NULL) return 0;
    if(k < 0) return 0;

    int tam = tamanho_lista(li);
    int qnt_i = k % tam;
    while(qnt_i--){
        *li = (*li)->prox;
    }
    return 1;
//pergunta 1: O(N), mas com a otimização do '%' a quantidade de iterações se limita ao tamanho da lista, e para o caso de k=1 ou k=n*tamanho_lista(n>=0) o custo é O(1);
//pergunta 2: pra obter o mesmo resultado numa lista dinâmica encadeada não circular, seria necessário percorrer até o ultimo, fazer o ultimo apontar pro primeiro, o inicio apontar pra ele e o penultimo apontar pra NULL. Pra fazer isso k vezes seriam 2 loops aninhados, logo O(n²).
}

int concatena_lista(Lista *li1, Lista *li2){
    if(li1 == NULL || li2 == NULL) return 0;
    if((*li2) == NULL) return 1;
    if((*li1) == NULL){
        *li1 = *li2;
        *li2 = NULL;
        return 1;
    }

    Elem *ult1 = *li1;
    Elem *ult2 = *li2;
    while(ult1->prox != (*li1)){
        ult1 = ult1->prox;
    }
    while(ult2->prox != (*li2)){
        ult2 = ult2->prox;
    }
    ult1->prox = *li2;
    ult2->prox = *li1;
    return 1;
    
    //na representação de lista circular que guarda o final da lista, a função seria O(1), pois não precisaria percorrer nenhuma das duas listas, visto que a única operação trabalhosa é achar o final, e nessa representação ja o temos desde o inicio.
}

int josephus(Lista* li, int k, int *sobrevivente){
    if(li == NULL || (*li) == NULL) return 0;
    if(k <= 0) return 0;

    Elem *no = *li;
    Elem *ult = *li;
    int tam = 1;
    while(ult->prox != (*li)){
        ult = ult->prox;
        tam++;
    }
    Elem *ant = ult;
    int avancos = (k-1) % tam;

    while(no->prox != no){ //enquanto não sobrar apenas 1
        if(!avancos){ //avancos == 0 vai estar exatamente em cima do elem a ser removido
            if(no == (*li)){
                *li = no->prox;
                ult->prox = *li;
                free(no);
                no = *li;
            }
            else{
                if(no == ult){
                    ult = ant;
                }
                ant->prox = no->prox;
                free(no);
                no = ant->prox;
            }
            tam--;
            avancos = (k-1) % tam;
        }
        else{
            ant = no;
            no = no->prox;
            avancos--;  
        }

    }
    *sobrevivente = no->dados.matricula;
    free(no);
    *li = NULL;
    
    return 1;
}


// representação que guarda o ponteiro pro último no

int insere_lista_inicio2(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(*no));
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = *li;
    }
    else {
        no->prox = (*li)->prox;
        (*li)->prox = no;
    }
    return 1;
}
int insere_lista_final2(Lista *li, struct aluno al){
    if(li == NULL) return 0;

    Elem *no = (Elem *) malloc(sizeof(*no));
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = *li;
    } else {
        no->prox = (*li)->prox;
        (*li)->prox = no;
        *li = no;
    }
    return 1;
}
int remove_lista_inicio2(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = (*li)->prox;
    if((*li) == no)
        *li = NULL;
    else
        (*li)->prox = no->prox;
    free(no);
    return 1;
}
int tamanho_lista2(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    int tam = 1;
    while(no->prox != (*li)){
        no = no->prox;
        tam++;
    }
    return tam;
}
int imprime_lista2(Lista *li){
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = (*li)->prox;
    while(no != (*li)){
        printf("%d ", no->dados.matricula);
        no = no->prox;
    }
    printf("\n");
    return 1;
}

//remoção do final: a remoção do final continua sendo O(N) pois é necessário encontrar o anterior, fazer ant->prox = no->prox e atualizar o último nó ( (*li) = ant). Como começamos do ultimo nó e precisamos encontrar o penultimo, faz-se necessário percorrer a lista inteira, logo O(N).