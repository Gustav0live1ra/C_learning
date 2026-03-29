#include <stdio.h>
#include <math.h>


int Ehtrianguloretangulo(int a, int b, int c){
    if( (c*c) == (a*a)+(b*b) ){
        return 1;
    }
    return 0;
}


int Formatrianguloretangulo(int a, int b, int c){
    int array[3]= {a,b,c};
    int cont=0;
    
    for(int i=0; i<3; i++){
        if (array[i] <=0){
            cont+=1;
        }
    }
    if (cont>1){
        return -1;
                                                                        //codigo incompleto(faltou paciencia)
    } else if(a<=0){
        a= sqrt(c-b);
        return  (a < 0) ? a : -1;

    } else if(b<=0){
        b= sqrt(c-a);
        return (b < 0) ? b : -1;

    } else if(c<=0){
        c= sqrt(a-b);
        return (c < 0) ? c : -1;
    }

    
}


int main(){
    int a,b,c;
    while(1){

        printf("digite os dois catetos do triangulo retangulo: ");
        scanf("%d%d", &a,&b);
        printf("agora digite a hipotenusa: ");
        scanf("%d", &c);

        if (c > a && c > b){
            break;
        }
        printf("valores inválidos.\n");
    }


    if(Ehtrianguloretangulo(a,b,c)){
        printf("Os valores formam um triangulo retangulo.\n");
    }else{
        int resultado;
        printf("os valores nao formam um triangulo retangulo\n");
        resultado = Formatrianguloretangulo(a,b,c);
        if(resultado != -1){

        }

    }

    return 0;
}