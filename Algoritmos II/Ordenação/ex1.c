#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define esc 27
#define MAX_SIZE 1000

  int v[MAX_SIZE]; // vetor
  int n;           // numero de elementos

void troca(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void gerarVetorAleatorio(int v[], int n, int maxValue) {
  int i;

  for (i = 0; i < n; i++) {
    v[i] = rand() % maxValue + 1;
  }
}

void printVetor(int v[], int n) {
  int i;

  printf("Vetor: ");

  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
    if ((i + 1) % 25 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

void vetorOndemAleatoria(int v[]) {
  int i, maxElementVet;

  system("cls");

  printf("Quantidade de elementos: ");
  scanf("%d", &n);

  printf("Valor maximo que sera gerado: ");
  scanf("%d", &maxElementVet);

  gerarVetorAleatorio(v, n, maxElementVet);

  printVetor(v, n);

  getch();
}

void vetorOrdemCrescente(int v[]) {
  int i, j, min_ind, maxElementVet;

  system("cls");

  printf("Quantidade de elementos: ");
  scanf("%d", &n);

  printf("Valor maximo que sera gerado: ");
  scanf("%d", &maxElementVet);

  gerarVetorAleatorio(v, n, maxElementVet);

  // selection sort
  for (i = 0; i < n - 1; i++) {
    min_ind = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[min_ind])
        min_ind = j;
    }
    if (min_ind != i)
      troca(&v[min_ind], &v[i]);
  }

  printVetor(v, n);

  getch();
}

void vetorOrdemDecrescente(int v[]) {
  int i, j, maxElementVet, max_ind;

  system("cls");

  printf("Quantidade de elementos: ");
  scanf("%d", &n);

  printf("Valor maximo que sera gerado: ");
  scanf("%d", &maxElementVet);

  gerarVetorAleatorio(v, n, maxElementVet);

  // selection sort
  for (i = 0; i < n; i++) {
    max_ind = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] > v[max_ind])
        max_ind = j;
    }
    if (max_ind != i)
      troca(&v[max_ind], &v[i]);
  }

  printVetor(v, n);

  getch();
}

void vetOrdemParcialCrescente(int v[]) {
  int i, j, maxElementVet, min_ind, aleatorio;

  system("cls");

  printf("Quantidade de elementos: ");
  scanf("%d", &n);

  printf("Valor maximo que sera gerado: ");
  scanf("%d", &maxElementVet);

  gerarVetorAleatorio(v, n, maxElementVet);

  // selection sort
  for (i = 0; i < n; i++) {
    min_ind = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[min_ind])
        min_ind = j;
    }
    aleatorio = rand() % 2;
    if (min_ind != i && aleatorio)
      troca(&v[min_ind], &v[i]);
  }

  printVetor(v, n);

  getch();
}

int main() {
  
  srand(time(NULL));

  char op;
  do {
    system("cls");
    printf("================================  MENU  "
           "=======================================\n");
    printf("1. Gerar vetor em ordem completamente aleatoria\n");
    printf("2. Gerar vetor ordenado em ordem crescente\n");
    printf("3. Gerar vetor ordenado em ordem decrescente\n");
    printf("4. Gerar vetor quase ordenado\n");
    printf("Esc - Sair\n");
    op = getch();

    switch (op) {
    case '1':
      vetorOndemAleatoria(v);
      break;

    case '2':
      vetorOrdemCrescente(v);
      break;

    case '3':
      vetorOrdemDecrescente(v);
      break;

    case '4':
      vetOrdemParcialCrescente(v);
      break;
    }
  } while (op != esc);

  return 0;
}
