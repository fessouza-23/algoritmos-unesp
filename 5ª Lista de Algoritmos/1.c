#include <stdio.h>

int main(){
    int n, num, i, fat, j;
    do {
        printf("Digite a quantidade de fatoriais a serem feitos: ");
        scanf("%d", &n);
    } while(n < 1);
    for(i = 1; i <= n; i++){
        do {
            printf("Digite um numero inteiro positivo: ");
            scanf("%d", &num);
        } while(num < 1);
        fat = 1;
        for(j = num; j >= 1; j--){
            fat *= j;
        }
        printf("fatorial de %d = %d\n", num, fat);
    }
    return 0;
}