#include <stdio.h>
#define max 100

int main() {
    int vet[max], i, j;

    for (i = 0; i < max; i++) {
        vet[i] = 0;
        for (j = 0; j <= max; j++) {
            if (i == j * j) {
                vet[i] = 1;
                break;
            }
        }
    }

    for (i = 0; i < max; i++) {
        printf("vet[%d] = %d\n", i, vet[i]);
    }

    return 0;
}
