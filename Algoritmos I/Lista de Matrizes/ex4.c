#include <stdio.h>

int main() {
    char resp;

    do {
        int m, n, i, j;

        do {
            printf("Digite o numero de linhas: ");
            scanf("%d", &m);

            printf("Digite o numero de colunas: ");
            scanf("%d", &n);
        } while (m <= 0 && n <= 0);

        float A[m][n], B[m][n], result;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i + 1, j + 1);
                scanf("%f", &A[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("B[%d][%d] = ", i + 1, j + 1);
                scanf("%f", &B[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                result += A[i] * b[i]
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%10.2f + %.2f = %.2f\n", A[i][j], B[i][j], C[i][j]);
            }
        }

        do {
            printf("\nExecutar novamente? (s/n)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');
    
    return 0;
}
