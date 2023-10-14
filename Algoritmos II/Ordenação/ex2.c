#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxCols 1000
#define numRows 6

void troca(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
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

  for (i = 0; i < numRows; i++) {
    printf("\nlinha %d: ", i + 1);
    for (j = 0; j < numCols; j++) {
      printf("%d ", matrizAleatoria[i][j]);
      if ((j + 1) % 25 == 0) {
        printf("\n");
      }
    }
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

void merge(int arr[], int left, int mid, int right, int *comparacoes,
           int *trocas) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    (*comparacoes)++;
    if (L[i] <= R[j]) {
      (*trocas)++;
      arr[k] = L[i];
      i++;
    } else {
      (*trocas)++;
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    (*trocas)++;
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    (*trocas)++;
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right, int *comparacoes, int *trocas) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, comparacoes, trocas);
    mergeSort(arr, mid + 1, right, comparacoes, trocas);

    merge(arr, left, mid, right, comparacoes, trocas);
  }
}

void callMergeSort(int matrizAleatoria[numRows][maxCols], int numCols) {
  int i, comparacoes = 0, trocas = 0;
  for (i = 0; i < numCols; i++) {
    mergeSort(matrizAleatoria[4], 0, numCols - 1, &comparacoes, &trocas);
  }

  printf("\n=============================  MERGE SORT  "
         "====================================\n");

  printf("\ncomparacoes: %d\ntrocas: %d\n", comparacoes, trocas);
}

int getRandomPivot(int low, int high) {
  srand(time(NULL));
  return low + rand() % (high - low + 1);
}

int partitionFirst(int matrizAleatoria[numRows][maxCols], int left, int right,
                   int *comparacoes, int *trocas) {
  int pivot = matrizAleatoria[5][left];
  int i = left + 1;
  int j = right;

  while (1) {
    while (i <= j && matrizAleatoria[5][i] <= pivot) {
      i++;
      (*comparacoes)++;
    }
    while (matrizAleatoria[5][j] > pivot) {
      j--;
      (*comparacoes)++;
    }
    if (i <= j) {
      troca(&matrizAleatoria[5][i], &matrizAleatoria[5][j]);
      (*trocas)++;
    } else {
      break;
    }
  }
  troca(&matrizAleatoria[5][left], &matrizAleatoria[5][j]);
  (*trocas)++;
  return j;
}

void quickSortFirst(int matrizAleatoria[numRows][maxCols], int left, int right,
                    int *comparacoes, int *trocas) {
  if (left < right) {
    int pivotIndex =
        partitionFirst(matrizAleatoria, left, right, comparacoes, trocas);
    quickSortFirst(matrizAleatoria, left, pivotIndex - 1, comparacoes, trocas);
    quickSortFirst(matrizAleatoria, pivotIndex + 1, right, comparacoes, trocas);
  }
}

int partitionRandom(int matrizAleatoria[numRows][maxCols], int left, int right,
                    int *comparacoes, int *trocas) {
  int pivotIndex = getRandomPivot(left, right);
  troca(&matrizAleatoria[5][pivotIndex], &matrizAleatoria[5][left]);
  return partitionFirst(matrizAleatoria, left, right, comparacoes, trocas);
}

void quickSortRandom(int matrizAleatoria[numRows][maxCols], int left, int right,
                     int *comparacoes, int *trocas) {
  if (left < right) {
    int pivotIndex =
        partitionRandom(matrizAleatoria, left, right, comparacoes, trocas);
    quickSortRandom(matrizAleatoria, left, pivotIndex - 1, comparacoes, trocas);
    quickSortRandom(matrizAleatoria, pivotIndex + 1, right, comparacoes,
                    trocas);
  }
}

