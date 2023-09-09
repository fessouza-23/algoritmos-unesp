#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define esc 27
typedef struct {
  int codigo;
  char nome[50];
  int idade;
  char endereco[50];
  char fone[50];
} Cliente;

FILE *abrirArquivo(const char nome_arquivo[20], const char op[5]) {
  FILE *file;
  if ((file = fopen(nome_arquivo, op)) == NULL) {
    printf("Erro ao abrir o arquivo.\n\n");
    exit(1);
  }
  return file;
}

void cadastrarCliente(Cliente *c) {
  FILE *file;

  system("cls");
  printf("CADASTRO DE NOVO CLIENTE\n");
  printf("Codigo: ");
  scanf("%d", &c->codigo);
  fflush(stdin); // Clear input buffer
  printf("Nome: ");
  fgets(c->nome, sizeof(c->nome), stdin);
  c->nome[strlen(c->nome) - 1] = '\0';
  printf("Idade: ");
  scanf("%d", &c->idade);
  fflush(stdin);
  printf("Endereco: ");
  fgets(c->endereco, sizeof(c->endereco), stdin);
  c->endereco[strlen(c->endereco) - 1] = '\0';
  printf("Telefone: ");
  fgets(c->fone, sizeof(c->fone), stdin);
  c->fone[strlen(c->fone) - 1] = '\0';

  // Gravação do Cliente no arquivo
  file = abrirArquivo("clientes.dat", "a+b");
  fwrite(c, sizeof(Cliente), 1, file);
  fclose(file);
}

// Esta função não está dentro as necessárias, serve apenas para testar
void consultarCliente() {
    FILE *file;
    Cliente c;

    system("cls");

    // Abra o arquivo para leitura
    file = abrirArquivo("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&c, sizeof(Cliente), 1, file) == 1) {
        printf("%d %s %d %s %s\n", c.codigo, c.nome, c.idade, c.endereco, c.fone);
    }

    fclose(file);
    getch();
}

void menu(Cliente *c) {
  char op;

  do {
    system("cls");
    printf("================================  MENU  "
           "=======================================\n");
    printf("1 - Cadastrar cliente\n");
    printf("2 - Listar clientes\n");
    printf("ESC - Sair\n");
    op = getch();

    switch (op) {
    case '1':
      cadastrarCliente(c);
      break;

    case '2':
      consultarCliente(c);
      break;

    case esc:
      // Handle the ESC key press
      break;

    default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
    }
  } while (op != esc);
}

int main() {
  Cliente c;
  menu(&c);
  return 0;
}