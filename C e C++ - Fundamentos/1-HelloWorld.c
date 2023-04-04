#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Fun��o principal do programa
int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    //Imprime na tela
    printf("Olá mundo!");

    //Pausa o programa ap�s executar
    system("pause");
    return 0;
}

