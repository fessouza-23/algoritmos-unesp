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
    char descricao[50];
} Produto;

char confirma()
{
    char resp;
    printf("Confirma (S/N)?");
    do
    {
        resp = toupper(getch());
    } while (resp != 'S' && resp != 'N');
    return resp;
}

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
        getchar();

        printf("Quantidade em estoque do produto: ");
        scanf("%d", &produto.quant);
        getchar();

        printf("Valor unitario: ");
        scanf("%f", &produto.valor_unitario);
        getchar();

        printf("Descricao: ");
        fgets(produto.descricao, sizeof(produto.descricao), stdin);

        // Removendo o caractere de nova linha no final da descrição
        size_t len = strlen(produto.descricao);
        if (len > 0 && produto.descricao[len - 1] == '\n') {
            produto.descricao[len - 1] = '\0';
        }

        // Salvando produto no arquivo
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
            printf("\n%3d %11d %19.2f %18s", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);
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

    // Abertura do arquivo
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
            printf("\n%3d %11d %19.2f %18s", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("O produto de codigo %d nao esta cadastrado.\n\n", codigo_referencia);

    fclose(file);
    getch();
}

void alteraRegCodigo()
{
    FILE *file;
    Produto produto;
    int codigo_referencia, achou = 0;

    system("cls");

    // Abertura do arquivo
    if ((file = fopen(nome_arquivo, "r+b")) == NULL)
    {
        printf("\nErro na abertura do arquivo.\n\n");
        getch();
        return;
    }

    // Codigo de referencia
    printf("Codigo do produto que deseja alterar: ");
    scanf("%d", &codigo_referencia);

    // Leitura dos produtos
    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe && produto.cod == codigo_referencia)
        {
            system("cls");
            printf("CODIGO    QUANTIDADE     VALOR UNITARIO       DESCRICAO");
            printf("\n%3d %11d %19.2f %16s\n", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);

            // Atualização do registro
            printf("\nQuantidade: ");
            scanf("%d", &produto.quant);

            printf("Valor unitario: ");
            scanf("%f", &produto.valor_unitario);

            printf("Descricao: ");
            fflush(stdin);
            gets(produto.descricao);

            // Volta o ponteiro para o inicio do registro
            fseek(file, -sizeof(Produto), SEEK_CUR);
            // Grava os dados alterados
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

void apagaRegCodigo()
{
    FILE *file;
    Produto produto;
    int codigo_referencia, achou = 0;

    system("cls");

    // Abertura do arquivo
    if ((file = fopen(nome_arquivo, "r+b")) == NULL)
    {
        printf("\nErro na abertura de arquivo.\n\n");
        getch();
        return;
    }

    printf("Codigo do produto que deseja excluir: ");
    scanf("%d", &codigo_referencia);

    // Leitura dos registros
    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe && produto.cod == codigo_referencia)
        {
            system("cls");
            printf("CODIGO    QUANTIDADE     VALOR UNITARIO     DESCRICAO");
            printf("\n%3d %11d %19.2f %22s\n", produto.cod, produto.quant, produto.valor_unitario, produto.descricao);

            if (confirma() == 'S')
            {
                produto.existe = 0;
                // Voltando ponteiro
                fseek(file, -sizeof(Produto), SEEK_CUR);
                // Gravando dados alterados
                fwrite(&produto, sizeof(Produto), 1, file);
                fflush(file);
                printf("\nProduto removido.\n\n");
            }
            else
            {
                printf("\n\nProduto codigo %d nao removido.\n\n", produto.cod);
            }
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("Produto de codigo %d nao esta cadastrado.\n\n", codigo_referencia);
    fclose(file);
    getch();
}

void remocaoFisica()
{
    FILE *file;
    FILE *arqaux;
    Produto produto;

    // Abertura do arquivo
    if ((file = fopen(nome_arquivo, "rb")) == NULL)
    {
        printf("\nErro na realizacao da remocao fisica.\n\n");
        getch();
        return;
    }

    // Abre um arquivo auxiliar para copiar os registros nao removidos logicamente
    arqaux = fopen("NOME.bak", "wb");

    while (fread(&produto, sizeof(Produto), 1, file) == 1)
    {
        if (produto.existe)
            fwrite(&produto, sizeof(Produto), 1, arqaux); // Copiando dados para arquivo auxiliar
    }
    fclose(file);
    fclose(arqaux);

    remove(nome_arquivo);
    rename("NOME.BAK", nome_arquivo);

    printf("\n\nRemocao fisica realizada.");
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
            alteraRegCodigo();
            break;
        case '5':
            apagaRegCodigo();
            break;
        case '6':
            break;
        default:
            printf("\nOpcao errada.\n");
        }
    } while (opcao != '6');
    remocaoFisica();
    return 0;
}
