#include <stdio.h>
#include <stdlib.h>

#define max 30

int main() {
    char resp;
    int n, i;

    do {
        do {
            printf("Digite o numero de linhas (entre 1 e %d): ", max);
            scanf("%d", &n);

            if (n <= 0 || n > max) {
                printf("Valor invalido. Tente novamente.\n");
            }
        } while (n <= 0 || n > max);

        float A[max], B[max];

        for (i = 0; i < n; i++) {
            printf("A[%d] = ", i + 1);
            scanf("%f", &A[i]);
        }

        for (i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                B[i-1] = A[i-1] * 2;
            } else {
                B[i-1] = A[i-1] / 2;
            }
        }

        for (i = 0; i < n; i++) {
            printf("%.2f ", B[i]);
        }

        do {
            printf("\nExecutar novamente? (s/n)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
