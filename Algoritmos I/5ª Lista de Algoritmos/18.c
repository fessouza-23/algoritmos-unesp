#include <stdio.h>

int main(){
    int n, i, cont = 2;
    do {
        printf("Digite um numero: ");
        scanf("%d", &n);
    } while(n < 1);
    for(i = 1; i <= n; i++){
        printf("%d ", cont);
        cont += 2;
    }
    return 0;
}