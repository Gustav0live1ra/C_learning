//mesma ideia de ordenação de um array, porém com um array de strings com n dimensões

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int N;
    
    while(scanf("%d", &N) != EOF){
        char str[N][6];
        //preenchimento do array de strings
        for(int i=0; i < N; i++){
            scanf("%s", str[i]);
        }
        //ordenação do array de strings
        int v=1;
        while(v){
            int cont=0;
            for(int i=0; i < N-1; i++){
                if( atoi(str[i]) > atoi(str[i+1]) ){
                    char aux[6];
                    strcpy(aux, str[i+1]);
                    strcpy(str[i+1], str[i]);
                    strcpy(str[i], aux);
                    
                    cont ++;
                }
            }
            if(!cont){
                v=0;
            }
        }
        //printar array de n dimensões ja ordenado
        for(int i=0; i < N; i++){
            printf("%s\n", str[i]);
        }
    }
    
    return 0;
}