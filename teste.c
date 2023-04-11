#include <stdio.h>
#include <math.h>

int main() {
    float valor, parteFracao;
    scanf("%f", &valor);
    printf("Valor inteiro do número %.3f: %d", valor, (int) valor);
    printf("\nParte fracionária: %.3f", valor - (int) valor);
    printf("\nArredondamento de %.3f: %.1f", valor, round(valor));
}
