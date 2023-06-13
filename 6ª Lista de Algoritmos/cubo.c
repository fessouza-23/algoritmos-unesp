#include <stdio.h>

int main(){
    int n, i, j, cont = 1, s;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &n);
    } while(n <= 0);
    for(i = 1; i <= n; i++){
        s = 0;
        for(j = 1; j <= i; j++){
            s += cont;
            cont += 2;
        }
        printf("%d\n", s);
    }
    return 0;
}