#include <stdio.h>

void removeitens(float array[], int *tam, int item) {
     if (item < 0 || item >= *tam ) {
        printf("erro ao remover este item");
        return;
     }
     for (item; item < *tam - 1; ++item) {
        array[item] = array[item + 1];
     }
     (*tam)--;
 }

int main()
{
    int tamanho;
    printf("quantidade de itens no carrinho: ");
    scanf("%d",&tamanho);

    float array[tamanho];
    float valor, total = 0;

    printf("O orcamento eh de 1599,99 R$.\n");

    for (int i = 0; i < tamanho; ++i){
        printf("valor do %d item: ", i + 1);
        scanf("%f", &valor);
        array[i] = valor;
        total += valor;
    }

    printf("Sua lista de compras: \n");

    for ( int i = 0; i < tamanho; ++i ){  //sizeof(array) / sizeof(array[0]) --- sizeof retorna o valor de bytes,
        printf("Item %d: %.2f R$ \n", i+1, array[i]);                             // divide o total pelo valor de 1 para obter o tamanho do array
    }

    printf("o total em compras sera de: %.2f R$\n", total);
    
    if (total <= 1600)
    {
        printf("dentro do orcamento, pode prosseguir com a compra!\n");
     } else {

         while (total > 1600){
            int Itemremovido;
            puts("\testourou o orcamento!");
            while(1){
                printf("digite a posicao do item da lista a ser retirado do carrinho: ");
                scanf("%d", &Itemremovido);
                if (Itemremovido <= tamanho && Itemremovido > 0){
                    break;
                }else{
                    puts("digite uma posicao valida.");
                }
            }
            Itemremovido -= 1;
            total -= array[Itemremovido];

            removeitens(array, &tamanho, Itemremovido);

            printf("sua lista de compras agora eh: \n");
            for (int i = 0; i < tamanho; ++i){
                printf("Item %d: %.2f R$ \n", i + 1, array[i]);
            }

            printf("o total em compras sera de: %.2f R$\n", total);

        }if (total <= 1600)
            {
                puts("agora sim, carrinho dentro do orcamento!");
                puts("\t!!boas compras!!");
            }
 
    }
    
    return 0;
}
