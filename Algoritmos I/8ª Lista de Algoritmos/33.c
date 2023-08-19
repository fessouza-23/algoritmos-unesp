#include <stdio.h>
#include <string.h>
#define max 30

int main() {
    char str1[max], str2[max], U[max], I[max], resp;
    int i, j, count;

    do {
        do {
            printf("Digite uma sequencia string: obs[max=30 caracteres]\n");
            scanf("%s", str1);
        } while (strlen(str1) > max);

        do {
            printf("Digite uma sequencia string: obs[max=30 caracteres]\n");
            scanf("%s", str2);
        } while (strlen(str2) > max);

        count = 0;

        for (i = 0; i < strlen(str1); i++) {
            for (j = 0; j < strlen(str2); j++) {
                if (str1[i] == str2[j]) {
                    I[count] = str1[i];
                    count++;
                    break;
                }
            }
        }

        I[count] = '\0'; // Caractere de terminação de string

        for (i = 0; i < strlen(str1); i++) {
            U[i] = str1[i];
        }

        i = strlen(str1);

        for (j = 0; j < strlen(str2); j++) {
            U[i + j] = str2[j];
        }

        U[i + strlen(str2)] = '\0';

        printf("U = '%s'\n", U);
        printf("I = '%s'\n", I);

        do {
            printf("Deseja executar novamente? (S/N): ");
            scanf(" %c", &resp);
        } while (resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');
    } while (resp == 'S' || resp == 's');

    return 0;
}
