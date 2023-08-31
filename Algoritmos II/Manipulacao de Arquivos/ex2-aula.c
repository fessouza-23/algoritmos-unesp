#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quant;

    system("cls");

    printf("Digite o numero de elementos: ");
    scanf("%d", &quant);

    int numeros[quant];

    system("cls");

    int i;

    for (i = 0; i < quant; i++)
    {
        printf("\nvalor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    FILE *file;
    int quant_pares = 0;

    // Gravação dos arquivos
    file = fopen("numeros-pares.dat", "wb");
    if (!file)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    for (i = 0; i < quant; i++)
    {
        if (numeros[i] % 2 == 0)
        {
            quant_pares++;
            fwrite(&numeros[i], sizeof(int), 1, file);
        }
    }
    fclose(file);

    FILE *file2;
    int quant_impares = 0;

    file2 = fopen("numeros-impares.dat", "wb");
    if (!file2)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for (i = 0; i < quant; i++)
    {
        if (numeros[i] % 2)
        {
            quant_impares++;
            fwrite(&numeros[i], sizeof(int), 1, file2);
        }
    }
    fclose(file2);

    // Leitura do arquivo
    file = fopen("numeros-pares.dat", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    printf("\n--- Arquivo de numeros pares ---\n");
    int numeros_read_pares[quant_pares];
    fread(numeros_read_pares, sizeof(int), quant, file);

    for (i = 0; i < quant_pares; i++)
    {
        printf("%d ", numeros_read_pares[i]);
    }

    fclose(file);

    file2 = fopen("numeros-impares.dat", "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    printf("\n--- Arquivo de numeros impares ---\n");
    int numeros_read_impares[quant_impares];
    fread(numeros_read_impares, sizeof(int), quant, file2);

    for (i = 0; i < quant_impares; i++)
    {
        printf("%d ", numeros_read_impares[i]);
    }

    fclose(file2);

    return 0;
}
