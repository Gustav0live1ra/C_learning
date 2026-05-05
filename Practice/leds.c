#include <stdio.h>


int main(){
    int q;
    scanf("%d%*c", &q);
    char str[41];
    
    for (int i=0; i < q; i++){
        fgets(str, 41, stdin);
        
        int leds=0;
        
        for(int i=0; str[i] != '\0'; i++){
            if (str[i] == '2' || str[i] == '3' || str[i] == '5'){
                leds += 5;
            }else if(str[i] == '0' || str[i] == '6' || str[i] == '9'){
                leds += 6;
            }else {
                switch(str[i]){
                    case '1':
                        leds +=2;
                        break;
                    case '4':
                        leds +=4;
                        break;
                    case '7':
                        leds +=3;
                        break;
                    case '8':
                        leds +=7;
                        break;
                }
            }
        }
        
        printf("%d leds\n", leds);
    }
    
    return 0;
}