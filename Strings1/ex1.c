#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void quantConsVogs(char str[], int *cons, int *vogs) {
    int i;
    char vogais[] = "AEIOUaeiou";

    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) { // Verifica se o caractere é uma letra
            if (strchr(vogais, str[i]) != NULL) {
                (*vogs)++;
            } else {
                (*cons)++;
            }
        }
    }
}

int reprocessamento() {
    int i;
    do {
        printf("\nDeseja utilizar o programa novamente?\n\t1 - Sim\n\t0 - Nao\n");
        scanf("%d", &i);
        if (i != 1 && i != 0)
            printf("Valor invalido! Por favor, digite novamente!\n");
    } while (i != 1 && i != 0);
    return i;
}

int main() {
    char str[21];
    int vogs, cons;

    do {
        vogs = cons = 0;

        printf("Digite uma frase: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // Removendo a quebra de linha

        quantConsVogs(str, &cons, &vogs);

        printf("Frase: %s\n", str);
        printf("Quantidade de vogais: %d\n", vogs);
        printf("Quantidade de consoantes: %d\n", cons);
    } while (reprocessamento());

    return 0;
}
