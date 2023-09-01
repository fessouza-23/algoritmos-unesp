#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file, *file2, *file3;
    char texto[100];

    if((file = fopen("arq.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n\n");
        getch();
        return;
    }

    if((file2 = fopen("arq2.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n\n");
        getch();
        return;
    }

    if((file3 = fopen("arq3.txt", "a+")) == NULL) {
        printf("Erro ao abrir o arquivo.\n\n");
        getch();
        return;
    }
    
    while(fgets(texto, 100, file) != NULL){
        fprintf(file3, "%s", texto);
        putc('\n', file3);
    }

    while(fgets(texto, 100, file2) != NULL){
        fprintf(file3, "%s", texto);
        putc('\n', file3);
    }

    fclose(file);
    fclose(file2);
    fclose(file3);
    return 0;
}