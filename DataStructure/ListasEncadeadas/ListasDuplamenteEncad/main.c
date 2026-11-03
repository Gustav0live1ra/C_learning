#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaEncad.h"

int main(void){
    Lista *li = cria_lista();
    struct aluno a1;
    for(int i=1; i<5; i++){
        a1.matricula=i;
        insere_lista_final(li,a1);
    }
    insere_lista_inicio(li,a1); //a1 = 4
    insere_lista_final(li,a1); 
    insere_lista_final(li,a1);

    imprime_lista_inversa(li); //em ordem invertida
    if(lista_consistente(li))
        printf("a lista eh consistente\n");
    
    remove_lista_pos(li,1); //lista(removeu o 4) --> 1 2 3 4 4 4
    if(lista_consistente(li))
        printf("a lista permaneceu consistente\n"); 

    move_para_inicio(li,4); //lista --> 4 1 2 3 4 4
    if(lista_consistente(li))
        printf("a lista permaneceu consistente\n");

    remove_todos(li, 4); //lista --> 1 2 3
    imprime_lista_inversa(li);
    if(lista_consistente(li))
        printf("a lista permaneceu consistente\n");
    
    inverte_lista(li); //lista --> 3 2 1
    imprime_lista_inversa(li); 
    if(lista_consistente(li))
        printf("a lista permaneceu consistente\n");

    a1.matricula = 2;
    insere_lista_final(li,a1);
    a1.matricula = 3;
    insere_lista_final(li,a1);
    if(eh_palindromo(li)){ //lista --> 3 2 1 2 3
        printf("Eh um palindromo\n");
    }
    else {
        printf("Nao eh um palindromo\n");
    }


    return 0;
}