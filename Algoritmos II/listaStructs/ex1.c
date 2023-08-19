#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 20

typedef struct {
    char nome[20];
    char estilo[20];
    int quantIntegrantes;
    int posTopFive;
} banda;

int quantBandasTotal = 0;
banda bandas[max];

void mostrarBandas() {
    // Mostra as bandas já incluídas
    for (int i = 0; i < quantBandasTotal; i++) {
        printf("Nome da banda: %s\n", bandas[i].nome);
        printf("Estilo de musica: %s\n", bandas[i].estilo);
        printf("Quantidade de integrantes: %d\n", bandas[i].quantIntegrantes);
        (bandas[i].posTopFive != 0)? printf("Posicao top five: %d\n", bandas[i].posTopFive) : printf("Nao esta no top five\n");
        printf("\n");
    }
}

void incluirBandas() {
    int quantBandasInput;

    printf("Quantidade de bandas que serao incluidas: ");
    scanf("%d", &quantBandasInput);
    getchar();

    quantBandasTotal += quantBandasInput;

    for (int i = 0; i < quantBandasInput; i++) {
        printf("--- %da banda ---\n", i + 1);

        printf("Nome da banda: ");
        fgets(bandas[i].nome, sizeof(bandas[i].nome), stdin);
        bandas[i].nome[strcspn(bandas[i].nome, "\n")] = '\0';

        printf("Estilo de musica: ");
        fgets(bandas[i].estilo, sizeof(bandas[i].estilo), stdin);
        bandas[i].estilo[strcspn(bandas[i].estilo, "\n")] = '\0';

        printf("Quantidade de integrantes: ");
        scanf("%d", &bandas[i].quantIntegrantes);
        getchar();

        printf("Ranking em seu TOP 5 (se nao estiver, coloque 0): ");
        scanf("%d", &bandas[i].posTopFive);
        getchar();
    }
}

void menu() {
    char select;
    
    do {
        system("clear");
        printf("--- MENU ---\n");
        printf("1. Incluir bandas\n");
        printf("2. Mostrar bandas\n");
        printf("3. Buscar bandas por ranking\n");
        printf("4. Buscar bandas por estilo musical\n");
        printf("5. Sair\n");
        do {
            select = getc();
            if (select < '1' || select > '5') {
                printf("Comando desconhecido!\n");
                getc();
            }
        } while (select < '1' || select > '5');

        switch (select) {
            case '1':
                incluirBandas();
                break;
            case '2':
                mostrarBandas();
                break;
            case '3':
                // Adicione lógica para buscar por ranking
                break;
            case '4':
                // Adicione lógica para buscar por estilo musical
                break;
        }
    } while (select != '5');
}

int main() {
    incluirBandas();
    menu();

    return 0;
}
