#ifndef DATA_H
#define DATA_H

typedef struct data Data;

Data *criarData(int dia, int mes, int ano);
void liberarData(Data *d);
char *getData(Data *d);
int compararDatas(Data *d1, Data *d2);    //retorna a diferença em dias entre uma data e outra, caso haja uma data nula retorna -1.
void avancarDias(Data *d, int qnt);


#endif