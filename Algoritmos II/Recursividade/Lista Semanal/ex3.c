#include <stdio.h>

int menor(int vet[], int n) {
  if (n == 1) {
    return vet[0];
  }
  int aux = menor(vet, n - 1);
  if (vet[n - 1] < aux)
    return vet[n - 1];
  else
    return aux;
}

int main() {
  int vet[50], i, n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("vet[%d] = ", i);
    scanf("%d", &vet[i]);
  }
  printf("\nMenor elemento do vetor = %d", menor(vet, n));
}
