#include <stdio.h> // Biblioteca para ler valores do teclado (input) e exibir no monitor (output)
#include <stdlib.h> // Bibliteoca para alocar memória, gerar números aleatórios, converter variáveis etc.
#include <locale.h> // Biblioteca para usar acento

int main() {
    setlocale(LC_ALL, ""); // set locale language
    int a = 6, b = 3, c = -10;
    printf("Soma de %d + %d = %d\n", a, b, a + b);
    printf("Subtração de %d - %d = %d\n", a, b, a - b);
    printf("Multiplicação de %d . %d = %d\n", a, b, a * b);
    printf("Divisão de %d / %d = %d\n", a, b, a / b);
    printf("Resto da divisão de %d / %d = %d\n", a, b, a % b);
    printf("Valor absoluto de %d = %d\n", c, abs(c));
    system("pause"); // pause o programa após executar
    return 0;
}