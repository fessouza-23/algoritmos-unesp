#include <stdio.h>
#define max 10

int main() {
    int v[max], i, j, n, aux;

    do {
        printf("Qual o tamanho do vetor? obs: [max = 20]\n");
        scanf("%d", &n);
    } while (n <= 0 || n > 20);

    for (i = 0; i < n; i++) {
        printf("Valor %d.: ", i + 1);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
