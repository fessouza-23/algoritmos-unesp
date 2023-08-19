#include <stdio.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

float calcularSomaLinha(float matriz[MAX_LINHAS][MAX_COLUNAS], int m, int n, int linha) {
    float soma = 0;

    if (linha >= 0 && linha < m) {
        for (int j = 0; j < n; j++) {
            soma += matriz[linha][j];
        }
    }

    return soma;
}

int main() {
    float matriz[MAX_LINHAS][MAX_COLUNAS];
    int m, n, linha;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0 || m > MAX_LINHAS || n > MAX_COLUNAS) {
        printf("Tamanho da matriz inválido.\n");
        return 0;
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento[%d, %d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Digite o numero da linha para calcular a soma: ");
    scanf("%d", &linha);

    float soma = calcularSomaLinha(matriz, m, n, linha - 1);
    printf("A soma dos elementos da linha %d é %.2f.\n", linha, soma);

    return 0;
}
