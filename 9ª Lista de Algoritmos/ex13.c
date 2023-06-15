#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 40

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
    int m, n, i, j;

    do {
        do {
            printf("Quantidade de linhas: ");
            scanf("%d", &m);
            (m <= 0) ? printf("Valor invalido!\n") : 0;
        } while (m <= 0 || m > max);

        do {
            printf("Quantidade de colunas: ");
            scanf("%d", &n);
            (n <= 0) ? printf("Valor invalido!\n") : 0;
        } while (n <= 0 || n > max);

        int a[m][n], b[m][n], c[m][n];

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("B[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }

        system("cls");

        printf("Matriz A\n");
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        printf("Matriz B\n");
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }

        printf("Matriz C\n");
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }

    } while(reprocessamento());

    return 0;
}
