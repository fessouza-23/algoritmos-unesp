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

void printMatriz(int matriz[][100], int n) {
    int i, j;
    printf("MATRIZ:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int somaElementosAbaixoDiagonal(int matriz[][100], int n) {
    int i, j, soma = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

int main() {
    int linhas, colunas, i, j;

    do {
        printf("Digite a quantidade de linhas da matriz: ");
        scanf("%d", &linhas);
        
        printf("Digite a quantidade de colunas da matriz: ");
        scanf("%d", &colunas);

        int matriz[100][100];

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                printf("Elemento [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
            }
        }

        system("cls");

        printMatriz(matriz, linhas);

        int soma = somaElementosAbaixoDiagonal(matriz, linhas);
        printf("Soma dos elementos abaixo da diagonal principal: %d\n", soma);

    } while(reprocessamento());

    return 0;
}
