#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  char estado[20];
} Paciente;

typedef struct {
  Paciente *pacientes;
  int capacidade;
  int tamanho;
} ListaPacientes;

ListaPacientes criarLista(int capacidade) {
  ListaPacientes lista;
  lista.capacidade = capacidade;
  lista.tamanho = 0;
  lista.pacientes = (Paciente *)malloc(capacidade * sizeof(Paciente));
  return lista;
}

void adicionarPaciente(ListaPacientes *lista, Paciente paciente) {
  if (lista->tamanho == lista->capacidade) {
    printf("A lista de pacientes está cheia.\n");
    return;
  }
  lista->pacientes[lista->tamanho] = paciente;
  lista->tamanho++;
}

void exibirListaPacientes(ListaPacientes lista) {
  printf("Pacientes:\n");
  for (int i = 0; i < lista.tamanho; i++) {
    printf("%s - %s\n", lista.pacientes[i].nome, lista.pacientes[i].estado);
  }
}

void priorizarPacientes(ListaPacientes *lista) {
  for (int i = 0; i < lista->tamanho - 1; i++) {
    for (int j = i + 1; j < lista->tamanho; j++) {
      if (strcmp(lista->pacientes[i].estado, lista->pacientes[j].estado) > 0) {
        Paciente temp = lista->pacientes[i];
        lista->pacientes[i] = lista->pacientes[j];
        lista->pacientes[j] = temp;
      }
    }
  }
}

int main() {
  ListaPacientes lista = criarLista(10);

  Paciente paciente1;
  strcpy(paciente1.nome, "Joao");
  strcpy(paciente1.estado, "ruim");
  adicionarPaciente(&lista, paciente1);

  Paciente paciente2;
  strcpy(paciente2.nome, "Maria");
  strcpy(paciente2.estado, "pessimo");
  adicionarPaciente(&lista, paciente2);

  Paciente paciente3;
  strcpy(paciente3.nome, "Pedro");
  strcpy(paciente3.estado, "regular");
  adicionarPaciente(&lista, paciente3);

  printf("Lista de pacientes antes da priorizacao:\n");
  exibirListaPacientes(lista);

  priorizarPacientes(&lista);

  printf("\nLista de pacientes apos a priorizacao:\n");
  exibirListaPacientes(lista);

  free(lista.pacientes);

  return 0;
}