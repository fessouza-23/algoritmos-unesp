#include <stdio.h>
#include <stdlib.h>

int main() {
    int contNulos, i, j, cont, sum, ehMatrizPermut = 1;

    printf("Digite a dimensao quadrada da matriz: ");
    scanf("%d", &cont);

    int A[cont][cont];

    system("cls");

    printf("Digite os valores da matriz por linha\n");
    for (i = 0; i < cont; i++) {
        for (j = 0; j < cont; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < cont; i++) {
        contNulos = 0;
        sum = 0;
        for (j = 0; j < cont; j++) {
            if (A[i][j] == 0) contNulos++;
            sum += A[i][j];
        }
        if (sum != 1  || contNulos != (cont-1)) {
            ehMatrizPermut = 0;
            break;
        }
    }

    for (j = 0; j < cont; j++) {
        contNulos = 0;
        sum = 0;
        for (i = 0; i < cont; i++) {
            if (A[i][j] == 0) contNulos++;
            sum += A[i][j];
        }
        if (sum != 1 || contNulos != (cont-1)) {
            ehMatrizPermut = 0;
            break;
        }
    }

    if (ehMatrizPermut) {
        printf("Eh matriz de permutacao\n");
    } else {
        printf("Nao eh matriz de permutacao\n");
    }

    return 0;
}
