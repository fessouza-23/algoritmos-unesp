#include <stdio.h>
#include <stdlib.h>
#define tam 3

int reprocessamento() {
    int num;

    do {
        printf("\nExecutar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &num);
        if (num != 1 && num != 2) printf("Valor invalido\n");
    } while (num != 1 && num != 2);

    return num;    
}

int main() {
    int v[tam][tam], i, j, valRef, soma1, soma2, ehQuadradoMagico;

    do {
        system("cls");
        for (i = 0; i < tam; i++) {
            for (j = 0; j < tam; j++) {
                printf("Elemento [%d][%d]: ", i+1, j+1);
                scanf("%d", &v[i][j]);
            }
        }

        // Valor de referência para os cálculos = soma da linha 0
        valRef = v[0][0] + v[0][1] + v[0][2];

        // Soma das linhas e colunas
        ehQuadradoMagico = 1; // Inicialmente assume que é quadrado mágico
        for (i = 0; i < tam; i++) {
            soma1 = 0;
            soma2 = 0;
            for (j = 0; j < tam; j++) {
                soma1 += v[i][j];
                soma2 += v[j][i];
            }
            if (soma1 != valRef || soma2 != valRef) {
                ehQuadradoMagico = 0;
                break;
            }
        }

        // Diagonal principal
        soma1 = 0;
        for (i = 0; i < tam; i++) {    
            soma1 += v[i][i];
        }

        if (soma1 != valRef) {
            ehQuadradoMagico = 0;
        }

        // Diagonal secundária
        soma1 = 0;
        for (i = 0; i < tam; i++) {    
            soma1 += v[i][tam - 1 - i];
        }

        if (soma1 != valRef) {
            ehQuadradoMagico = 0;
        }

        if (ehQuadradoMagico) {
            printf("Eh quadrado magico\n");
        } else {
            printf("Nao eh quadrado magico\n");
        }

    } while (reprocessamento() == 1);

    return 0;
}
