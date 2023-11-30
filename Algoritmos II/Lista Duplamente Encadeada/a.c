#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int info;
    struct reg *ant;
    struct reg *prox;
} *no;

void cria_lista (no *lista) {
    *lista = NULL;
}

void mostrar_lista(no lista) {
    no p = lista;
    while(p) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void incluir_comeco(no *lista, int info) {
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = *lista;
    p->ant = NULL;

    if(*lista)
        p->prox->ant = p;

    *lista = p;
}

void incluir_final(no *lista, int info) {
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = NULL;
    no q = *lista;

    if(*lista == NULL) {
        *lista = p;
    } else {
        while(q->prox){
            q = q->prox;
        }
        p->ant = q;
        q->prox = p;
    }
}

void incluir_ordenado(no *lista, int info){
    no p = (no) malloc(sizeof(struct reg));
	p->info = info;

	if (!*lista) 
	{
		p->ant = NULL;
		p->prox = NULL;
		*lista = p;
	} 
	else if ((*lista)->info >= info) {
		p->ant = NULL;
		p->prox = *lista;
        if (*lista)
            (*lista)->ant=p;
		*lista = p;
	}
	else {
        no q = *lista;
		while(q->prox != NULL && q->info < info)
			q = q->prox;

		if(q->info >= info) {
			p->prox = q;
			p->ant = q->ant;
			q->ant->prox = p;
			q->ant = p; 	
		} 
		else {
			p->ant = q;
			p->prox = NULL;
			q->prox = p;
		}
	}
}

void remover_comeco(no *lista){
    no p = *lista;
    *lista = p->prox;
    free(p);
    (*lista)->ant = NULL;
}

void remover_fim(no *lista) {
    no p = *lista;
    while(p->prox) {
        p = p->prox;
    }
    p->ant->prox = NULL;
    free(p);
}

void buscar_elemento(no lista, int x) {
    no p = lista;
    int i = 0, achou = 0;
    while(p) {
        if(p->info == x) {
            printf("Elemento %d achado: i = %d\n", x, i);
            achou = 1;
            break;
        }
        i++;
        p = p->prox;
    }
    if(!achou) {
        printf("Elemento nao encontrado!\n");
    }
}

void apagar_lista(no *lista){
    no p = (*lista)->prox;
    while(p){
        free(p->ant);
        p = p->prox;
    }
    *lista = NULL;
}

int main() {
    no lista;
    cria_lista(&lista);

    incluir_comeco(&lista, 80);
    incluir_comeco(&lista, 70);
    incluir_comeco(&lista, 50);
    incluir_final(&lista, 90);
    mostrar_lista(lista);
    incluir_ordenado(&lista, 60);
    mostrar_lista(lista);
    remover_comeco(&lista);
    mostrar_lista(lista);
    remover_fim(&lista);
    mostrar_lista(lista);
    buscar_elemento(lista, 60);
    apagar_lista(&lista);
    mostrar_lista(lista);
}