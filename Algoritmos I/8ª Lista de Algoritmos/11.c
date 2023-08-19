#include <stdio.h>

#define max 50

int main() {
    int vetor[max];
    int n, chave, i, posicao = -1;
    
    printf("Digite o tamanho do vetor (maximo %d): ", max);
    scanf("%d", &n);
    
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    printf("Digite a chave a ser buscada: ");
    scanf("%d", &chave);
    
    for (i = 0; i < n; i++) {
        if (vetor[i] == chave) {
            posicao = i;
            break;
        }
    }
    
    if (posicao != -1) {
        printf("A chave %d foi encontrada na posicao %d.\n", chave, posicao);
    } else {
        printf("A chave %d nao foi encontrada no vetor.\n", chave);
    }
    
    return 0;
}
