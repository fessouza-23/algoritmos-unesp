#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void leMatriz(int *m, int *n){
    system("cls");

    do {
        printf("Digite a quantidade de linhas: ");
        scanf("%d", m);

        (*m <= 0)? printf("Valor invalido.\n") : 0;
    } while (*m <= 0);

    do {
        printf("Digite a quantidade de colunas: ");
        scanf("%d", n);

        (*n <= 0)? printf("Valor invalido.\n") : 0;
    } while (*n <= 0);
}

void menu() {
    int escolha = 0;
    while (1) {
        system("cls");
        printf("================================  MENU  =======================================\n");
        printf("1. Gerar nova matriz\n");
        printf("2. Mostrar matriz\n");
        printf("3. Trocar os elementos da linha X pela linha Y\n");
        printf("F1. Help");
        fflush(stdin);
        char c = getch();
    }
}

int main() {
    int m, n;

    leMatriz(&m, &n);
    menu();
    return 0;
}
