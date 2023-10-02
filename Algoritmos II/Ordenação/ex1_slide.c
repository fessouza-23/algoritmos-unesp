#include <stdio.h>

void selection_sort(int v[], int n){
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("\n");
    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(v, 10);
    return 0;
}