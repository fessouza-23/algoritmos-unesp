#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char email[50];
} Aluno;

int main() {
    int quant;

    system("cls");
    
    printf("Quantidade de alunos para registro: ");
    scanf("%d", &quant);

    Aluno alunos[quant];
    getchar(); // trash

    for (int i = 0; i < quant; i++) {
        printf("- Registro %d\n", i+1);
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        getchar();

        printf("Email: ");
        fgets(alunos[i].email, sizeof(alunos[i].email), stdin);
        alunos[i].email[strcspn(alunos[i].email, "\n")] = '\0';
    }

    FILE *file;

    // Gravação do arquivo
    file = fopen("alunos.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    fwrite(&quant, sizeof(int), 1, file);
    fwrite(alunos, sizeof(int), quant, file);
    fclose(file);

    // Leitura do arquivo
    file = fopen("alunos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    fread(&quant, sizeof(int), 1, file);
    printf("Quantidade de alunos: %d", quant);
    fread(alunos, sizeof(int), quant, file);

    for (int i = 0; i < quant; i++) {
        printf("\n\nNome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Email: %s\n", alunos[i].email);
    }

    fclose(file);
    return 0;
}
