#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *file;
    char caractere;
    int quant_vogais = 0, quant_consoantes = 0, achou;
    char vogais[] = {"AEIOU"};
    
    if((file = fopen("arq.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n\n");
        getch();
        return;
    }

    while(!feof(file)) {
        caractere = getc(file);
        achou = 0;
        if(toupper(caractere) >= 'A' && toupper(caractere) <= 'Z'){
            for (int i = 0; i < strlen(vogais); i++) {
                if (toupper(caractere) == vogais[i]) {
                    quant_vogais++;
                    achou = 1;
                    break;
                }
            }
            if (!achou) {
                quant_consoantes++;
            }
        }
    }
    system("cls");
    printf("Vogais: %d\nConsoantes: %d\n", quant_vogais, quant_consoantes);
    getch();
    return 0;
}