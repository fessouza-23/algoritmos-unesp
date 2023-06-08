#include <stdio.h>
#define max 100

int main() {
    int vet[max], i;

    for (i = 0; i < max; i++)
        vet[i] = 15;

    for (i = 0; i < max; i++)
        printf("vet[%d] = %d\n", i, vet[i]);

    return 0;
}
