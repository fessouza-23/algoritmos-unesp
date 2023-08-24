#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;

    arquivo = fopen("exemplo.dat", "wb"); // wb - escrita - cria um novo arquivos
    if (!arquivo) {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    return 0;
}