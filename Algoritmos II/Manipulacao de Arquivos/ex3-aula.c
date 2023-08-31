#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nome_arquivo[] = "estoque.dat";

typedef struct
{
    int cod;
    int quant;
    int existe;
    float valor_unitario;
    char descricao[20];
} Produto;

void cadastra()
{
    Produto produto;
    char resp[10];
    FILE *file;

    system("cls");

    // Abertura de arquivo
    if ((file = fopen(nome_arquivo, "a+b")) == NULL)
    {
        printf("Erro na abertura do arquivo.\n\n");
        getchar();
        return;
    }

    // Leitura e gravação
    do
    {
        // Lendo dados do produto
        produto.existe = 1;
        printf("\n\nCodigo do produto: ");
        scanf("%d", &produto.cod);

        printf("Quantidade em estoque do produto: ");
        scanf("%d", &produto.quant);

        printf("Valor unitario: ");
        scanf("%f", &produto.valor_unitario);

        printf("Descricao: ");
        scanf("%19s", produto.descricao); // Usando %19s para evitar overflow

        // salvando produto no arquivo
        fwrite(&produto, sizeof(Produto), 1, file);

        // Verificando se o usuário deseja inserir um novo produto
        printf("\n Adicionar outro produto (s/n)?: ");
        scanf("%s", resp);
    } while (toupper(resp[0]) == 'S');
    // Fechando arquivo
    fclose(file);
}

void mostra()
{
    FILE *file;
    Produto produto;

    system("cls");

    // Abertura do arquivo
    if ((file = fopen(nome_arquivo, "rb")) == NULL)
    {
        printf("\nErro de abertura de arquivo.\n\n");
        getchar();
        return;
    }

    // Leitura de produtos
    printf("CODIGO    QUANTIDADE     VALOR UNITARIO       DESCRICAO");
    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe == 1)
        {
            printf("\n%3d %11d %19.2f %16s", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);
        }
    }

    // Fechamento do arquivo
    fclose(file);
    getch();
}


void menu(char *opcao)
{
    system("cls");
    printf("\n       M E N U ");
    printf("\n 1 - Cadastrar produto.");
    printf("\n 2 - Mostrar todos os produtos.");
    printf("\n 3 - Consultar produto pelo codigo.");
    printf("\n 5 - Altera produto pelo codigo.");
    printf("\n 6 - Apaga pelo codigo.");
    printf("\n 7 - Sair");
    printf("\n\n Opcao ---> ");
    do
    {
        *opcao = getch();
    } while (*opcao < '1' || *opcao > '7');
}

int main()
{
    char opcao;

    do
    {
        menu(&opcao);
        switch (opcao)
        {
        case '1':
            cadastra();
            break;
        case '2':
            mostra();
            break;
        case '3':
            // consultaNumero(nome_arquivo);
            break;
        case '4':
            // consultaNome(nome_arquivo);
            break;
        case '5':
            // alteraNumero(nome_arquivo);
            break;
        case '6':
            // apagaRegNumero(nome_arquivo);
            break;
        case '7':
            break;
        default:
            printf("\nOpcao errada.\n");
        }
    } while (opcao != '7');

    return 0;
}
