#include <stdio.h>

FILE *abrirArquivo(const char nome_arquivo[20], const char op[5]) {
  FILE *file;
  if ((file = fopen(nome_arquivo, op)) == NULL) {
    printf("Erro ao abrir o arquivo.\n\n");
    getch();
  }
  return file;
}

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
  FILE *file;
  int n, m, i;

  file = abrirArquivo("dados.txt", "r");

  fscanf(file, "%d %d", &n, &m);

  int arr[n];

  for (i = 0; i < n; i++) {
    fscanf(file, "%d", &arr[i]);
  }

  printf("Array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int x;
  while (fscanf(file, "%d", &x) != EOF) {
    printf("\nx = %d\n", x);
    buscaLinear(arr, n, x);
    buscaLinearOrd(arr, n, x);
    buscaBinaria(arr, n, x);
  }

  fclose(file);

  return 0;
}
