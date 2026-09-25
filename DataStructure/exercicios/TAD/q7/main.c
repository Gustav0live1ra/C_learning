#include <stdio.h>
#include "data.h"

int main(){
    Data *data1 = criarData(1,6,2007);
    Data *data2= criarData(2, 7, 2008);

    avancarDias(data1, 389);

    printf("Data1: %s\n",getData(data1));
    printf("Data2: %s\n",getData(data2));

    int diferenca = compararDatas(data1, data2);
    if(diferenca != -1){
        printf("A diferença entre data1 e data2 é de %d dias", diferenca);
    }

    liberarData(data1);
    data1=NULL;
    liberarData(data2);
    data2=NULL;

    return 0;

}