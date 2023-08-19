#include <stdio.h>
#include <string.h>
#define max 5

void decresOrder(char nomes[max][20]) {
    int i, j;
    char aux[20];

    for (i = 0; i < max; i++) {
        for (j = i + 1; j < max; j++) {
            if (stricmp(nomes[i], nomes[j]) < 0) {
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }
}

void printList(char nomes[max][20]) {
    int i;

    for (i = 0; i < max; i++) {
        puts(nomes[i]);
    }
}

int main() {
    char nomes[max][20];
    int cont;

    for (cont = 0; cont < max; cont++) {
        printf("nome 1: ", cont+1);
        gets(nomes[cont]);
    }

    decresOrder(nomes);
    printList(nomes);
    return 0;
}