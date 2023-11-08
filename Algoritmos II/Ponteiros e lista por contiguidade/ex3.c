#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd) {
  int i, j;

  *qtd = n1 + n2;

  int *x3 = (int *)malloc(*qtd * sizeof(int));

  for (i = 0; i < n1; i++) {
    x3[i] = x1[i];
  }

  j = n1;
  for (i = 0; i < n2; i++) {
    int achou = 0;
    for (int k = 0; k < n1; k++) {
      if (x2[i] == x1[k]) {
        achou = 1;
        break;
      }
    }
    if (!achou) {
      x3[j] = x2[i];
      j++;
    }
  }

  *qtd = j;

  int *uniao = (int *)malloc(*qtd * sizeof(int));
  for (i = 0; i < *qtd; i++) {
    uniao[i] = x3[i];
  }

  free(x3);

  return uniao;
}

int main() {
  int x1[] = {1, 3, 5, 6, 7};
  int x2[] = {1, 3, 4, 6, 8};
  int n1 = 5;
  int n2 = 5;

  int qtd;
  int *x3 = uniao(x1, x2, n1, n2, &qtd);

  printf("x3 = {");
  for (int i = 0; i < qtd; i++) {
    printf("%d", x3[i]);
    if (i < qtd - 1) {
      printf(", ");
    }
  }
  printf("}\n");

  free(x3);

  return 0;
}