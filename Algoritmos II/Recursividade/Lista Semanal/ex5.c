#include <stdio.h>

int contarDigitos(int n, int k) {
    if (n == 0) {
        return 0;
    } else {
        int ultimoDigito = n % 10;
        if (ultimoDigito == k) {
            return 1 + contarDigitos(n / 10, k);
        } else {
            return contarDigitos(n / 10, k);
        }
    }
}

int main() {
    int n, k;
    printf("Digite um numero natural N: ");
    scanf("%d", &n);
    printf("Digite o digito K a ser contado: ");
    scanf("%d", &k);

    int ocorrencias = contarDigitos(n, k);
    printf("O digito %d ocorre %d vezes em %d.\n", k, ocorrencias, n);

    return 0;
}
