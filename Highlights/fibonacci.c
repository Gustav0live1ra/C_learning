#include <stdio.h>

int main(){
    int n, a=0, b=1, next;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        
        printf("%d%c", a, (i == n-1) ? '\n' : ' ');
        
        next = a+b;
        
        a = b;
        b = next;
        
    }
    
    return 0;
}