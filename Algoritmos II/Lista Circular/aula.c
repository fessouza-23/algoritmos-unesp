#include <stdio.h>
#include <stdlib.h>

// lista circular

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

  if (*lista == NULL) {
    p->prox = p;
  } else {
    no q = *lista;
    while (q->prox != *lista) {
      q = q->prox;
    }
    q->prox = p;
  }

  *lista = p;
}

// c)
void mostrar_lista(no lista) {
  if (lista == NULL) {
    printf("Lista vazia\n");
    return;
  }

  no p = lista;
  do {
    printf("%d ", p->info);
    p = p->prox;
  } while (p != lista);

  printf("\n");
}

// d)
void inclui_final(no *lista, int info) {
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  p->prox = *lista;

  if (*lista == NULL) {
    *lista = p;
    p->prox = p;
  } else {
    no q = *lista;
    while (q->prox != *lista) {
      q = q->prox;
    }
    q->prox = p;
  }
}

// e)
void remover_inicio(no *lista) {
  if (*lista != NULL) {
    no inicio = *lista;
    no fim = *lista;
    *lista = inicio->prox;
    while (fim->prox != inicio) {
      fim = fim->prox;
    }
    if (*lista != NULL) {
      fim->prox = *lista;
    } else {
      fim->prox = NULL;
    }
    free(inicio);
  }
}

no buscar(no lista, int info, int *pos) {
  if (lista != NULL) {
    no p = lista;
    *pos = 0;

    do {
      if (p->info == info)
        return p;
      p = p->prox;
      (*pos)++;
    } while (p != lista);
  }

  return NULL;
}

void rotacionar(no *lista) {
  if (*lista != NULL)
    *lista = (*lista)->prox;
}

void rotacionar_ate_elem(no *lista, int info) {
  int pos;
  no p = buscar(*lista, info, &pos);
  if (p != NULL)
    *lista = p;
}

int remover_todas_ocorrencias(no *lista, int info) {
    if(*lista == NULL)
        return 0;
    
    int cont_remocoes = 0;

    // remocao no inicio
    while(*lista && info == (*lista)->info) {
        remover_inicio(lista);
        cont_remocoes++;
    }

    if(*lista == NULL)
        return cont_remocoes;

    no q = (*lista)->prox;

}

int main() {
  no lista;
  cria_lista(&lista);

  // Testando inclui_inicio
  inclui_inicio(&lista, 10);
  inclui_inicio(&lista, 20);
  inclui_inicio(&lista, 30);
  printf("Lista apos inclui_inicio: ");
  mostrar_lista(lista);

  // Testando inclui_final
  inclui_final(&lista, 40);
  inclui_final(&lista, 50);
  inclui_final(&lista, 60);
  printf("Lista apos inclui_final: ");
  mostrar_lista(lista);

  // Testando remover_inicio
  remover_inicio(&lista);
  printf("Lista apos remover_inicio: ");
  mostrar_lista(lista);

  // Testando buscar
  int pos;
  no elemento = buscar(lista, 40, &pos);
  if (elemento != NULL) {
    printf("Elemento 40 encontrado na posicao %d\n", pos);
  } else {
    printf("Elemento 40 nao encontrado\n");
  }

  // Testando rotacionar
  rotacionar(&lista);
  printf("Lista apos rotacionar: ");
  mostrar_lista(lista);

  // Testando rotacionar_ate_elem
  rotacionar_ate_elem(&lista, 50);
  printf("Lista apos rotacionar ate o elemento 50: ");
  mostrar_lista(lista);

  return 0;
}
