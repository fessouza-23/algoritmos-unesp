#include <stdio.h>

int main() {
    int sequence[100], n, i, m, found = 0;

    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &n);

    printf("Digite os numeros da sequencia: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    for (i = 0; i < n - 2; i++) {
        for (m = 1; i + 2 * m <= n; m++) {
            int equal = 1;
            for (int j = 0; j < m; j++) {
                if (sequence[i + j] != sequence[i + m + j]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        printf("Existem dois segmentos consecutivos iguais:\n");
        printf("i = %d e m = %d\n", i, m);
    } else {
        printf("Nao existem dois segmentos consecutivos iguais.\n");
    }

    return 0;
}
