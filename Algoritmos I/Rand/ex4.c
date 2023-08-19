#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, num, guess, quant = 0, x, y, aux;
    srand(time(NULL));
    do {
        printf("Digite o intervalo: ");
        scanf("%d %d", &x, &y);
        (x > y)? aux = x, x = y, y = aux : 0;
    } while(x < 0 && y < 0 || (y - x) < 2);
    num = rand() % (y - x + 1) + x;
    printf("Adivinhe o numero!\n");
    printf("Numero: %d\n", num);
    do {
        printf("Qual o numero?\n");
        scanf("%d", &guess);
        (guess > num)? printf("O valor eh menor!\n") : 0;
        (guess < num)? printf("O valor eh maior!\n") : 0;
        quant++;
    } while(guess != num);
    printf("\nBoa!\n%d tentativas.\n", quant);
    return 0;
}