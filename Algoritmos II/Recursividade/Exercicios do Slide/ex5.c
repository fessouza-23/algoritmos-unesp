#include <stdio.h>

int max(int vet[], int n) {
    int max = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > max)
            max = vet[i];
    }
    return max;
}

int main() {
    int n, vet[5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vet[i]);
    printf("%d\n", max(vet, n));
    return 0;
}