#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    
    char *str = malloc(n * 21 * sizeof(char) + 1);
    fgets(str, n*21 +1, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    for(int i=0; str[i] != '\0'; i++){
        if(i==0){
            if(str[i] == 'O' && str[i+1] == 'B' && str[i+3] == ' ' ||
               str[i] == 'U' && str[i+1] == 'R' && str[i+3] == ' ') {
                   str[i+2] = 'I';
               }
        } else if(i < strlen(str) - 3){
            if(str[i] == 'O' && str[i+1] == 'B' && str[i+3] == ' ' && str[i-1] == ' ' ||
               str[i] == 'U' && str[i+1] == 'R' && str[i+3] == ' ' && str[i-1] == ' '){
                   str[i+2] = 'I';
               }
        //if i == strlen(str) - 3;
        } else {
            if(str[i] == 'O' && str[i+1] == 'B' && str[i+3] == '\0' && str[i-1] == ' ' ||
               str[i] == 'U' && str[i+1] == 'R' && str[i+3] == '\0' && str[i-1] == ' '){
                   str[i+2] = 'I';
            }
        }
    }
    printf("%s\n", str);
    
    return 0;
}