#include <stdio.h>

int main() {
    int A[10], B[20], i, j, nA, nB, X[30], Y[10], Z[10], max;
    char resp;

    do {
        do {
            printf("Digite o tamanho do vetor A: [max=10]\n");
            scanf("%d", &nA);
            printf("Digite o tamanho do vetor B: [max=20]\n");
            scanf("%d", &nB);
        } while ((nA < 0 || nA > 10) && (nB < 0 || nB > 20));

        if (nB > nA) {
            max = nB;
        } else {
            max = nA;
        }

        for (i = 0; i < nA; i++) {
            printf("Valor %d do vetor A: ", i + 1);
            scanf("%d", &A[i]);
        }

        for (i = 0; i < nB; i++) {
            printf("Valor %d do vetor B: ", i + 1);
            scanf("%d", &B[i]);
        }
    } while (resp == 'S' || resp == 's');

    for (i = 0; i < nA; i++) {
        X[i] = A[i];
    }

    for (i = 0, j = 0; i < nB; i++, j++) {
        X[nA + j] = B[i];
    }

    int cont = 0;

    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            if (A[i] == B[j]) {
                Y[cont] = A[i];
                cont++;
                break;
            }
        }
    }

    int contZ = 0;
    int encontrado;

    for (i = 0; i < nA; i++) {
        encontrado = 1;
        for (j = 0; j < nB; j++) {
            if (A[i] == B[j]) {
                encontrado = 0;
            }
        }
        if (encontrado) {
            Z[contZ] = A[i];
            contZ++;
        }
    }

    for (i = 0; i < nA + nB; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    for (i = 0; i < cont; i++) {
        printf("Y[%d] = %d\n", i, Y[i]);
    }

    for (i = 0; i < contZ; i++) {
        printf("Z[%d] = %d\n", i, Z[i]);
    }

    return 0;
}
