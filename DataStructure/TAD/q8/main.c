#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void){

    Matriz *m1= criarMatriz(4,4);
    int num=1, linhas = numLinhas(m1), colunas = numColunas(m1);
    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){
            atribuirElemento(m1,i,j,num);
            num++;
        }
    }
    int v;
    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){
            lerElemento(m1,i,j,&v);
            printf("%d ", v);
        }
    }
    liberarMatriz(m1);
    return 0;
}