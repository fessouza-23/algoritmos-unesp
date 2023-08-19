#include <stdio.h>

int main() {
    char resp;

    do {
        int n;
        printf("Digite o tamanho da sequencia: ");
        scanf("%d", &n);

        int num, lenAtual = 1, lenMax = 1;

        printf("Digite os numeros da sequencia:\n");
        scanf("%d", &num);

        for (int i = 1; i < n; i++) {
            int numAnt = num;
            scanf("%d", &num);

            if (num > numAnt) {
                lenAtual++;
            } else {
                if (lenAtual > lenMax) {
                    lenMax = lenAtual;
                }
                lenAtual = 1;
            }
        }

        if (lenAtual > lenMax) {
            lenMax = lenAtual;
        }

        printf("O comprimento do segmento crescente maximo eh: %d\n", lenMax);

        do {
            printf("Deseja executar novamente? (S/N): ");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');
    } while (resp == 'S' || resp == 's');

    return 0;
}
