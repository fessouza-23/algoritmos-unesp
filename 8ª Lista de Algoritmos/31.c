#include <stdio.h>
#define max 20

int main() {
    int N, v1[max], v2[max], v3[max], v4[max], j, i, cont;

    do {
        printf("Digite o tamanho do vetor: obs[max=20]\n");
        scanf("%d", &N);
    } while (N <= 0);

    printf("1a sequencia: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &v1[i]);
    }

    printf("2a sequencia: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &v2[i]);
    }

    cont = 0;
    for (i = N - 1; i >= 0; i--) {
        if (v1[i] + v2[i] >= 10) {
            v3[i] = (v1[i] + v2[i]) - 10;
            cont++;
        } else {
            v3[i] = (v1[i] + v2[i]) + cont;
            cont = 0;
        }
    }

    if (cont != 0) {
        v4[0] = cont;
        for (i = 1, j = 0; i < N + 1; i++, j++) {
            v4[i] = v3[j];
        }

        printf("Resultado sq: ");
        for (i = 0; i < N + 1; i++) {
            printf("%d ", v4[i]);
        }
    } else {
        printf("Resultado sq: ");
        for (i = 0; i < N; i++) {
            printf("%d ", v3[i]);
        }
    }

    return 0;
}
