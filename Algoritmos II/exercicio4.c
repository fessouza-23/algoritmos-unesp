#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} ponto;

float calcularDistancia(ponto a, ponto b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

void lerPontos(ponto *a, ponto *b) {
    printf("Valores do ponto A\n");
    printf("x: ");
    scanf("%f", &a->x);
    printf("y: ");
    scanf("%f", &a->y);

    printf("Valores do ponto B\n");
    printf("x: ");
    scanf("%f", &b->x);
    printf("y: ");
    scanf("%f", &b->y);
}

typedef struct {
    ponto a, b;
} retangulo;

void lerRetangulo(retangulo *ret) {
    lerPontos(&ret->a, &ret->b);
}

void calcularAreaRetangulo(retangulo ret) {
    float area;

    area = fabs((ret.a.x - ret.b.x) * (ret.a.y - ret.b.y));
    printf("Area do retangulo: %.2f\n", area);
}

int main() {
    ponto a, b;
    printf("--- CALCULO DA DISTANCIA ENTRE PONTOS ---\n");
    lerPontos(&a , &b);
    printf("Distancia entre os pontos: %.2f\n", calcularDistancia(a, b));

    retangulo ret;
    printf("--- CALCULO DA AREA DO RETANGULO ---\n");
    lerRetangulo(&ret);
    calcularAreaRetangulo(ret);

    return 0;
}
