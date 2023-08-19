#include <stdio.h>
#include <stdlib.h>

#define max 20

int main() {
    char resp;
    int n, i, j, cont;
    float A[max], B[max];
    int contados[max] = {0};

    do {
        do {
            printf("Digite o numero de elementos (entre 1 e %d): ", max);
            scanf("%d", &n);

            if (n <= 0 || n > max) {
                printf("Valor invalido. Tente novamente.\n");
            }
        } while (n <= 0 || n > max);

        printf("Digite os elementos separados por espaco: ");
        for (i = 0; i < n; i++) {
            scanf("%f", &A[i]);
        }

        int index = 0;
        for (i = 0; i < n; i++) {
            if (!contados[i]) {
                cont = 1;
                for (j = i + 1; j < n; j++) {
                    if (A[i] == A[j]) {
                        cont++;
                        contados[j] = 1;
                    }
                }
                B[index] = A[i];
                B[index + 1] = cont;
                index += 2;
            }
        }

        for (i = 0; i < index; i += 2) {
            printf("%.2f ocorre %.0f vezes\n", B[i], B[i + 1]);
        }

        do {
            printf("\nExecutar novamente? (s/n)\n");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    } while (resp == 'S' || resp == 's');

    return 0;
}
