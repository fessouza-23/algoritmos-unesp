#include <stdio.h>

int main(){
    int x, y, result = 1, i;
    do {
        printf("Digite dois numeros inteiros positivos: ");
        scanf("%d %d", &x, &y);
    } while(x < 1 && y < 1);
    for(i = 1; i <= y; i++){
        result *= x;
    }
    printf("%d^%d=%d", x, y, result);
    return 0;
}