#include<stdio.h>
//converte decimal para binario

int Calculatam(int n){
    int tam = 0;
    while(n > 0){
        n = n/2;
        tam +=1;
    } 
    return tam;
}

int main(){
    int n, tam, resto, cont=0;
    scanf("%d", &n);
    tam = Calculatam(n);

    int binario[tam];
    while(n > 0){
        resto = n % 2;
        binario[cont] = resto;
        n = n / 2;

        cont+=1;
    }


    for (int i=tam-1; i >= 0; i--){
        printf("%d", binario[i]);
    }
    return 0;
}