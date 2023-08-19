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
int contador = 0;
i = 0;
banda bandas[max];


void mostrarBandas() {
    system("cls");

    for (i = 0; i < quantBandasTotal; i++) {
        printf("Nome da banda: %s\n", bandas[i].nome);
        printf("Estilo de musica: %s\n", bandas[i].estilo);
        printf("Quantidade de integrantes: %d\n", bandas[i].quantIntegrantes);
        (bandas[i].posTopFive != 0)? printf("Posicao top five: %d\n", bandas[i].posTopFive) : printf("Nao esta no top five\n");
        printf("\n");
    }

    system("pause");
}

void incluirBandas() {
    int quantBandasInput;

    system("cls");

    printf("Quantidade de bandas que serao incluidas: ");
    scanf("%d", &quantBandasInput);
    getchar();

    quantBandasTotal += quantBandasInput;

    for (i = 0; i < quantBandasInput; i++, contador++) {
        printf("--- %da banda ---\n", i + 1);

        printf("Nome da banda: ");
        fgets(bandas[contador].nome, sizeof(bandas[contador].nome), stdin);
        bandas[contador].nome[strcspn(bandas[contador].nome, "\n")] = '\0';

        printf("Estilo de musica: ");
        fgets(bandas[contador].estilo, sizeof(bandas[contador].estilo), stdin);
        bandas[contador].estilo[strcspn(bandas[contador].estilo, "\n")] = '\0';

        printf("Quantidade de integrantes: ");
        scanf("%d", &bandas[contador].quantIntegrantes);
        getchar();

        printf("Ranking em seu TOP 5 (se nao estiver, coloque 0): ");
        scanf("%d", &bandas[contador].posTopFive);
        getchar();
    }
}

void buscarPorRanking() {
    int ranking;

    system("cls");

    printf("Qual ranking? ");
    scanf("%d", &ranking);

    for(i = 0; i < quantBandasTotal; i++) {
        if (bandas[i].posTopFive == ranking) {  // Use '==' for comparison
            printf("Nome da banda: %s\n", bandas[i].nome);
            printf("Estilo de musica: %s\n", bandas[i].estilo);
            printf("Quantidade de integrantes: %d\n", bandas[i].quantIntegrantes);
            printf("Posicao top five: %d\n", bandas[i].posTopFive);
            break;
        }
    }
    
    if (i == quantBandasTotal) {
        printf("Nao possui banda neste ranking\n");
    }

    system("pause");
}

void buscarPorEstilo() {
    char estilo[20];

    system("cls");

    printf("Qual estilo de musica? ");
    fgets(estilo, sizeof(estilo), stdin);
    estilo[strcspn(estilo, "\n")] = '\0';

    for(i = 0; i < quantBandasTotal; i++) {
        if (strcmp(bandas[i].estilo, estilo) == 0) {
            printf("Nome da banda: %s\n", bandas[i].nome);
            printf("Estilo de musica: %s\n", bandas[i].estilo);
            printf("Quantidade de integrantes: %d\n", bandas[i].quantIntegrantes);
            printf("Posicao top five: %d\n", bandas[i].posTopFive);
        }
    }
    
    if (i == quantBandasTotal) {
        printf("Nao possui banda deste estilo\n");
    }

    system("pause");
}



void menu() {
    char select;
    
    do {
        system("cls");
        printf("--- MENU ---\n");
        printf("1. Incluir bandas\n");
        printf("2. Mostrar bandas\n");
        printf("3. Buscar bandas por ranking\n");
        printf("4. Buscar bandas por estilo musical\n");
        printf("5. Sair\n");
        do {
            select = getch();
            if (select < '1' || select > '5') {
                printf("Comando desconhecido!\n");
                getch();
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
                buscarPorRanking();
                break;
            case '4':
                buscarPorEstilo();
                break;
            case '5':
                exit(0);
                break;
        }
    } while (select != '5');
}

int main() {
    incluirBandas();
    menu();
    return 0;
}

