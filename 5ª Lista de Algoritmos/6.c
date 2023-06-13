#include <stdio.h>

int main(){
    int a, b, soma, i;
    do {
        soma = 0;
        do {
            printf("Digite dois valores positivos inteiros: ");
            scanf("%d %d", &a, &b);
        } while(a < 1 && b < 1);
        for(i = a; i <= b; i++){
            soma += i;
        }
        printf("Soma de valores entre %d e %d eh: %d\n", a, b, soma);
    } while(a < b);
    return 0;
}