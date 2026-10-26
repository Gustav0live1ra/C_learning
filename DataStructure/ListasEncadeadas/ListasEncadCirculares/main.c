#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

int main(void){ //main de teste
    Lista *li = cria_lista();
    Lista *li2 = cria_lista();
    struct aluno a1, a2, a3, a4, a5, a6, a7;
    a1.matricula=1;a2.matricula=2;a3.matricula=3;a4.matricula=4,a5.matricula=5,a6.matricula=6,a7.matricula=7;
    insere_lista_final(li, a1);
    insere_lista_final(li, a2);
    insere_lista_final(li, a3);
    insere_lista_final(li, a4);
    insere_lista_final(li2, a5);
    insere_lista_final(li2, a6);
    insere_lista_final(li2, a7);
    
    struct aluno a, b;
    buscaCiclica(li, 5, &a);
    buscaCiclica(li, 43, &b);
    printf("%d %d\n", a.matricula, b.matricula);

    rotaciona_lista(li, 2);
    imprime_lista(li);
    rotaciona_lista(li, 2);
    imprime_lista(li);

    concatena_lista(li,li2);
    imprime_lista(li);

    int sobrevivente;
    josephus(li,4, &sobrevivente);
    printf("Sobrevivente: %d\n", sobrevivente);

    remove_lista_pos(li,1);
    imprime_lista(li);
    remove_lista_pos(li,3);
    imprime_lista(li);

    return 0;
}