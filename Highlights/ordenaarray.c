#include <stdio.h>



int OrdenaArray(int arr[],int  t){
    while(1){
        int cont = 0;
        
        for (int i=0; i<t-1; i++){
            if(arr[i] > arr[i+1]) {

                int aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;

                cont = 1;
            }
        }
        if(cont == 0){
            break;
        }
    }
}


int main(){
    int array[5] = {5,2,3,7,4};
    
    OrdenaArray(array, 5);
    for (int i=0; i<5; i++){
        printf("%d ", array[i]);
    }
    return 0;
}