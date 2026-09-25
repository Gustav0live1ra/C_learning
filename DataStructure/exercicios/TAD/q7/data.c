#include<stdio.h>
#include<stdlib.h>
#include"data.h"

struct data{
    int dia;
    int mes;
    int ano;
};

Data *criarData(int dia, int mes, int ano){
    Data *data = malloc(sizeof(*data));
    if(data ==NULL)return NULL;

    data->ano = ano;
    data->mes = mes;
    data->dia = dia;

    return data;
}
void liberarData(Data *d){
    free(d);
}

char *getData(Data *d){
    if(d == NULL) return NULL;
    char *buffer = malloc(11 * sizeof(char)); // formato dd/mm/yyyy → 10 + '\0'
    if(buffer == NULL) return NULL;
    sprintf(buffer, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
    return buffer;
}
int compararDatas(Data *d1, Data *d2){
    if(d1 == NULL || d2 == NULL) return -1;
    if(d1->dia==d2->dia && d1->mes==d2->mes && d1->ano==d2->ano){
        return 0; //diferença 0
    }
    int anos = abs(d1->ano - d2->ano);
    int meses = abs(d1->mes - d2->mes);
    int dias= abs(d1->dia - d2->dia);

    dias += anos * 365; 
    dias += meses * 30;

    return dias; //diferença em dias
}
void avancarDias(Data *d, int qnt){
    if(d!=NULL){
        d->ano += qnt / 365;
        qnt = qnt % 365;
        d->mes += qnt/ 30;
        qnt = qnt % 30;
        d->dia += qnt;
    } 
}