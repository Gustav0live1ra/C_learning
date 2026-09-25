#include <stdio.h>

void ordenaPar(int *a,int *b){
    if(*a <= *b) return;
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void){
    int a = 9;
    int b = 5;

    ordenaPar(&a, &b);

    printf("%d %d", a, b);
    return 0;
}