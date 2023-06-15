#include <stdio.h>

#define MAX_MOCCAS 20
#define MAX_RAPAIZES 30
#define MAX_PERGUNTAS 20

#define SIM 1
#define NAO 2
#define INDIFERENTE 3

void preencherQuestionario(int questionario[][MAX_RAPAIZES][MAX_PERGUNTAS], int numMoccas, int numRapaizes) {
    printf("Responda as perguntas com '1' para SIM, '2' para NAO e '3' para INDIFERENTE.\n");

    for (int i = 0; i < numMoccas; i++) {
        for (int j = 0; j < numRapaizes; j++) {
            printf("Perguntas para Moca %d e Rapaz %d:\n", i+1, j+1);
            for (int k = 0; k < MAX_PERGUNTAS; k++) {
                printf("Pergunta %02d: ", k+1);
                int resposta;
                scanf("%d", &resposta);
                questionario[i][j][k] = resposta;
            }
            printf("\n");
        }
    }
}

void imprimirTabelaAfinidade(int questionario[][MAX_RAPAIZES][MAX_PERGUNTAS], int numMoccas, int numRapaizes) {
    printf("=== Tabela de Afinidade ===\n\n");
    printf("       ");
    for (int j = 0; j < numRapaizes; j++) {
        printf("Rapaz %02d ", j+1);
    }
    printf("\n");

    for (int i = 0; i < numMoccas; i++) {
        printf("Moca %02d ", i+1);
        for (int j = 0; j < numRapaizes; j++) {
            int afinidade = 0;
            for (int k = 0; k < MAX_PERGUNTAS; k++) {
                if (questionario[i][j][k] == SIM) {
                    afinidade++;
                } else if (questionario[i][j][k] == INDIFERENTE) {
                    afinidade += 0.5;
                }
            }
            printf("    %02d     ", afinidade);
        }
        printf("\n");
    }
}

int main() {
    int numMoccas, numRapaizes;
    int questionario[MAX_MOCCAS][MAX_RAPAIZES][MAX_PERGUNTAS];

    printf("Digite o numero de mocas (M <= 20): ");
    scanf("%d", &numMoccas);
    printf("Digite o número de rapazes (R <= 30): ");
    scanf("%d", &numRapaizes);

    if (numMoccas <= 0 || numMoccas > MAX_MOCCAS || numRapaizes <= 0 || numRapaizes > MAX_RAPAIZES) {
        printf("Numero de mocas ou rapazes inválido.\n");
        return 0;
    }

    preencherQuestionario(questionario, numMoccas, numRapaizes);
    imprimirTabelaAfinidade(questionario, numMoccas, numRapaizes);

    return 0;
}
