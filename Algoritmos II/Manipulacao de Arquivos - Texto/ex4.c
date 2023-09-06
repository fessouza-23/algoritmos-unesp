#include <stdio.h>
#include <stdlib.h>

float calcularMedia(float nota1, float nota2) { return (nota1 + nota2) / 2; }

int main() {
  FILE *file;
  char nome_arquivo[20], nome_aluno[50];
  int quant;
  float nota1, nota2;

  system("cls");
  printf("Nome do arquivo de texto .txt: ");
  gets(nome_arquivo);

  if ((file = fopen(nome_arquivo, "r")) == NULL) {
    printf("Erro ao abrir o arquivo.\n\n");
    getch();
    return 1;
  }

  if (fscanf(file, "%d", &quant) != 1) {
    printf("Erro ao ler a quantidade de alunos do arquivo.\n");
    fclose(file);
    getch();
    return 1;
  }

  system("cls");
  printf("Alunos com nota menor que 5.0:\n");

  for (int i = 0; i < quant; i++) {
    fgetc(file); // Ler a quebra de linha após a quantidade
    fgets(nome_aluno, sizeof(nome_aluno), file);
    fscanf(file, "%f %f", &nota1, &nota2);

    if (calcularMedia(nota1, nota2) < 5.0) {
      printf("Nome do aluno: %s", nome_aluno);
    }
  }

  fclose(file);
  return 0;
}
