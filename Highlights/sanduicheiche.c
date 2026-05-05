#include <stdio.h>
#include <string.h>

int main(){
    char str[35];
    
    while(scanf("%s", str) != EOF){
        int len = strlen(str);
        int tamERRO=0;
        
        
        for(int tam=1; tam<= len / 2; tam++){
            
            int fim_original = len - (tam *2);
            int fim_repetido = len - tam;
            
        //verifica se a string a partir de fim_repetido é igual a string a partir de fim_original com tam caracteres 
            if(strncmp(&str[fim_original], &str[fim_repetido], tam) == 0){
                tamERRO = tam;
            }
        }
        
        str[len - tamERRO] = '\0';
        printf("%s\n", str);
    }
    
    
    return 0;
}