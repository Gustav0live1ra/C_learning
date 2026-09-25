#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

Matriz *criarMatriz(int nl, int nc);
void liberarMatriz(Matriz *m);
int lerElemento(Matriz *m, int i, int j, int *v);
int atribuirElemento(Matriz *m, int i, int j, int v);
int numLinhas(Matriz *m);
int numColunas(Matriz *m);

#endif