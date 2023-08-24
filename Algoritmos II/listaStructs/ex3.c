#include <stdio.h>

typedef struct {
    double real;
    double imag;
} complexo;

void lerComplexo(complexo *c) {
    printf("Parte real: ");
    scanf("%lf", &c->real);

    printf("Parte imaginaria: ");
    scanf("%lf", &c->imag);
}

complexo somarComplexos(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

complexo subtrairComplexos(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}

complexo multiplicarComplexos(complexo c1, complexo c2) {
    complexo resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

int main() {
    complexo c1, c2, resultado;

    printf("Digite o primeiro numero complexo:\n");
    lerComplexo(&c1);

    printf("Digite o segundo numero complexo:\n");
    lerComplexo(&c2);

    resultado = somarComplexos(c1, c2);
    printf("Soma: %.2lf + %.2lfi\n", resultado.real, resultado.imag);

    resultado = subtrairComplexos(c1, c2);
    printf("Subtracao: %.2lf + %.2lfi\n", resultado.real, resultado.imag);

    resultado = multiplicarComplexos(c1, c2);
    printf("Multiplicacao: %.2lf + %.2lfi\n", resultado.real, resultado.imag);

    return 0;
}
