#include <stdio.h>
#include <string.h>


void tirabarran(char *str) {
    int len = strlen(str);
    // Remove o \n e também o \r (se existir);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}


int main(){
    char senha[52];
    
    while(fgets(senha, 52, stdin) != NULL){
        int contA = 0, cont_a = 0, contint = 0, contothers = 0;
        tirabarran(senha);
        for (int i=0; senha[i] != '\0'; i++){
            if(senha[i] >= 'a' && senha[i] <= 'z'){
                cont_a++;
            }else if(senha[i] >= 'A' && senha[i] <= 'Z'){
                contA++;
            }else if(senha[i] >= '0' && senha[i] <= '9'){
                contint++;
            }else{
                contothers++;
            }
        }
        
        if (contA > 0 && cont_a > 0 && contint > 0 && contothers == 0 && strlen(senha) >=6 && strlen(senha) <= 32){
            printf("senha valida.\n");
        }else{
            printf("senha invalida.\n");
        }
        
    }
    
    return 0;
}