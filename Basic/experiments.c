#include <stdio.h>

int main(){
    int n,ctot=0,contR=0, contC=0, contS=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int q;
        char tcobaia;
        scanf("%d %c", &q, &tcobaia);
        ctot+=q;

        switch (tcobaia){
            case 'C':
                contC +=q;
                break;
            case 'R':
                contR +=q;
                break;
            case 'S':
                contS +=q;
                break;
        }

    }
    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n", ctot, contC,contR,contS);
    printf("Percentual de coelhos: %.2f %\n", (float)contC *100/ctot);
    printf("Percentual de ratos: %.2f %\n", (float)contR *100/ctot);
    printf("Percentual de sapos: %.2f %\n", (float)contS *100/ctot);
    return 0;
}