#include <stdio.h>
#define max 1000

int main() {
    int v1[max], v2[max], i, num, soma1, soma2;
    char resp;

    do {
        soma1 = soma2 = 0;
        do {
            printf("Digite o tamanho dos vetores [max = 1000]: ");
            scanf("%d", &num);
        } while (num <= 0 || num > 1000);

        int v3[num];

        for (i = 0; i < num; i++) {
            printf("vetor 1 | Valor %d: ", i + 1);
            scanf("%d", &v1[i]);
            soma1 += v1[i];
        }

        for (i = 0; i < num; i++) {
            printf("vetor 2 | Valor %d: ", i + 1);
            scanf("%d", &v2[i]);
            soma2 += v2[i];
        }

        for (i = 0; i < num; i++) {
            v3[i] = v1[i] + v2[i];
        }

        printf("Soma dos dois vetores equivale a: %d\n", soma1 + soma2);
        for (i = 0; i < num; i++)
            printf("v3[%d] = %d\n", i, v3[i]);

        do {
            printf("Executar novamente? Sim(S)/Nao(N)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
