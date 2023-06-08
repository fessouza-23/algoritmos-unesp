#include <stdio.h>

int main(){
    int i, j, num;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    } while(num < 1);
    for(i = num; i >= 1; i--){
        for(j = 1; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}