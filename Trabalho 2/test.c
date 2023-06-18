#include <stdio.h>

#define MAX_DIM 100

void lerMatriz(int matriz[][MAX_DIM], int dimensoes[], int num_dimensoes) {
    int i, j, k;

    printf("Digite os elementos da matriz:\n");

    if (num_dimensoes == 1) {
        for (i = 0; i < dimensoes[0]; i++) {
            printf("Elemento [%d]: ", i);
            scanf("%d", &matriz[i][0]);
        }
    } else {
        for (i = 0; i < dimensoes[0]; i++) {
            int nova_dimensoes[num_dimensoes - 1];
            for (j = 1; j < num_dimensoes; j++) {
                nova_dimensoes[j - 1] = dimensoes[j];
            }
            printf("Digite os elementos para a dimensão %d:\n", i);
            lerMatriz(matriz[i], nova_dimensoes, num_dimensoes - 1);
        }
    }
}

void mostrarMatriz(int matriz[][MAX_DIM], int dimensoes[], int num_dimensoes, int nivel_atual, char str_formatada[]) {
    int i, j, k;

    if (nivel_atual == num_dimensoes) {
        printf("%s", str_formatada);
        for (i = 0; i < dimensoes[nivel_atual - 1]; i++) {
            printf("%d ", matriz[i][0]);
        }
        printf("\n");
    } else {
        for (i = 0; i < dimensoes[nivel_atual - 1]; i++) {
            char nova_str_formatada[MAX_DIM];
            if (nivel_atual == 1) {
                sprintf(nova_str_formatada, "[%d]: ", i);
            } else {
                sprintf(nova_str_formatada, "%s[%d]: ", str_formatada, i);
            }
            mostrarMatriz(matriz[i], dimensoes, num_dimensoes, nivel_atual + 1, nova_str_formatada);
        }
    }
}

int main() {
    int matriz[MAX_DIM][MAX_DIM];
    int dimensoes[MAX_DIM];
    int num_dimensoes;
    int i;

    printf("Digite o número de dimensões da matriz: ");
    scanf("%d", &num_dimensoes);

    printf("Digite o tamanho de cada dimensão:\n");
    for (i = 0; i < num_dimensoes; i++) {
        printf("Dimensão %d: ", i + 1);
        scanf("%d", &dimensoes[i]);
    }

    lerMatriz(matriz, dimensoes, num_dimensoes);
    mostrarMatriz(matriz, dimensoes, num_dimensoes, 1, "");

    return 0;
}
