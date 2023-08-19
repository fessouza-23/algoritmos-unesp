#include <stdio.h>
#define max 1000

int main() {
    int vet[max], i, num, val, soma;
    char resp;

    do {
        soma = 0;
        do {
            printf("Digite o numero de elementos para o vetor [max = 1000]: ");
            scanf("%d", &num);
        } while (num <= 0 || num > 1000);

        for (i = 0; i < num; i++) {
            printf("valor %d: ", i + 1);
            scanf("%d", &val);
            vet[i] = val;
            soma += vet[i];
        }

        for (i = 0; i < num; i++) {
            printf("%d + ", vet[i]);
        }
        printf("\b = %d\n", soma);

        do {
            printf("Executar novamente? Sim(S)/Nao(N)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
