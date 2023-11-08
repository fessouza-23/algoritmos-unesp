#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *vet, int quant) {
  int i;
  for (i = 0; i < quant; i++) {
    printf("Vetor[%d]: ", i);
    scanf("%d", &vet[i]);
  }
}

int main() {
  int quant, i;
  int *vet;

  printf("Quantos elementos: ");
  scanf("%d", &quant);

  if ((vet = (int *)malloc(quant * sizeof(int))) == NULL) {
    printf("Erro de alocacao de memoria.\n");
    return 1;
  }

  lerVetor(vet, quant);

  printf("\nImprimindo os valores do vetor:");
  for (i = 0; i < quant; i++)
    printf("\nvet[%d] = %d", i + 1, vet[i]);

  free(vet);
  getch();

  return 0;
}