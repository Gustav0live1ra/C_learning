#include <stdio.h>

                                        //tabuadav1//

int main()
{
    int n;
    printf("digite um número para ver sua tabuada: ");
    scanf("%d", &n);
    for (int i=1; i < 11; ++i) {
        printf("%d X %d = %d \n", n, i, n*i);
    }
    return 0;
}
