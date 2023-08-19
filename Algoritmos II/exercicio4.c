#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} ponto;

float calcularDistancia(ponto a, ponto b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void lerPonto(ponto *point) {
    printf("Valor de x: ");
    scanf("%f", &point->x);
    
    printf("Valor de y: ");
    scanf("%f", &point->y);
}

int main() {
    ponto a, b;

    printf("Ponto A:\n");
    lerPonto(&a);
    
    printf("\nPonto B:\n");
    lerPonto(&b);
    printf("Distancia entre os pontos: %.2f\n", calcularDistancia(a, b));

    return 0;
}