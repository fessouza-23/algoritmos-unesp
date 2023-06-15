#include <stdio.h>

#define LINHAS 3
#define COLUNAS 13

void lerPalpites(int palpites[][COLUNAS]) {
    printf("Digite os palpites:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Palpite %d.%d: ", i + 1, j + 1);
            scanf("%d", &palpites[i][j]);
        }
    }
}

void imprimirPalpites(int palpites[][COLUNAS]) {
    printf("Palpites:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", palpites[i][j]);
        }
        printf("\n");
    }
}

int calcularValor(int palpites[][COLUNAS], int V) {
    int numDuplos = 0;
    int numTriplos = 0;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (palpites[i][j] == 2) {
                numDuplos++;
            } else if (palpites[i][j] == 3) {
                numTriplos++;
            }
        }
    }

    return V * 2 * 3 * (numDuplos + numTriplos);
}

int main() {
    int palpites[LINHAS][COLUNAS];
    int V;
    char teste[100], revendedor[100];

    do {
        printf("Digite o nome do teste: ");
        scanf("%99s", teste);
        printf("Digite o nome do revendedor: ");
        scanf("%99s", revendedor);

        printf("Digite o valor da aposta (V): ");
        scanf("%d", &V);

        if (V <= 0) {
            printf("Valor da aposta inválido. Digite um valor positivo.\n");
        }
    } while (V <= 0);

    lerPalpites(palpites);
    imprimirPalpites(palpites);

    int valorPago = calcularValor(palpites, V);
    printf("=== Dados do Teste ===\n");
    printf("Nome do Teste: %s\n", teste);
    printf("Nome do Revendedor: %s\n", revendedor);
    printf("Valor a ser pago pelo apostador: %d\n", valorPago);

    return 0;
}
