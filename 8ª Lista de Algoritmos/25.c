#include <stdio.h>
#define max 100

int main() {
    int T1, T2, num, i, cont, j, vMenor;
    float A[max], B[max];

    do {
        printf("Tamanho do vetor A: obs[max=100]\n");
        scanf("%d", &T1);
        printf("Tamanho do vetor B: obs[max=100]\n");
        scanf("%d", &T2);
    } while ((T1 <= 0 || T1 > 100) && (T2 <= 0 || T2 > 100));

    if (T1 > T2) {
        vMenor = T2;
    } else {
        vMenor = T1;
    }

    for (i = 0; i < T1; i++) {
        printf("valor %d. do vetor A: ", i + 1);
        scanf("%f", &A[i]);
    }

    for (i = 0; i < T2; i++) {
        printf("valor %d. do vetor B: ", i + 1);
        scanf("%f", &B[i]);
    }

    float C[T1 + T2];
    j = 0;
    cont = 0;
    while (cont < vMenor) {
        C[j] = A[cont];
        C[j + 1] = B[cont];
        cont++;
        j += 2;
    }

    while (cont < T1) {
        C[j] = A[cont];
        cont++;
        j++;
    }

    while (cont < T2) {
        C[j] = B[cont];
        cont++;
        j++;
    }

    for (i = 0; i < (T1 + T2); i++) {
        printf("C[%d] = %.1f\n", i, C[i]);
    }

    return 0;
}
