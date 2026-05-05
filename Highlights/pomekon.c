#include <stdio.h>
#include <string.h>


int main(){
    int N;
    scanf("%d%*c", &N);
    
    char str[1005];
    char arraystr[N][1005];
    
    int i3 = 0;
    for (int i=0; i<N; i++){
        scanf("%s", str);
        
        if(i==0){
            strcpy(arraystr[i3], str);
            i3++;
        }else{

            int v=1;
            
            for(int i2=0; i2 < i3; i2++){
            
                if(!strcmp(str, arraystr[i2])){
                    v=0;
                    break;
                }

            }
            if(v){
                strcpy(arraystr[i3], str);
                i3++;
            }
        }
    }
    
    
    printf("Falta(m) %d pomekon(s).\n", 151 - i3);

    return 0;
}