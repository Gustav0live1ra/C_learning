#include <stdio.h>

                                    //basic operations calculator//
int main()
{   int n1, n2, opc = 0;
    printf("1° valor: ");
    scanf("%d", &n1);
    printf("2° valor: ");
    scanf("%d", &n2);
    printf("\n[1] somar\n[2] multiplicar\n[3] subtrair\n[4] dividir\n[5] resto da divisão\n");
    do {
        printf("sua escolha: ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("%d", n1 + n2);
                break;
            case 2:
                printf("%d", n1 * n2);
                break;
            case 3:
                printf("%d", n1 - n2);
                break;
            case 4:
                printf("%d", n1 / n2);
                break;
            case 5:
                printf("%d", n1 % n2);
                break;
            default:
                printf("digite uma opção válida.\n");
                continue;
        }
    } while(opc < 1 || opc > 5);
    return 0;
}