int getMedianPivotIndex(int matrizAleatoria[numRows][maxCols], int left,
                        int right) {
  int middle = left + (right - left) / 2;

  if (matrizAleatoria[5][left] > matrizAleatoria[5][middle]) {
    troca(&matrizAleatoria[5][left], &matrizAleatoria[5][middle]);
  }
  if (matrizAleatoria[5][left] > matrizAleatoria[5][right]) {
    troca(&matrizAleatoria[5][left], &matrizAleatoria[5][right]);
  }
  if (matrizAleatoria[5][middle] > matrizAleatoria[5][right]) {
    troca(&matrizAleatoria[5][middle], &matrizAleatoria[5][right]);
  }

  return middle;
}

int partitionMedian(int matrizAleatoria[numRows][maxCols], int left, int right,
                    int *comparacoes, int *trocas) {
  int pivotIndex = getMedianPivotIndex(matrizAleatoria, left, right);
  troca(&matrizAleatoria[5][pivotIndex], &matrizAleatoria[5][left]);
  return partitionFirst(matrizAleatoria, left, right, comparacoes, trocas);
}

void quickSortMedian(int matrizAleatoria[numRows][maxCols], int left, int right,
                     int *comparacoes, int *trocas) {
  if (left < right) {
    int pivotIndex =
        partitionMedian(matrizAleatoria, left, right, comparacoes, trocas);
    quickSortMedian(matrizAleatoria, left, pivotIndex - 1, comparacoes, trocas);
    quickSortMedian(matrizAleatoria, pivotIndex + 1, right, comparacoes,
                    trocas);
  }
}

void callQuickSort(int matrizAleatoria[numRows][maxCols], int numCols) {
  int comparacoesInicio = 0, trocasInicio = 0;
  int comparacoesAleatorio = 0, trocasAleatorio = 0;
  int comparacoesMediana = 0, trocasMediana = 0;

  int matrizInicio[numRows][maxCols];
  int matrizAleatorio[numRows][maxCols];
  int matrizMediana[numRows][maxCols];

  // Copia a matriz original para as três versões do Quicksort
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      matrizInicio[i][j] = matrizAleatoria[i][j];
      matrizAleatorio[i][j] = matrizAleatoria[i][j];
      matrizMediana[i][j] = matrizAleatoria[i][j];
    }
  }

  printf("\n=============================  QUICKSORT COM PIVO NO INICIO  "
         "====================================\n");
  quickSortFirst(matrizInicio, 0, numCols - 1, &comparacoesInicio,
                 &trocasInicio);
  printf("Comparacoes: %d\nTrocas: %d\n", comparacoesInicio, trocasInicio);

  printf("\n=============================  QUICKSORT COM PIVO ALEATORIO  "
         "====================================\n");
  quickSortRandom(matrizAleatorio, 0, numCols - 1, &comparacoesAleatorio,
                  &trocasAleatorio);
  printf("Comparacoes: %d\nTrocas: %d\n", comparacoesAleatorio,
         trocasAleatorio);

  printf("\n=============================  QUICKSORT COM PIVO NA MEDIANA  "
         "====================================\n");
  quickSortMedian(matrizMediana, 0, numCols - 1, &comparacoesMediana,
                  &trocasMediana);
  printf("Comparacoes: %d\nTrocas: %d\n", comparacoesMediana, trocasMediana);
}

int main() {
  int matrizAleatoria[numRows][maxCols];
  int numCols, maxElement;

  srand(time(NULL));

  system("cls");

  printf("Quantidade de elementos: ");
  scanf("%d", &numCols);

  printf("Valor maximo que pode ser gerado: ");
  scanf("%d", &maxElement);

  system("cls");

  gerarMatrizAleatoria(matrizAleatoria, numCols, maxElement);

  system("cls");

  selectionSort(matrizAleatoria, numCols);
  bubbleSort(matrizAleatoria, numCols);
  insertionSort(matrizAleatoria, numCols);
  shellSort(matrizAleatoria, numCols);
  callMergeSort(matrizAleatoria, numCols);
  callQuickSort(matrizAleatoria, numCols);

  return 0;
}