#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
  int info;
  struct reg *prox;
} *no;

// a)
void cria_lista(no *lista) { *lista = NULL; }

// b)
void inclui_inicio(no *lista, int info) {
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  p->prox = *lista;
  *lista = p;
}

// c)
void inclui_fim(no *lista, int info) {
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  p->prox = NULL;
  if (*lista == NULL)
    *lista = p;
  else {
    no q = *lista;
    while (q->prox)
      q = q->prox;
    q->prox = p;
  }
}

// f)
void imprimir_lista(no lista) {
  no p = lista;
  while (p) {
    printf("%d ", p->info);
    p = p->prox;
  }
}

// g)
int contar_nos(no lista) {
  no p = lista;
  int cont = 0;
  while (p) {
    cont++;
    p = p->prox;
  }
  return cont;
}

// h)
bool busca(no lista, int x) {
  no p = lista;
  while (p) {
    if (p->info == x)
      return true;
    p = p->prox;
  }
  return false;
}

// i)
int k_enesimo_elemento(no lista, int k) {
  no p = lista;
  for (int i = 0; i < k; i++) {
    p = p->prox;
  }
  return p->info;
}

// j)
int remover_inicio(no *lista) {
  if (!*lista)
    return 0;
  no p = *lista;
  *lista = p->prox;
  free(p);
  return 1;
}

// k)
int remover_fim(no *lista) {
  if (!*lista)
    return 0;

  no p = *lista;
  no anterior = NULL;

  while (p->prox) {
    anterior = p;
    p = p->prox;
  }

  if (anterior == NULL) {
    free(*lista);
    *lista = NULL;
  } else {
    anterior->prox = NULL;
    free(p);
  }

  return 1;
}

void remover_k_elemento(no *lista, int k) {
  no p = *lista;
  for (int i = 0; i < k - 1; i++) {
    p = p->prox;
  }
  no aux = p->prox;    // aux = k-esimo
  p->prox = aux->prox; // p->prox = k+1-esimo
  free(aux);           // libera k-esimo
}

void apagar_lista(no *lista) {
  while (*lista) {
    no p = *lista;
    *lista = p->prox;
    free(p);
  }
}

int main() {
  no lista;
  cria_lista(&lista);

  inclui_inicio(&lista, 10);
  inclui_fim(&lista, 20);
  inclui_inicio(&lista, 30);
  inclui_fim(&lista, 40);
  inclui_fim(&lista, 50);
  inclui_fim(&lista, 60);
  inclui_fim(&lista, 70);
  inclui_fim(&lista, 80);

  printf("Lista inicial: ");
  imprimir_lista(lista);
  printf("\n");

  remover_inicio(&lista);
  printf("Apos remover o primeiro elemento: ");
  imprimir_lista(lista);
  printf("\n");

  printf("Numero de elementos na lista: %d\n", contar_nos(lista));

  int k = 1;
  if (k < contar_nos(lista)) {
    printf("O %d-esimo elemento na lista eh: %d\n", k,
           k_enesimo_elemento(lista, k));
  } else {
    printf("Indice %d fora do intervalo da lista.\n", k);
  }

  int valor_busca = 20;
  if (busca(lista, valor_busca)) {
    printf("O valor %d esta na lista.\n", valor_busca);
  } else {
    printf("O valor %d nao esta na lista.\n", valor_busca);
  }

  if (remover_fim(&lista)) {
    printf("Remocao do ultimo elemento bem-sucedida.\n");
  } else {
    printf("A lista esta vazia, nenhum elemento removido.\n");
  }

  printf("Lista apos remover o ultimo elemento: ");
  imprimir_lista(lista);
  printf("\n");

  int k_para_remover = 1;
  remover_k_elemento(&lista, k_para_remover);
  printf("Lista apos remover o %d-esimo elemento: ", k_para_remover);
  imprimir_lista(lista);
  printf("\n");

  apagar_lista(&lista);
  printf("Lista apos apagar todos os elementos: ");
  imprimir_lista(lista);
  printf("\n");

  return 0;
}
