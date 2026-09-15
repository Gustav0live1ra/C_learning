#include<stdio.h>

void MaxMin(int *p, int n, int *MAX,int *MIN){
    if (n <= 0) return;

    p++; //já comeca deslocando pq max e min começam com o array[0]
    for (int i = 1; i < n; i++){
        if(*p > *MAX) *MAX = *p;
        if(*p < *MIN) *MIN = *p;

        p++;
    }
    
}

int main(void){
    int array[6] ={12, 7, 30, 4, 18, 9};
    int Max= array[0];
    int Min= array[0];

    int *p = array;

    MaxMin(p, 6, &Max, &Min);
    printf("%d %d", Min, Max);

    return 0;
}