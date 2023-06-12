#include <stdio.h>
#include <stdlib.h>

#define max 100

int main() {
    int n, i, j;
    float sequence[max];
    int count[max] = {0};

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    printf("Digite a sequencia de numeros:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &sequence[i]);
    }

    for (i = 0; i < n; i++) {
        if (count[i] != -1) {
            count[i] = 1;
            for (j = i + 1; j < n; j++) {
                if (sequence[i] == sequence[j]) {
                    count[i]++;
                    count[j] = -1;
                }
            }
        }
    }


    printf("Saida:\n");
    for (i = 0; i < n; i++) {
        if (count[i] != -1) {
            printf("%.1f ocorre %d vez(es)\n", sequence[i], count[i]);
        }
    }

    return 0;
}
