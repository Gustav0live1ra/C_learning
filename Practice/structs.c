#include <stdio.h>
#include <string.h>

#define tam 3

typedef struct {
    char nome[51];
    int idade;
    float peso;
    float altura;
} data_person;


int main(){
    //typedef struct data_person data_person;
    data_person person[3];
    

    for(int i=0; i<tam; i++){
        printf("digite o Nome da %d pessoa: ", i + 1);
        fgets(person[i].nome, 51, stdin);
        person[i].nome[strcspn(person[i].nome, "\n")] = '\0';

        puts("sua idade: ");
        scanf("%d%*c", &person[i].idade);

        puts("seu peso: ");
        scanf("%f%*c", &person[i].peso);

        puts("sua altura: ");
        scanf("%f%*c", &person[i].altura);

    }
    for(int i =0; i<tam; i++){
        
        if(i==0){
            printf("idade de %s: %d\n", person[i].nome, person[i].idade);
            printf("altura de %s: %.2f\n", person[i].nome, person[i].altura);

        }else if(i==2){
            printf("peso de %s: %.2f\n", person[i].nome, person[i].peso);
            printf("altura de %s: %.2f\n", person[i].nome, person[i].altura);

        } 

    }
    return 0;
}
