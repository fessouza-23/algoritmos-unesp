#include <stdio.h>
#include <stdlib.h>

int main() {
    char resp;
    int m, n, i, j;

    do {
        do {
            printf("Digite o numero de linhas: ");
            scanf("%d", &m);

            printf("Digite o numero de colunas: ");
            scanf("%d", &n);
        } while (m <= 0 && n <= 0);

        float A[m][n], soma = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i + 1, j + 1);
                scanf("%f", &A[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                soma += A[i][j];
            }
        }

        printf("Soma de todos os numeros da matriz: %.2f\n", soma);

        do {
            printf("Executar novamente? (s/n)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
