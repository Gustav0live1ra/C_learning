#include <stdio.h>

// Devolver esse ponteiro é seguro por que nesse caso ele aponta diretamente para o endereço dos valores do array (cópia de endereço <-> passagem por referência).
// retornar o endereço de uma variável local não seria seguro por que aquela variável só existe dentro do escopo da função.
// uma vez que a função encerra, o endereço específico não guarda mais o valor da variável local.

int *primeiraOcorrencia(int *v, int n, int alvo){
    for (int i = 0; i < n; i++){
        if( *v == alvo ){
            return v;
        }
        v++;
    }
    return NULL;
    
}

int main(void){
    int array[6] = {12, 7, 30, 4, 18, 30};
    int *v = array;
    int *p = primeiraOcorrencia(v, 6, 99);

    if(p == NULL) {     //tratamento do caso nao encontrado
        printf("nao encontrado\n");
        return 1;
    }
    *p = 0; // acesso indireto via ponteiro para zerar o primeiro encontrado
    v = array;
    for (int i = 0; i < 6; i++){
        printf("%d ", *v);
        v++;
    }

    return 0;
}