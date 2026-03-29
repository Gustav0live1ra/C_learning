#include <stdio.h>
#include <math.h>

float Delta(float a,float b,float c){
    float d = (b*b) - (4*a*c);
    return d;
}


float X1(float b, float raizDelta, float a){
    raizDelta = sqrt(raizDelta);
    return ((-1*b) + raizDelta) / 2*a;
}


float X2(float b,float raizDelta, float a){
    raizDelta = sqrt(raizDelta);
    return ((-1*b) - raizDelta) / 2*a;
}


int main(){
    float a,b,c,delta;
    scanf("%f%f%f", &a,&b,&c);
    
    if(a == 0){
        printf("o coeficiente 'a' eh zero, logo essa nao eh uma equação do segundo grau.\n");
        return 1;
    }
    // chamada da função Delta //
    delta=Delta(a,b,c);

    if(delta<0){
        printf("o delta deu negativo, logo nao existem raizes reais para essa equação do segundo grau.\n");
        return 2;
    }


    printf("X1 = %f\nX2 = %f\n", X1(b,delta,a), X2(b,delta,a));
    return 0;
}