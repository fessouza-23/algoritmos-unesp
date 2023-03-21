#include <stdio.h> // Biblioteca para ler valores do teclado (input) e exibir no monitor (output)
#include <stdlib.h> // Bibliteoca para alocar memória, gerar números aleatórios, converter variáveis etc.
#include <locale.h> // Biblioteca para usar acento

int main() {
    setlocale(LC_ALL, ""); // set locale language

    // Decision marks: && (and) || (or), >=, <=, !=, ==

    int valor = 2, opcao = 1;
    printf("%d\n", valor);
    if (valor == 2){
        printf("True\n");
    }

    if (valor % 2 == 1){
        printf("Valor é ímpar\n");
    } else {
        printf("Valor é par\n");
    }
    
    if (opcao == 1){
        printf("Opcao = 1\n");
    } else if (opcao == 2){
        printf("Opcao = 2\n");
    } else{
        printf("Opcao =! de 1 != 2");
    }

    // Switch case
    int i = 1;
    switch (i)
    {
    case 1:
        printf("Opcao escohida: 1\n");
        break;
    case 2:
        printf("Opcao escolhida: 2\n");
        break;
    case 3:
        printf("Opcao escolhida: 3\n");
        break;
    default:
        printf("Opcao escolhida inválida!");
        break;
    }

    // Switch com char
    char c = 'x';
    switch (c)
    {
    case 'x':
        printf("A letra é: x\n");
        break;
    default:
        printf("Opcao inválida!");
        break;
    }
    system("pause");
    return 0;
}