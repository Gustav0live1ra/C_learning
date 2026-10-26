#include <stdio.h>
#include <stdlib.h>

//um vetor local dentro de uma funcao seria alocado na pilha, oq significaria que após sair do escopo da funcao a memória alocada para esse vetor seria desalocada. Isso implica que fora da funcao o endereço não guarda o dado necessário, retornar esse endereço vai causar algum comportamento indefinido.

void lerArray(float *notas, int tam){

    while(tam--){
        scanf("%f", notas);
        notas++;
    }
    
}

float calculaMedia(float notas[], int tam){

    float soma=0;
    for (int i = 0; i < tam; i++){
        soma += notas[i];
    }
    
    return soma / tam;
}

float calculaMaior(float *notas, int tam){

    float maior = *notas;
    notas++;
    tam--;

    while(tam--){
        if(*notas > maior){
            maior = *notas;
        }
        notas++;
    }
    return maior;
}

void destruirArray(float **pa){
    free(*pa);
    *pa = NULL;
}

int main(){
    int qntNotas;
    printf("quantas notas serão lidas: ");
    scanf("%d", &qntNotas);

    if( qntNotas <=0 ) return 1;

    float *notas = malloc(qntNotas * sizeof(float));
    if (notas == NULL) return 1;

    lerArray(notas, qntNotas);
    printf("Média das notas: %.1f\n", calculaMedia(notas, qntNotas));
    printf("Maior nota: %.1f\n", calculaMaior(notas, qntNotas));
    destruirArray(&notas);
    if(notas==NULL) printf("deu certo\n");


    return 0;
}