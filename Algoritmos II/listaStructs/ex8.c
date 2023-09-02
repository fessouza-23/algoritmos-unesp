#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Para a função toupper
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[50];
    char RG[30];
    float salario;
    int idade;
    char sexo[20];
    Data dataNascimento;
} TipoReg;

typedef struct
{
    TipoReg funcionario[100];
    int quant;
} TipoCadastro;

void IniciaCadastro(TipoCadastro *cadastro)
{
    cadastro->quant = 0;
}

void LeFuncionarios(TipoCadastro *cadastro)
{
    char resp[2];
    do
    {
        cadastro->quant++;
        printf("FUNCIONARIO %d\n", cadastro->quant);

        printf("Nome: ");
        fgets(cadastro->funcionario[cadastro->quant - 1].nome, sizeof(cadastro->funcionario[cadastro->quant - 1].nome), stdin);
        cadastro->funcionario[cadastro->quant - 1].nome[strcspn(cadastro->funcionario[cadastro->quant - 1].nome, "\n")] = '\0';

        printf("RG: ");
        fgets(cadastro->funcionario[cadastro->quant - 1].RG, sizeof(cadastro->funcionario[cadastro->quant - 1].RG), stdin);
        cadastro->funcionario[cadastro->quant - 1].RG[strcspn(cadastro->funcionario[cadastro->quant - 1].RG, "\n")] = '\0';

        printf("\nAdicionar outro funcionario (s/n)?: ");
        scanf("%1s", resp);

        while (getchar() != '\n');

    } while (toupper(resp[0]) == 'S');
}

int main()
{
    TipoCadastro cadastro;
    IniciaCadastro(&cadastro);
    LeFuncionarios(&cadastro);

    return 0;
}
