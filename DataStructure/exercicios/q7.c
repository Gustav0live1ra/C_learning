#include<stdio.h>

// quando n é impar, o elemento central permanece intacto, pois ele está justamente no centro do array, não há necessidade de 
// inverter a posição dele

void inverter(int *v, int n){
    int *p = v + (n-1); //p aponta para o endereço do ultimo valor do array

    n = n / 2;  //percorremos até a metade do array pra inverter todos, se n for ímpar, ent n / 2 vai pegar a parte inteira da divisão
    for (int i = 0; i < n; i++){
        int aux = *v;
        *v = *p;
        *p = aux;

        v++;
        p--;
    }

}

int main(void){
    int array[7] = {1,2,3,4,5,6,7};
    inverter(array, 7);

    int *p = array;
    for (int i = 0; i < 7; i++){
        printf("%d ", *p++);
    }
    
    return 0;
}