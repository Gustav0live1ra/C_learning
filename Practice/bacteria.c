#include <stdio.h>
#include <string.h>


int main(){
    char str1[102], str2[102];
    
    while(1){
        fgets(str1,102,stdin);
        fgets(str2,102,stdin);
        
        str1[strcspn(str1, "\n")] = '\0';
        str2[strcspn(str2, "\n")] = '\0';
        
        if(strlen(str1) == 0 && strlen(str2) == 0){
            break;
        }
    
        //verifica se str2 está contida em str1
        if(strstr(str1, str2) != NULL){
            puts("Resistente");
        }else{
            puts("Nao resistente");
        }
        
        
    }
    return 0;
}