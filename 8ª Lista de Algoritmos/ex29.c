#include <stdio.h>

#define MAX_GRAU 50

int main() {
    double coeficientes[MAX_GRAU];
    int grau;
    int M;

    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    if (grau < 1 || grau > MAX_GRAU) {
        printf("Grau invalido.\n");
        return 0;
    }

    for (int i = 0; i <= grau; i++) {
        printf("Digite o coeficiente a%d: ", i);
        scanf("%lf", &coeficientes[i]);
    }

    printf("Digite o valor de M: ");
    scanf("%d", &M);

    for (int k = 1; k <= M; k++) {
        double alfa;
        double resultado[MAX_GRAU];

        printf("\nDigite o valor de alfa: ");
        scanf("%lf", &alfa);

        for (int i = 0; i < grau; i++) {
            resultado[i] = coeficientes[i];
        }

        for (int i = grau - 1; i >= 1; i--) {
            resultado[i - 1] = resultado[i - 1] * alfa + resultado[i];
        }

        printf("Polinomio q(x) para alfa = %.2lf:\n", alfa);
        for (int i = 0; i < grau - 1; i++) {
            printf("%.2lfx^%d + ", resultado[i], grau - i - 1);
        }
        printf("%.2lf\n", resultado[grau - 1]);
    }

    return 0;
}
