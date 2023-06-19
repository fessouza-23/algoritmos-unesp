#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int contavogal(char texto[]) {
    char vogais[] = "aeiouAEIOU";
    int i, j, numVogais = 0;
    for (i = 0; texto[i] != '\0'; ++i) {                                       // for (i=0; i<strlen(texto); i++)
        for (j = 0; vogais[j] != '\0'; ++j) // for (j=0; j<strlen(vogais); j++)
            if (vogais[j] == texto[i]) {
                numVogais++;
                break;
            }
    }
    return numVogais;
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
    char frase[40];
    do {
        printf("Digite uma frase: ");
        scanf("%s", frase);
        printf("\n\nFrase: %s", frase);
        printf("\nNumero de vogais: %d", contavogal(frase));
    } while (reprocessamento());
}
