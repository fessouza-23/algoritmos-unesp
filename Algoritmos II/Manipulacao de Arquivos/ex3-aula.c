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
        getch();
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
        getch();
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

void consultaCodigo()
{
    FILE *file;
    Produto produto;
    int achou = 0;
    int codigo_referencia;

    system("cls");

    // abertura do arquivo
    if ((file = fopen(nome_arquivo, "rb")) == NULL)
    {
        printf("\nErro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    // cod para consulta
    printf("\nCodigo do produto a ser consultado: ");
    scanf("%d", &codigo_referencia);

    // leitura dos registro
    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe && produto.cod == codigo_referencia)
        {
            system("cls");
            printf("CODIGO    QUANTIDADE     VALOR UNITARIO       DESCRICAO");
            printf("\n%3d %11d %19.2f %16s\n", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("O produto de codigo %d nao esta cadastrado.\n\n", codigo_referencia);

    fclose(file);
    getch();
}

void alteraCodigo()
{
    FILE *file;
    Produto produto;
    int codigo_referencia, achou = 0;

    system("cls");

    // abertura do arquivo
    if ((file = fopen(nome_arquivo, "r+b")) == NULL)
    {
        printf("\nErro na abertura do arquivo.\n\n");
        getch();
        return;
    }

    // codigo de referencia
    printf("Codigo do produto que deseja alterar: ");
    scanf("%d", &codigo_referencia);

    // leitura dos produtos
    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe && produto.cod == codigo_referencia)
        {
            system("cls");
            printf("CODIGO    QUANTIDADE     VALOR UNITARIO       DESCRICAO");
            printf("\n%3d %11d %19.2f %16s\n", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);

            // atualização do registro
            printf("\nQuantidade: ");
            scanf("%d", &produto.quant);

            printf("Valor unitario: ");
            scanf("%f", &produto.valor_unitario);

            printf("Descricao: ");
            fflush(stdin);
            gets(produto.descricao);

            // volta o ponteiro para o inicio do registro
            fseek(file, -sizeof(Produto), SEEK_CUR);
            // grava os dados alterados
            fwrite(&produto, sizeof(Produto), 1, file);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("O produto de codigo %d nao esta cadastrado.\n\n", codigo_referencia);
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
    printf("\n 4 - Alterar produto pelo codigo.");
    printf("\n 5 - Apagar pelo codigo.");
    printf("\n 6 - Sair");
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
            consultaCodigo();
            break;
        case '4':
            alteraCodigo();
            break;
        case '5':
            // alteraNumero(nome_arquivo);
            break;
        case '6':
            exit();
            break;
        default:
            printf("\nOpcao errada.\n");
        }
    } while (opcao != '7');

    return 0;
}
