#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *abrirArquivo(const char nome_arquivo[20], const char op[5]) {
  FILE *file;
  if ((file = fopen(nome_arquivo, op)) == NULL) {
    printf("Erro ao abrir o arquivo.\n\n");
    exit(1);
  }
  return file;
}

int main() {
  FILE *file, *file2, *file3;
  char texto[81], nome_arquivo1[20];

  // Criando arquivo 1
  system("cls");
  printf("- Gravando no primeiro arquivo -\n");
  file = abrirArquivo("arquivo1.txt", "w");

  // Gravando no arquivo 1
  while (strlen(gets(texto)) > 0) {
    fputs(texto, file);
    putc('\n', file);
  }
  fclose(file);

  // Criando arquivo 2
  system("cls");
  printf("- Gravando no segundo arquivo -\n");
  file = abrirArquivo("arquivo2.txt", "w");

  // Gravando no arquivo 2
  while (strlen(gets(texto)) > 0) {
    fputs(texto, file);
    putc('\n', file);
  }
  fclose(file);

  file = abrirArquivo("arquivo1.txt", "r");
  file2 = abrirArquivo("arquivo2.txt", "r");
  file3 = abrirArquivo("arquivo_merge.txt", "w");

  // Gravando no arquivo 3
  while (fgets(texto, 100, file) != NULL) {
    fprintf(file3, "%s", texto);
  }

  while (fgets(texto, 100, file2) != NULL) {
    fprintf(file3, "%s", texto);
  }

  printf("Arquivo merge criado.\n");
  getch();
  fclose(file);
  fclose(file2);
  fclose(file3);

  return 0;
}
