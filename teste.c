#include <stdio.h>
#include <string.h>
#define max 5

void ordenar(char nomes[max][20]) {
    char aux[20];
    int i, j;

    for (i = 0; i < max; i++) {
        for (j = i+1; j < max; j++) {
            if (stricmp(nomes[i], nomes[j]) > 0) {
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }
}

int main() {
    char nomes[max][20];
    int i, j;
    
    // input
    printf("Digite os nomes");
    for (i = 0; i < max; i++) {
        printf("Nome %d: ", i+1);
        gets(nomes[i]);
    }

    ordenar(nomes);
    for (i = 0; i < max; i++) {
        puts(nomes[i]);
    }
    return 0;
}