#include <stdio.h>
#define max 100

int main() {
    int v[max], i, n, j, k;

    do {
        printf("Qual o tamanho do vetor? obs: [max = 100]\n");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                for (k = j; k < n - 1; k++) {
                    v[k] = v[k + 1];
                }
                n--;
                j--; // Para reavaliar o próximo elemento na posição j
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
