#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file, *file2, *file3;
  char texto[81], nome_arquivo1[20];

  system("cls");
  printf("- Gravando no primeiro arquivo -\n");
  if ((file = fopen("arquivo1.txt", "a+")) == NULL) {
    printf("\n file não pode ser aberto");
    getch();
    return 1;
  }

  while (strlen(gets(texto)) > 0) {
    fputs(texto, file);
    putc('\n', file);
  }
  fclose(file);

  system("cls");
  printf("- Gravando no segundo arquivo -\n");
  if ((file = fopen("arquivo2.txt", "a+")) == NULL) {
    printf("\n file não pode ser aberto");
    getch();
    return 1;
  }

  while (strlen(gets(texto)) > 0) {
    fputs(texto, file);
    putc('\n', file);
  }
  fclose(file);

  if ((file = fopen("arquivo1.txt", "r")) == NULL) {
    printf("Erro ao abrir o arquivo1.txt\n");
    getch();
    return 1;
  }

  if ((file2 = fopen("arquivo2.txt", "r")) == NULL) {
    printf("Erro ao abrir o arquivo2.txt\n");
    getch();
    return 1;
  }

  if ((file3 = fopen("arquivo_merge.txt", "a+")) == NULL) {
    printf("Erro ao abrir o arquivo_merge.txt\n");
    getch();
    return 1;
  }

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
