#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, num, guess, quant = 0;
    srand(time(NULL));
    num = rand() % 1001;
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