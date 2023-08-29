#include <stdio.h>
#include <stdlib.h>

int main() {
    int quant;

    system("cls");

    printf("Digite o numero de elementos: ");
    scanf("%d", &quant);

    int numeros[quant];

    system("cls");

    int i;

    for (i = 0; i < quant; i++) {
        printf("\n%º valor: ", i+1);
        scanf("%d", &numeros[i]);
    }

    FILE *file;

    // Gravação do arquivo
    file = fopen("numeros-pares.dat", "wb");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita.");
        return 1;
    }
    for (i = 0; i < quant; i++) {
        if (numeros[i] % 2 == 0) {
            fwrite(numeros, sizeof(int), quant, file);
        }
    }
    fclose(file);

    FILE *file2;

    file2 = fopen("numeros-impares.dat", "wb");
    if (!file2) {
        printf("Erro ao abrir o arquivo para escrita.");
        return 1;
    }
    for (i = 0; i < quant; i++) {
        if (numeros[i] % 2) {
            fwrite(numeros, sizeof(int), quant, file2);
        }
    }
    fclose(file2);

        // Leitura do arquivo
    file = fopen("numeros-pares.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    int numeros_read[quant];
    fread(numeros_read, sizeof(int), quant, file);

    for (i = 0; i < quant; i++) {
        printf("%d ", numeros_read[i]);
    }

    fclose(file);

    return 0;
}