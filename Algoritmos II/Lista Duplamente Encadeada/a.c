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
    //Criação do nó p
    no p = (no) malloc(sizeof(struct reg));
	p->info = info;

	if (!*lista) 
	{
        //Se a lista for vazia
		p->ant = NULL;
		p->prox = NULL;
		*lista = p;
	} 
	else if ((*lista)->info >= info) 
	{
        // Se o elemento for menor que o primeiro elemento da lista
        // Neste caso inserimos no inicio
		p->ant = NULL;
		p->prox = *lista;
        if (*lista)
            (*lista)->ant=p;
		*lista = p;
	}
	else
	{
        // Elemento sera incluido no meio ou final da lista
        // Obter q = 1o elemento maior ou igual a info (se nao houver, volta para o inicio)
        //           ou ultimo nó (se todos os elementos forem menor que info)
        no q = *lista;
		while(q->prox != NULL && q->info < info)
			q = q->prox;

		if(q->info >= info) //Se q->info for maior ou igual a info
		{
            //Insere no meio de q->ant e q
			p->prox = q;
			p->ant = q->ant;
			q->ant->prox = p;
			q->ant = p; 	
		} 
		else //Caso contrário, insere no final
		{
			p->ant = q;
			p->prox = NULL;
			q->prox = p;
		}
	}
}

int main() {
    no lista;
    cria_lista(&lista);

    incluir_comeco(&lista, 80);
    incluir_comeco(&lista, 70);
    incluir_comeco(&lista, 50);
    mostrar_lista(lista);
    incluir_ordenado(&lista, 60);
    mostrar_lista(lista);

}