#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
  int info;
  struct reg *prox;
} *no;

// d)
void inclui_ordenado(no *lista, int info) {
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  p->prox = NULL;

  no atual = *lista;
  no anterior = NULL;

  while (atual != NULL && p->info > atual->info) {
    anterior = atual;
    atual = atual->prox;
  }

  if (anterior == NULL) {
    p->prox = *lista;
    *lista = p;
  } else {
    anterior->prox = p;
    p->prox = atual;
  }
}

int main() {
  no lista;
  lista = NULL;

  inclui_ordenado(&lista, 30);
  inclui_ordenado(&lista, 10);
  inclui_ordenado(&lista, 50);
  inclui_ordenado(&lista, 20);
  inclui_ordenado(&lista, 40);

  no p = lista;
  while (p != NULL) {
    printf("%d ", p->info);
    p = p->prox;
  }

  while (lista != NULL) {
    no temp = lista;
    lista = lista->prox;
    free(temp);
  }

  return 0;
}
