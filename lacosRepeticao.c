#include <stdio.h> // Biblioteca para ler valores do teclado (input) e exibir no monitor (output)
#include <stdlib.h> // Bibliteoca para alocar memória, gerar números aleatórios, converter variáveis etc.
#include <locale.h> // Biblioteca para usar acento
#include <time.h>

int main() {

    // reponsável por alimentar o rand (random) de forma diferente
    srand((unsigned) time(NULL));
    int aleatorio = rand();
    printf("Valor: %d\n", aleatorio);


    int i = 1;
    while (i <= 10)
    {
        printf("%d\n", i);
        i++; // equivale a: i = i + 1 | incremento |
    }
    

    system("pause") ;
    return 0; 

}