#include <stdio.h>
#include <math.h>


int ResolveEquacao2grau(float a,float b, float c, float *x1, float *x2){
    float delta = (b*b) - (4*a*c);
    
    if (a==0){
        printf("os coeficientes nao formam uma equacao do segundo grau\n");
        return -1;
    } 
    if (delta < 0){
        printf("nao existe raizes reais para essa equacao do segundo grau\n");
        return -2;
    }

    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);
    return 0;
}


int main(){
    float a,b,c, x1, x2;
    int retorno;
    
    printf("digite respectivamente os coeficientes de a b c da equacao: ");
    scanf("%f%f%f", &a,&b,&c);

    retorno = ResolveEquacao2grau(a,b,c, &x1,&x2);
    
    if (retorno == 0){
        printf("X1 = %.2f\nX2 = %.2f\n", x1, x2);
    }
return 0;
}