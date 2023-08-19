#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int reprocessamento() {
    int resp;

    do {
        printf("Executar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &resp);
    } while (resp != 1 && resp != 2);

    return resp;
}

int main() {
    char frase[101], vogais[] = "aeiou";
    int i, j, count[5] = {0};  // Array to store the counts of each vowel

    do {
        system("cls");
        printf("Digite a frase: ");
        fflush(stdin);  // Clear the input buffer
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';  // Remove trailing newline character

        for (i = 0; i < strlen(frase); i++) {
            frase[i] = tolower(frase[i]);
            for (j = 0; j < strlen(vogais); j++) {
                if (frase[i] == vogais[j]) {
                    count[j]++;  // Increment the count for the corresponding vowel
                }
            }
        }

        // Print the counts of each vowel
        for (j = 0; j < strlen(vogais); j++) {
            printf("Count of %c: %d\n", vogais[j], count[j]);
        }

    } while (reprocessamento());

    return 0;
}
