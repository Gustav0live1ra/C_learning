#include <stdio.h>
#include <string.h>


int verificapalindromo(const char *str){
    int last = strlen(str) - 1;
    int valor_verdade = 1;
    
    // conforme i incrementa, um lado da comparação aumenta e o outro diminui, assim consegue-se comparar a ordem normal com a inversa.
    for(int i=0; i < last/2; i++){
        if(str[i] != str[last - i]){
            valor_verdade = 0;
        }
    }
    
    return valor_verdade;
}


void tirabarran(char *str) {
    int len = strlen(str);
    // Remove o \n e também o \r (se existir)
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}


int main(){
    char risada[52], vogal[52];
    fgets(risada, 52, stdin);
    tirabarran(risada);
    
    //desconsidera as consoantes e adiciona apenas as vogais na string vogal.
    int i2 = 0;
    for(int i1=0; risada[i1] != '\0'; i1++){
        if(risada[i1] == 'a' || risada[i1] == 'e' || risada[i1] == 'i' || risada[i1] == 'o' || risada[i1] == 'u'){
            vogal[i2] = risada[i1];
            i2++;
        }
    }
    vogal[i2]= '\0';
    

    if(verificapalindromo(vogal)){
        puts("S");
    }else{
        puts("N");
    }
    
    return 0;
}
