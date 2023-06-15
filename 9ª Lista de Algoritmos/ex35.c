#include <stdio.h>

#define linhas 8
#define colunas 8
#define peao 1
#define cavalo 3
#define bispo 3
#define torre 5
#define rainha 10
#define rei 50

void calcularValorPecas(char tabuleiro[][colunas]) {
    int i, j;
    int valorTotal = 0;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            switch (tabuleiro[i][j]) {
                case ' ':
                    valorTotal += 0;
                    break;
                case 'P':
                    valorTotal += peao;
                    break;
                case 'C':
                    valorTotal += cavalo;
                    break;
                case 'B':
                    valorTotal += bispo;
                    break;
                case 'T':
                    valorTotal += torre;
                    break;
                case 'R':
                    valorTotal += rainha;
                    break;
                case 'K':
                    valorTotal += rei;
                    break;
            }
        }
    }

    printf("Valor total das peças: %d\n", valorTotal);
}

int main() {
    char tabuleiro[linhas][colunas];
    int i, j;

    printf("Insira os valores do tabuleiro de xadrez:\n");
    printf("Valores validos: ' ' (espaço vazio), 'P' (peao), 'C' (cavalo), 'B' (bispo), 'T' (torre), 'R' (rainha), 'K' (rei)\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            tabuleiro[i][j] = getchar();
            if (tabuleiro[i][j] != ' ' && tabuleiro[i][j] != 'P' && tabuleiro[i][j] != 'C' && tabuleiro[i][j] != 'B' && tabuleiro[i][j] != 'T' && tabuleiro[i][j] != 'R' && tabuleiro[i][j] != 'K') {
                printf("Valor invalido! Insira um valor valido.\n");
                j--;
            }
        }
        // Descartar o caractere de nova linha (\n) após cada linha do tabuleiro
        getchar();
    }

    printf("\nTabuleiro de Xadrez:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    calcularValorPecas(tabuleiro);

    return 0;
}
