#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    rand() 0 a 32767
    de 0 a 10: rand() % 11;
    de 0 a 35: rand() % 36;
    de 1 a 50: rand() % 50 + 1; -> de 0 a 49
    de 10 a 23: rand() % 14 + 10;
    Formula para gerar valores aleatorios entre 2 numeros: 
        "(n2 - n1 + 1) + n1";
*/

int main(){
    int i;
    srand(time(NULL)); // time funciona como uma Seed (parametro) para o srand gerar os numeros, fazendo com que seja sempre aleatorio.
    printf("Gerando 5 numeros aleatorios: ");
    for(i = 1; i <= 5; i++)
        printf("\t%d\n", rand() % 11);
    return 0;
}