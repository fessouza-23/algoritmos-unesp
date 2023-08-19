#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    srand(time(NULL));
    printf("Gerando 5 numeros aleatorios: ");
    for(i = 1; i <= 5; i++)
        printf("\t%.2f\n", (rand() % 101)/100.);
    printf("Gerando 5 numeros aleatorios: ");
    for(i = 1; i <= 5; i++)
        printf("\t%.4f\n", (rand() % 10001)/10000.);
    return 0;
}