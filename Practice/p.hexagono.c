#include <stdio.h>
#include <math.h>


void Calculahexagono(float lado, float *area, float *perimetro){
    *area = ((3 * (lado*lado)) * sqrt(3)) / 2;
    
    *perimetro = 6*lado;
}


int main(){
    float lado, area=0,perimetro=0;
    scanf("%f", &lado);

    Calculahexagono(lado, &area, &perimetro);

    printf("area: %.2f\nperimetro: %.2f\n", area ,perimetro);

    return 0;
    
}