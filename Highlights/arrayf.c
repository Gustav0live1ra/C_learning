#include <stdio.h>

float Calculamedia(int arr[],int t){                   // questao 3 //
    float soma = 0;
    for (int i=0; i<t; i++){
        soma += arr[i];
    }
    
    return soma / t;
}   


int Emarray(int arr[], int t, int valor){              //questao 4//
    for (int i=0; i<t; i++){
        if(valor == arr[i]){
            return 1;
        }
    }
    return 0;
}


int Maiorvalorarray(int arr[], int t){              //questao 5//
    int maior = 0;
    for (int i=0; i<t; i++){
        if(i==0){
            maior = arr[i];
        }else if(maior < arr[i]){
            maior = arr[i];
        }
    }
    return maior;
}

int Eharrayordenado(int arr[], int t){              //questao 6//
    int cont = 1;
    for(int i=0; i<t-1; i++){
        if(arr[i] > arr[i+1]){
            cont = 0;
        }
    }
    return cont;
}


int main(){                                   //questao 1 e 2//
    int array[10], cont=1, sum=0;
    for (int i=0; i<10; i++){
        scanf("%d", &array[i]);
    }

    printf("array normal:\n");
    for (int i=0; i<10; i++){
        printf("%d%c", array[i], (i==9) ? '\n' : ' ');
    }

    printf("array invertido:\n");
    for (int i=9; i>=0; i--){
        printf("%d%c", array[i], (i==0) ? '\n' : ' ');
    }


    printf("o elemento da quinta posicao do array eh:\n%d\n", array[4]);
    
    printf("elementos de indice impar do array:\n");
    for (int i=0; i<10; i++){
        if(i % 2 != 0){
            printf("%d%c",array[i], (i==9) ? '\n': ' ');
        }

        sum += array[i];
    }
    printf("a soma dos elementos do array eh:\n%d\n", sum);


    //chamada da questao 3 //
    printf("a media dos elementos do array eh:\n%.1f\n", Calculamedia(array,10));


    //chamada da questao 4//
    if(Emarray(array, 10, 3)){  //valor de teste=3;//
        printf("o valor 3 esta presente no array.\n");
    }else{
        printf("o valor 3 nao esta presente no array.\n");
    }


    //chamada da questao 5//
    printf("o maior elemento do array eh:\n%d\n", Maiorvalorarray(array, 10));


    //chamada da questao 6//
    if(Eharrayordenado(array, 10)){
        printf("o array esta ordenado.\n");
    }else{
        printf("o array nao esta ordenado.\n");
    }

    return 0;
}
