#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){ // Caso o programa retornar um número maior que 1 quer dizer que houve erro
    setlocale(LC_ALL, "");
    /*
    Código            Formato
      %c                char
      %d                int
      %e                nº em notação científica com 'e' minúsculo
      %E                nº em notação científica com 'e' maiúsculo
      %f                float, double
      %s                string
      %o                nº octal
      %u                decimal 'unsigned' (sem sinal)
      %%                imprime %

      obs: Para printf, os argumentos do tipo float são promovidos para double, 
      então tanto %f quanto %lf são usados ​​para double. Para scanf, 
      você deve usar %f para float e %lf para double.
    */
    
    int a = 5;
    printf("Int: %d\n", a);
    
    float b = 5.5;
    printf("\nValor de b: %f\n", b);
    scanf("%f", &b);
    printf("\nNovo valor de ba: %f", b);

    char c = 'c';
    printf("\nValor de c: %c\n", c);
    // Ao ler-se um valor, antes de ser passado para a variável
    // ele se aloja no Buffer (espaço de memória variável)
    fflush(stdin); // limpa o Buffer de resquícios de leitura dos valores int e float
    // stdin: standart in - entrada principal
    scanf("%c", &c);
    printf("\nNovo valor de c: %c", c);
    return 0;
}
