#include <stdio.h>
#define max 25
#define values 10

int main() {
    int n, i, j;
    int coeficientes[max];
    int valores_x[values];
    
    printf("Digite o valor de n (n <= 25): ");
    scanf("%d", &n);
    
    printf("Digite os coeficientes do polinomio p(x):\n");
    for (i = 0; i <= n; i++) {
        printf("Coeficiente a%d: ", i);
        scanf("%d", &coeficientes[i]);
    }
    
    printf("\nCalculando o valor de p(x) para 10 valores de x:\n");
    printf("----------------------------------\n");
    
    for (j = 0; j < values; j++) {
        printf("Digite o valor de x: ");
        scanf("%d", &valores_x[j]);
    }
    
    printf("----------------------------------\n");
    
    printf("Valores calculados:\n");
    for (j = 0; j < values; j++) {
        int x = valores_x[j];
        int resultado = 0;
        
        for (i = n; i >= 0; i--) {
            resultado += coeficientes[i] * pow(x, i);
        }
        
        printf("p(%d) = %d\n", x, resultado);
    }
    
    return 0;
}
