#include <stdio.h>

#define ESTADOS 26
#define MUNICIPIOS 10

void lerPopulacao(int populacao[][MUNICIPIOS]) {
    for (int i = 0; i < ESTADOS; i++) {
        printf("Estado %d:\n", i + 1);
        for (int j = 0; j < MUNICIPIOS; j++) {
            printf("Populacao do municipio %d: ", j + 1);
            scanf("%d", &populacao[i][j]);
        }
        printf("\n");
    }
}

void imprimirPopulacao(int populacao[][MUNICIPIOS]) {
    printf("Populacao dos municipios mais populosos:\n");
    for (int i = 0; i < ESTADOS; i++) {
        printf("Estado %d:\n", i + 1);
        for (int j = 0; j < MUNICIPIOS; j++) {
            printf("Municipio %d: %d habitantes\n", j + 1, populacao[i][j]);
        }
        printf("\n");
    }
}

void encontrarMunicipioMaisPopuloso(int populacao[][MUNICIPIOS], int *estado, int *municipio) {
    int maxPopulacao = populacao[0][0];
    *estado = 1;
    *municipio = 1;

    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < MUNICIPIOS; j++) {
            if (populacao[i][j] > maxPopulacao) {
                maxPopulacao = populacao[i][j];
                *estado = i + 1;
                *municipio = j + 1;
            }
        }
    }
}

float calcularMediaCapitais(int populacao[][MUNICIPIOS]) {
    int somaCapitais = 0;

    for (int i = 0; i < ESTADOS; i++) {
        somaCapitais += populacao[i][0]; // Considera apenas a primeira coluna (populacao da capital)
    }

    return (float)somaCapitais / ESTADOS;
}

int main() {
    int populacao[ESTADOS][MUNICIPIOS];

    lerPopulacao(populacao);
    imprimirPopulacao(populacao);

    int estadoMaisPopuloso, municipioMaisPopuloso;
    encontrarMunicipioMaisPopuloso(populacao, &estadoMaisPopuloso, &municipioMaisPopuloso);
    printf("O municipio mais populoso e o municipio %d do estado %d.\n", municipioMaisPopuloso, estadoMaisPopuloso);

    float mediaCapitais = calcularMediaCapitais(populacao);
    printf("A media da populacao das capitais dos 26 estados e: %.2f habitantes.\n", mediaCapitais);

    return 0;
}
