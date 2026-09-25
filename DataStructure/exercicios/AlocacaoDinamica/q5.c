#include <stdio.h>
#include <stdlib.h>

//compilar o programa antes de corrigir resultou em 3 warnings: malloc alocando espaço insuficiente, *a e *b sendo usado dps de free.
//não é uma rede de segurança suficiente, pois determinados erros, como o do for que acessa um index fora do array ou a chamada dupla de malloc pra b, ele não consegue identicar.  
//o que cada um faz na memória:
    //1. malloc alocando espaço insuficiente abre brecha para o programa tentar acessar espaço fora do alocado para guardar aluno, o que pode gerar comportamento indefinido. 
    //2. depois de dar free(a) o programa tenta printar a->media, isso vai dar erro pq a não aponta mais para Aluno, aponta pra um lixo de memória qualquer.
    //3. o duplo free(b) corrompe as estruturas internas do alocador.
    //4. acessar um index out of range do array vai gerar um comportamento indefinido na memória.
    //5. o malloc duplo para *b, quando o segundo é feito ele retorna um ponteiro e faz b apontar para ele, deixando o primeiro espaço solto na memória(vazamento de memória) sem referência.
typedef struct{
    int matricula;
    char nome[32];
    float media;
} Aluno;

int main(void){
    Aluno *a = malloc(sizeof(Aluno));
    if(a == NULL) return 1;
    a -> matricula = 20260145;
    a -> media = 8.7f;

    printf("%.1f\n", a->media);
    free(a);

    Aluno *b = malloc(sizeof(Aluno));
    b -> matricula = 20260200;
    free(b);

    int *v = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++){
        v[i] = i * i;
    }
    free(v);
    return 0;
}