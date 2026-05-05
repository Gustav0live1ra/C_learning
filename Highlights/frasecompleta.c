#include <stdio.h>
#include <string.h>


void tirabarran(char *str) {
    int len = strlen(str);
    
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}


int main(){
    int n;
    scanf("%d%*c", &n);
    
    while(n--){
        char letrasquejaforam[27] = {' ', '\0'};
        int qletras=0;
        
        char frase[250];
        fgets(frase,250, stdin);
        tirabarran(frase);
        
        int i2=0;
        for(int i=0; frase[i] != '\0'; i++){
            if(frase[i] >= 'a' && frase[i] <= 'z'){

                if(i == 0){
                    letrasquejaforam[i2] = frase[i];
                    i2++;
                    
                }else{
                    //verifica se a letra atual da frase é repetida ou não.
                    int v = 1;
                    for(int i3=0; letrasquejaforam[i3] != '\0'; i3++){
                        
                        if(frase[i] == letrasquejaforam[i3]){
                            v = 0;
                        }
                    }
                    if(v){
                        letrasquejaforam[i2] = frase[i];
                        i2++;
                    }
                }
            }
        }

        letrasquejaforam[i2] = '\0';

        if(strlen(letrasquejaforam) == 26){
            puts("frase completa");
        }else if(strlen(letrasquejaforam) >= 13){
            puts("frase quase completa");
        }else{
            puts("frase mal elaborada");
        }
    }
    
    return 0;
}
