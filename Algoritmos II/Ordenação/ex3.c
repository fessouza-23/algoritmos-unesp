#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxCols 1000
#define numRows 4
#define maxValue 1000

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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

void gerarVetorAleatorio(int v[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    v[i] = rand() % maxValue + 1;
  }
}

void vetorOrdemCrescente(int v[], int n) {
  int i, j, min_ind, maxElementVet;

  system("cls");

  gerarVetorAleatorio(v, n);

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

void vetorOrdemDecrescente(int v[], int n) {
  int i, j, maxElementVet, max_ind;

  system("cls");

  gerarVetorAleatorio(v, n);

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

void vetOrdemParcialCrescente(int v[], int n) {
  int i, j, maxElementVet, min_ind, aleatorio;

  system("cls");

  gerarVetorAleatorio(v, n);

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

void printMatriz(int matriz[numRows][maxCols], int numCols, int posLinha) {
    for (int j = 0; j < numCols; j++) {
        printf("%d ", matriz[posLinha][j]);
        if (((j + 1) % 25) == 0) {
            printf("\n");
        }
    }
}

void gerarMatrizAleatoria(int matrizAleatoria[numRows][maxCols], int numCols,
                          int maxElement) {
  int i, j;

  printf(
      "A matriz aleatoria armazena em cada linha um 'vetor' aleatorio gerado. "
      "\nTodas as linhas possui o mesmo vetor(coluna da matriz) aleatorio e "
      "\nsao tratados por sorts diferentes.\n");

  for (j = 0; j < numCols; j++) {
    matrizAleatoria[0][j] = rand() % maxElement + 1;
  }

  for (i = 1; i < numRows; i++) {
    for (j = 0; j < numCols; j++) {
      matrizAleatoria[i][j] = matrizAleatoria[0][j];
    }
  }


    for (j = 0; j < numCols; j++) {
      printf("%d ", matrizAleatoria[0][j]);
  }

  getch();
}

void selectionSort(int matrizAleatoria[numRows][maxCols], int numCols) {
    int i, j, min_ind, comparacoes = 0, trocas = 0;

    for (i = 0; i < numCols - 1; i++) {
        min_ind = i;
        for (j = i + 1; j < numCols; j++) {
            comparacoes++;
            if (matrizAleatoria[0][j] < matrizAleatoria[0][min_ind]) {
                min_ind = j;
            }
        }
        if (min_ind != i) {
            troca(&matrizAleatoria[0][min_ind], &matrizAleatoria[0][i]);
            trocas++;
        }
    }

    printf("\n=============================  SELECTION SORT  "
           "====================================\n");

    printf("\ncomparacoes: %d\ntrocas: %d\n", comparacoes, trocas);
}

void bubbleSort(int matrizAleatoria[numRows][maxCols], int numCols) {
    int i, j, houve_troca = 1, comparacoes = 0, trocas = 0;

    for (i = 0; i < numCols - 1 && houve_troca; i++) {
        houve_troca = 0;
        for (j = 0; j < numCols - i - 1; j++) {
            comparacoes++;
            if (matrizAleatoria[1][j] > matrizAleatoria[1][j + 1]) {
                troca(&matrizAleatoria[1][j], &matrizAleatoria[1][j + 1]);
                houve_troca = 1;
                trocas++;
            }
        }
    }

    printf("\n=============================  BUBBLE SORT  "
           "====================================\n");

    printf("\ncomparacoes: %d\ntrocas: %d\n", comparacoes, trocas);
}

void insertionSort(int matrizAleatoria[numRows][maxCols], int numCols) {
    int i, j, aux, comparacoes = 0, trocas = 0;

    for (i = 1; i < numCols; i++) {
        aux = matrizAleatoria[2][i];
        j = i - 1;

        comparacoes++;

        while (j >= 0 && aux < matrizAleatoria[2][j]) {
            matrizAleatoria[2][j + 1] = matrizAleatoria[2][j];
            trocas++;
            j--;
        }

        matrizAleatoria[2][j + 1] = aux;
        trocas++;
    }

    printf("\n=============================  INSERTION SORT  "
           "====================================\n");

    printf("\ncomparacoes: %d\ntrocas: %d\n", comparacoes, trocas);
}

void shellSort(int matrizAleatoria[numRows][maxCols], int numCols) {
    int i, j, k, aux, trocas = 0, comparacoes = 0;

    for (k = numCols / 2; k > 0; k /= 2) {
        for (i = k; i < numCols; i++) {
            aux = matrizAleatoria[3][i];
            comparacoes++;

            for (j = i - k; j >= 0 && aux < matrizAleatoria[3][j]; j -= k) {
                matrizAleatoria[3][j + k] = matrizAleatoria[3][j];
                trocas++;
            }

            matrizAleatoria[3][j + k] = aux;
            trocas++;
        }
    }

    printf("\n=============================  SHELL SORT  "
           "====================================\n");

    printf("\ncomparacoes: %d\ntrocas: %d\n", comparacoes, trocas);
}

int main() {
    int matrizAleatoria[numRows][maxCols];
    int v[maxCols], n;
    int numCols, maxElement;

    srand(time(NULL));

    

    system("cls");

    printf("Quantidade de elementos: ");
    scanf("%d", &numCols);

    system("cls");

    // gerarMatrizAleatoria(matrizAleatoria, numCols, maxElement);

    system("cls");

    vetOrdemParcialCrescente(v, numCols);

    int i, j;

    for (i = 0; i < numRows; i++) {
      for (j = 0; j < numCols; j++) {
        matrizAleatoria[i][j] = v[j];
      }
    }

  for (i = 0; i < numRows; i++) {
    printf("linha %d ", i+1);
      for (j = 0; j < numCols; j++) {
        printf("%d ", matrizAleatoria[i][j]);
      }
    }

    selectionSort(matrizAleatoria, numCols);
    bubbleSort(matrizAleatoria, numCols);
    insertionSort(matrizAleatoria, numCols);
    shellSort(matrizAleatoria, numCols);

    return 0;
}