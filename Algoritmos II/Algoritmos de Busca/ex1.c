#include <stdio.h>

int buscaLinear(int vet[], int n, int x) {
  int i, cont = 0;
  for (i = 0; i < n; i++, cont++) {
    if (vet[i] == x) {
      printf("Quantidade de operacoes: %d\n", cont);
      return i;
    }
  }
  printf("Quantidade de operacoes: %d\n", cont);
  return -1;
}

int buscaLinearOrd(int vet[], int n, int x) {
  int i, cont = 0;
  for (i = 0; i < n; i++, cont++) {
    if (vet[i] == x) {
      printf("Quantidade de operacoes: %d\n", cont);
      return i;
    } else if (vet[i] > x) {
      printf("Quantidade de operacoes: %d\n", cont);
      return -1;
    }
  }
  printf("Quantidade de operacoes: %d\n", cont);
  return -1;
}

int buscaBinaria(int vet[], int n, int x) {
  int i, cont = 0;
  int meio;
  int esquerda = 0;
  int direita = n - 1;
  while (esquerda <= direita) {
    meio = (esquerda + direita) / 2;
    cont++;
    if (vet[meio] == x) {
      printf("Quantidade de operacoes: %d\n", cont);
      return meio;
    } else if (vet[meio] > x) {
      direita = meio - 1;
      cont++;
    } else if (vet[meio] < x) {
      esquerda = meio + 1;
      cont++;
    }
  }
  printf("Quantidade de operacoes: %d\n", cont);
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 12;

  buscaLinear(arr, n, x);
  buscaLinearOrd(arr, n, x);
  buscaBinaria(arr, n, x);

  return 0;
}
