#include <stdio.h>

typedef struct {
    int x;
    int y;
} ponto;

typedef struct {
    ponto a;
    ponto b;
} retangulo;

void lerPonto(ponto *point) {
    printf("x: "); scanf("%d", &point->x);
    printf("y: "); scanf("%d", &point->y);
}

void criarRetangulo(retangulo *ret) {
    printf("Digite os valores do ponto A (inf. esquerdo)\n");
    lerPonto(&ret->a);

    printf("Digite os valores do ponto B (sup.direito)\n");
    lerPonto(&ret->b);
}

int verificarPonto(ponto p, retangulo ret) {
    if (p.x > ret.b.x || p.x < ret.a.x) {
        return 0;
    } else if (p.y > ret.b.y || p.y < ret.b.y) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    retangulo ret;
    criarRetangulo(&ret);

    ponto p;
    printf("Digite os valores do Ponto P\n");
    lerPonto(&p);

    (verificarPonto(p, ret))? printf("Ponto P esta dentro do retangulo\n") : printf("Ponto P nao esta dentro do retangulo\n");

    return 0;
}