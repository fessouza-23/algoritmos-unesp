#include <stdio.h>

int inserir_final(int list[], int *n, int value) {
    if(*n == MAX)
        return 0;
    list[*n] = value;
    (*n)++;
}

int main() {
    int list = {1, 2, 3, 4, 5};
    int n = 5;

    inserir_final(list, &n, x);

    return 0;
}