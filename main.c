#include <stdio.h> // Biblioteca para ler valores do teclado (input) e exibir no monitor (output)
#include <stdlib.h> // Bibliteoca para alocar memória, gerar números aleatórios, converter variáveis etc.
#include <locale.h> // Biblioteca para usar acento

void main() {
    setlocale(LC_ALL, ""); // set locale language
    printf("Hello, World.\n");
}