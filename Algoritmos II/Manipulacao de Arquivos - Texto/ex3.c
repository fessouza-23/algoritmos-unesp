#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file;
    char arquivo[20];
    char caracter;
    int quant_digitos = 0, quant_letras = 0, quant_linhas = 1;
    int frequencia[256] = {0};

    system("cls");
    printf("Nome do arquivo de texto .txt: ");
    scanf("%s", arquivo);

    if ((file = fopen(arquivo, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n\n");
        return 1;
    }

    while ((caracter = fgetc(file)) != EOF)
    {
        if (isalpha(caracter))
        {
            quant_letras++;
        }
        else if (isdigit(caracter))
        {
            quant_digitos++;
        }
        else if (caracter == '\n')
        {
            quant_linhas++;
        }
        frequencia[(int)caracter]++;
    }

    printf("Quantidade de letras: %d\n", quant_letras);
    printf("Quantidade de digitos: %d\n", quant_digitos);
    printf("Quantidade de linhas: %d\n", quant_linhas);

    char caractere_mais_frequente = 0;
    int max_frequencia = 0;

    for (int i = 0; i < 256; i++)
    {
        if (frequencia[i] > max_frequencia)
        {
            max_frequencia = frequencia[i];
            caractere_mais_frequente = (char)i;
        }
    }

    printf("Caractere mais frequente: %c (aparece %d vezes)\n", caractere_mais_frequente, max_frequencia);

    fclose(file);
    return 0;
}
