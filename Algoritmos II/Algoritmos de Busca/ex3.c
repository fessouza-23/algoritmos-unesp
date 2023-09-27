#include <stdio.h>
#include <string.h>

FILE *abrirArquivo(const char nome_arquivo[20], const char op[5]) {
  FILE *file;
  if ((file = fopen(nome_arquivo, op)) == NULL) {
    printf("Erro ao abrir o arquivo.\n\n");
    getch();
  }
  return file;
}

int confirma() {
  printf("\nDeseja continuar? (s/n): ");
  if (getch() == 's') {
    return 1;
  } else {
    return 0;
  }
}

void buscaBinaria(char lista_nomes[61][121], int n, char x[121]) {
  int i;
  int esquerda = 0;
  int direita = n - 1;
  int encontrados = 0; // Contador para nomes encontrados

  printf("Nomes encontrados:\n");

  while (esquerda <= direita) {
    int meio = (esquerda + direita) / 2;
    char primeiro_nome[121];
    sscanf(lista_nomes[meio], "%120s", primeiro_nome);

    if (strcmp(primeiro_nome, x) == 0) {
      printf("%s", lista_nomes[meio]);
      encontrados++;

      // busca à esquerda
      int j = meio - 1;
      while (j >= 0 && strcmp(primeiro_nome, x) == 0) {
        sscanf(lista_nomes[j], "%120s", primeiro_nome);
        if (strcmp(primeiro_nome, x) == 0) {
          printf("%s", lista_nomes[j]);
          encontrados++;
        }
        j--;
      }

      // busca à direita
      j = meio + 1;
      while (j < n && strcmp(primeiro_nome, x) == 0) {
        sscanf(lista_nomes[j], "%120s", primeiro_nome);
        if (strcmp(primeiro_nome, x) == 0) {
          printf("%s", lista_nomes[j]);
          encontrados++;
        }
        j++;
      }

      break; // Encerra o loop quando encontrar o nome.
    } else if (strcmp(primeiro_nome, x) > 0) {
      direita = meio - 1;
    } else {
      esquerda = meio + 1;
    }
  }

  if (encontrados == 0) {
    printf("Nenhum nome encontrado para '%s'\n", x);
  }
}

int main() {
  char lista_nomes[61][121];
  int i;
  FILE *file;

  file = abrirArquivo("nomes.txt", "r");

  for (i = 0; i < 60; i++) {
    if (fgets(lista_nomes[i], 121, file) == NULL) {
      break; // Encerra o loop se não houver mais linhas para ler.
    }
  }

  fclose(file);

  char nome_consulta[121];
  system("cls");
  do {
    printf("\nDigite o nome a ser procurado: ");
    scanf("%s", nome_consulta);
    buscaBinaria(lista_nomes, 60, nome_consulta);
  } while (confirma());

  return 0;
}
