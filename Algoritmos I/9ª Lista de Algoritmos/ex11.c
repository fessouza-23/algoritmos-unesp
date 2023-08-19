#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int reprocessamento() {
    char resp;
    do {
        printf("Deseja executar novamente? (S/N): ");
        scanf(" %c", &resp);
    } while (tolower(resp) != 's' && tolower(resp) != 'n');
    
    if (tolower(resp) == 's') {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    int m, n, i, j, somaLin, somaTds;

    do {
        do {
            printf("Quantidade de linhas: ");
            scanf("%d", &m);
            (m <= 0) ? printf("Valor invalido!\n") : 0;
        } while (m <= 0);

        do {
            printf("Quantidade de colunas: ");
            scanf("%d", &n);
            (n <= 0) ? printf("Valor invalido!\n") : 0;
        } while (n <= 0);

        int a[m][n];

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }

        somaTds = 0;

        for (i = 0; i < m; i++) {
            somaLin = 0;
            for (j = 0; j < n; j++) {
                somaLin += a[i][j];
                somaTds += a[i][j];
            }
            printf("Soma da linha %d: %d\n", i + 1, somaLin);
        }

        printf("Soma de todos os elementos: %d\n", somaTds);
    } while(reprocessamento());

    return 0;
}
