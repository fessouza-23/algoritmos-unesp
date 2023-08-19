#include <stdio.h>
#define max 100

int main() {
    int vet[max], i, cont = 10;

    for (i = 0; i < max; i++, cont += 10)
        vet[i] = cont;

    for (i = 0; i < max; i++)
        printf("vet[%d] = %d\n", i, vet[i]);

    return 0;
}
