#include <stdio.h>
#include <string.h>
#include "ListaDinEncad.h"

int main(void){
    ListaTarefas *li = cria_lista();
    printf("lista encadeada criada com sucesso!\n");
    int cont = 5; 
    for(int i=0; i<25; i++){
        struct tarefa tarefa;
        tarefa.codigo = i * i - 2*i;
        tarefa.prioridade = i;
        if(i==20){ //so a tarefa 20 tem descricao
            strcpy(tarefa.descricao, "jogar lol");
        }
        insere_tarefa_final(li, tarefa);
        printf("tarefa%d->codigo: %d\n", i+1, tarefa.codigo);
        if(i > 5 && cont){
            i--; //obriga 5 tarefas serem repetidas
            cont--;
        }
    }
    printf("LISTA PREENCHIDA COM SUCESSO!\n");

    cont = conta_tarefas_prioridade(li, 6);
    printf("\nQNT TAREFAS COM PRIORIDADE 6: %d\n", cont);
    
    struct tarefa t_mais_urgente;
    if(tarefa_mais_urgente(li,&t_mais_urgente))
        printf("\nTAREFA MAIS URGENTE -> CODIGO: %d\n", t_mais_urgente.codigo);
    
    struct tarefa t1;
    if(busca_tarefa_desc(li, "lol", &t1)){
        printf("\nTAREFA COM SUBSTRING LOL -> DESCRIÇÃO: %s\n", t1.descricao);
    }

    struct tarefa t2;
    t2.prioridade = 6;
    if(insere_tarefa_final_prioridade(li,t2))
        printf("\nINSERIDA NOVA TAREFA DE PRIORIDADE 6 COM INSERE_TAREFA_FINAL_PRIORIDADE!\n");

    cont = remove_tarefas_prioridade(li,6);
    if(cont >= 0)
        printf("\nQNT DE TAREFAS DE PRIORIDADE 6 REMOVIDAS: %d\n", cont);

    printf("\nLISTA INVERTIDA:\n");
    inverte_lista(li);
    for(int i=0; i<25; i++){
        struct tarefa tarefa;
        if(busca_tarefa_pos(li,i+1,&tarefa))
            printf("tarefa%d->codigo: %d\n", i+1, tarefa.codigo);
    }

    if(remove_tarefa_pos(li,20)){
        printf("\nREMOVIDA TAREFA DA POSICAO 20!\n");
    }

    printf("\nLI E LI2 MESCLADAS:\n");
    ListaTarefas *li2 = cria_lista();
    for(int i=0; i<25; i++){
        struct tarefa tarefa;
        tarefa.codigo = i * i - 2*i;
        tarefa.prioridade = i;
        insere_tarefa_final(li2, tarefa);
    }
    mescla_tarefas(li,li2);
    for(int i=0; i<50; i++){
        struct tarefa tarefa;
        if(busca_tarefa_pos(li,i+1,&tarefa))
            printf("tarefa%d->codigo: %d\n", i+1, tarefa.codigo);
    }

    libera_lista(li);
    return 0;

}