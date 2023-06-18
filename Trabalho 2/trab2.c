#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void start() {
    while (!kbhit()) { // verifica se alguma tecla foi pressionada
        system("cls");
        printf("==============================  WELCOME  ======================================\n\n");
        Sleep(800);
        system("cls");
        printf("==============================  WELCOME  ======================================\n");
        printf("                            <press any key>                                    \n");
        Sleep(800);
    }
    getch();
}

void menu() {
    int escolha = 0;
    while (1) {
        system("cls");
        printf("================================  MENU  =======================================\n");
        printf("1. -> NEW GAME\n");
        printf("2. MOSTRAR MATRIZ\n");
        printf("3. QUIT\n");
        fflush(stdin);
        char c = getch();
        switch (c) {
            case '1':
                escolha = 1;
                system("cls");
                printf("================================  MENU  =======================================\n");
                printf("1. -> NEW GAME\n");
                printf("2. MOSTRAR MATRIZ\n");
                printf("3. QUIT\n");
                getch();
                break;
            case '2':
                escolha = 2;
                system("cls");
                printf("================================  MENU  =======================================\n");
                printf("1. NEW GAME\n");
                printf("2. -> MOSTRAR MATRIZ\n");
                printf("3. QUIT\n");
                getch();
                break;
            case '3':
                escolha = 3;
                system("cls");
                printf("================================  MENU  =======================================\n");
                printf("1. NEW GAME\n");
                printf("2. MOSTRAR MATRIZ\n");
                printf("3. -> QUIT\n");
                getch();
                break;
        }
    }
}

int main() {
    start();
    menu();
    return 0;
}
