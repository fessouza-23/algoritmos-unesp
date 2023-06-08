#include <stdio.h>

int main(){
    int carac;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &carac);
    } while(carac < 1);
    printf("O caractere corresponde ao numero no ASCII eh: %c", carac);
    return 0;
}