#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
    int linhas;
    int colunas;
    int **v;
};

Matriz *criarMatriz(int nl, int nc){
    Matriz *m = malloc(sizeof(*m));
    if(m==NULL) return NULL;

    m->linhas = nl;
    m->colunas = nc;
    
    m->v = malloc(nl * sizeof(int *));
    if(m->v==NULL) return NULL;

    for(int i=0; i<nl; i++){
        m->v[i] = malloc(nc * sizeof(int));
        if(m->v[i] == NULL){
            for(int j=0; j<i; j++){
                free(m->v[j]);
            }
            free(m->v);
            free(m);
            return NULL;
        }
    }
    return m;
}

void liberarMatriz(Matriz *m){
    for(int i=0; i<m->linhas; i++){
        free(m->v[i]);
    }
    free(m->v);
    free(m);
}
int lerElemento(Matriz *m, int i, int j, int *v){
    if(m==NULL) return 0; 
    if( i > m->linhas || j > m->colunas || i < 0 || j < 0) return 0;
    *v = m->v[i][j];
    return 1;
}
int atribuirElemento(Matriz *m, int i, int j, int v){
    if(m==NULL) return 0; 
    if( i > m->linhas || j > m->colunas || i < 0 || j < 0) return 0;
    m->v[i][j] = v;
    return 1;
}
int numLinhas(Matriz *m){
    if(m==NULL) return 0;
    return m->linhas;
}
int numColunas(Matriz *m){
    if(m==NULL) return 0;
    return m->colunas;
}