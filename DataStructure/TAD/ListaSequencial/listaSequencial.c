#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSequencial.h"

struct lista{
    int qnt;
    struct produto dados[MAX];
    
};

//funções implementadas em sala

Lista* cria_lista(){
    Lista *li = malloc(sizeof(*li));
    if(li!=NULL) {
        li->qnt = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int busca_lista_pos(Lista* li, int pos, struct produto *p){
    if(li == NULL || pos <= 0 || pos > li->qnt) 
        return 0;
    *p = li->dados[pos-1];
    return 1;
}

int busca_lista_cod(Lista* li, int cod, struct produto *p){
    if(li == NULL) return 0;
    for (int i = 0; i < li->qnt; i++){
        if(li->dados[i].codigo == cod){
            *p = li->dados[i];
            return 1;
        }
    }
    return 0;
}
int insere_lista_final(Lista* li, struct produto p){
    if(li==NULL || li->qnt == MAX) return 0;

    li->dados[li->qnt] = p;
    li->qnt++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct produto p){
    if(li==NULL || li->qnt == MAX) return 0;

    for(int i=li->qnt; i>0; i--){
        li->dados[i] = li->dados[i-1];
    }
    li->dados[0] = p;
    li->qnt++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct produto p){
    if(li==NULL || li->qnt == MAX) return 0;
    
    int i;
    for(i = 0; i < li->qnt; i++){
        if(p.codigo < li->dados[i].codigo){
            break; //posição encontrada
        }
    }
    for (int j=li->qnt; j > i; j--){
        li->dados[j] = li->dados[j-1];
    }
    li->dados[i] = p;
    li->qnt++;
    return 1;
}

int remove_lista(Lista* li, int cod){
    if(li==NULL || li->qnt == 0) return 0;

    int i;
    for(i=0; i<li->qnt; i++){
        if(li->dados[i].codigo == cod){
            break;
        }
    }
    if(i==li->qnt) return 0;  //não encontrado

    while(i < li->qnt-1){
        li->dados[i] = li->dados[i+1];
        i++;
    }
    li->qnt--;  //se o produto for o ultimo da lista, pula o while e vem direto pra cá
    return 1;
}
int remove_lista_otimizado(Lista* li, int cod){
    if(li == NULL || li->qnt == 0) return 0;
    
    int i;
    for( i=0; i<li->qnt; i++){
        if(li->dados[i].codigo == cod){
            break;
        }
    }
    if(i==li->qnt) return 0;
    li->dados[i] = li->dados[li->qnt-1];
    li->qnt--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL || li->qnt==0) return 0;

    for(int i=0; i < li->qnt-1; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->qnt--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li==NULL || li->qnt == 0) return 0;

    li->qnt--;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li==NULL) return -1;
    return li->qnt;
}
int lista_cheia(Lista* li){
    if(li==NULL) return -1;
    return li->qnt == MAX;
}
int lista_vazia(Lista* li){
    if(li==NULL) return -1;
    return li->qnt == 0;
}

        /* prototipos da lista */

int lista_tem_espaco(Lista* li, int n){
    if(li==NULL) return 0;
    return MAX - li->qnt >= n;
}

float soma_precos(Lista* li){
    if(li==NULL) return 0;

    float soma=0;
    for(int i=0; i<li->qnt; i++){
        soma += li->dados[i].preco;
    }
    return soma;
}

int busca_por_nome(Lista* li, char *nome, struct produto *p){
    if(li==NULL) return 0;

    for(int i=0; i < li->qnt; i++){
        if(!strcmp(li->dados[i].nome, nome)){
            *p = li->dados[i];
            return 1;
        }
    }
    return 0;
}

int insere_lista_decrescente(Lista* li, struct produto p){
    if(li==NULL || li->qnt ==MAX) return 0;
    
    int i;
    for(i=0; i< li->qnt; i++){
        if(p.preco > li->dados[i].preco){
            break;
        }
    }
    for(int j=li->qnt; j>i; j--){
        li->dados[j] = li->dados[j-1];
    }
    li->dados[i] = p;
    li->qnt++;
    return 1;
}

int remove_mais_caro(Lista* li, struct produto *removido){
    if(li == NULL || li->qnt == 0) return 0;
    
    float maior=li->dados[0].preco;
    int indice_Maior=0;
    for(int i=1; i< li->qnt; i++){
        if(li->dados[i].preco > maior){
            maior = li->dados[i].preco;
            indice_Maior = i;
        }
    }
    //usando o algoritmo de remoção otimizada
    *removido = li->dados[indice_Maior];
    li->dados[indice_Maior] = li->dados[li->qnt-1];
    li->qnt--;
    return 1;
}

int conta_faixa_preco(Lista* li, float min, float max){
    if(li == NULL) return 0;

    int contador=0;
    for(int i =0; i<li->qnt; i++){
        if(li->dados[i].preco >= min && li->dados[i].preco <= max) {
            contador++;
        }
    }
    return contador;
}

int remove_abaixo_de(Lista* li, float precoMinimo){
    if(li == NULL) return 0;

    int contador=0;
    for(int i=0; i<li->qnt; i++){
        if(li->dados[i].preco < precoMinimo){
            li->dados[i] = li->dados[li->qnt-1];
            li->qnt--;
            i--; //faz ele avaliar de novo a mesma posição
            contador++;
        }
    }
    return contador;
}

int mescla_listas(Lista* destino, Lista* origem){
    if(destino == NULL || origem == NULL) return 0;
    if(destino->qnt == MAX || origem->qnt == 0) return 0;

    int verificador , contador = 0;
    for(int i = 0; i<origem->qnt; i++){
        verificador=1; //reseta
        for(int j=0; j<destino->qnt; j++){
            if(origem->dados[i].codigo == destino->dados[j].codigo){
                verificador = 0;
                break;
            }
        }
        if(verificador){
            destino->dados[destino->qnt] = origem->dados[i];
            destino->qnt++;
            contador++;
        }
        if(destino->qnt == MAX) return contador;
    }
    return contador;
}