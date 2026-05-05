#include <stdio.h>
#include <stdlib.h>


void zera_sete(char *str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == '7'){
            str[i] = '0';
        }
    }
}

int main(){
    char n1[6], n2[6], op;
    char strResult[41];
    
    scanf("%s %c %s", n1, &op, n2);

    zera_sete(n1);
    zera_sete(n2);
    
    switch(op){
        case 'x': sprintf(strResult, "%d", (atoi(n1) * atoi(n2)) ); break;
        case '+': sprintf(strResult, "%d", (atoi(n1) + atoi(n2)) ); break;
    }
    
   
    zera_sete(strResult);
    
    printf("%d", atoi(strResult));
    return 0;
}
