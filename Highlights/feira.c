#include <stdio.h>
#include <string.h>

int main(){
    int N,M,P;

    scanf("%d%*c", &N);
    while(N--){
        float somatotal=0;

        scanf("%d%*c", &M);
        char str[M][51];
        float arr[M];
        
        for(int i=0; i < M; i++){
            scanf("%s%*c %f%*c", str[i], &arr[i]);
        }
        
        scanf("%d%*c", &P);
        char produto[51];
        int valor=0;
        
        while(P--){
            scanf("%s%*c %d%*c", produto, &valor);
            
            for(int i=0; i < M; i++){
                if(!strcmp(produto, str[i])){
                    somatotal = somatotal + (valor * arr[i]);
                     break;
                }
            }
        }
        
        printf("R$ %.2f\n", somatotal);
        
    }
    
    
    return 0;
}