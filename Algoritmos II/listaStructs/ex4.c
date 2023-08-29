#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numerador;
    int denominador;
} racional;

void lerRacional(racional *racional)
{
    printf("Numerador: ");
    scanf("%d", &racional->numerador);
    printf("Denominador: ");
    scanf("%d", &racional->denominador);
    printf("\n");
}

int mdc(int num1, int num2)
{
    while (num2 != 0)
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int mmc(int num1, int num2)
{
    return num1 * (num2 / mdc(num1, num2));
}

racional somarRacionais(racional racional1, racional racional2)
{
    int mmc_var = mmc(racional1.denominador, racional2.denominador);
    
    racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
    racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

    racional result = {
        .numerador = racional1.numerador + racional2.numerador,
        .denominador = mmc_var
    };

    return result;
}

racional subtrairRacionais(racional racional1, racional racional2)
{
    int mmc_var = mmc(racional1.denominador, racional2.denominador);
    
    racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
    racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

    racional result = {
        .numerador = racional1.numerador - racional2.numerador,
        .denominador = mmc_var
    };

    return result;
}

racional multiplicarRacionais(racional racional1, racional racional2)
{
    racional result = {
        .numerador = racional1.numerador * racional2.numerador,
        .denominador = racional1.denominador * racional2.denominador
    };

    return result;
}

void imprimirRacional(racional r)
{
    printf("%d/%d", r.numerador, r.denominador);
}

int main()
{
    racional racional1, racional2;

    printf("RACIONAL 1\n");
    lerRacional(&racional1);

    printf("\nRACIONAL 2\n");
    lerRacional(&racional2);

    racional resultado_soma_racionais = somarRacionais(racional1, racional2);

    printf("\nSOMA\n");
    imprimirRacional(racional1);
    printf(" + ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(resultado_soma_racionais);
    printf("\n");

    racional resultado_subtracao_racionais = subtrairRacionais(racional1, racional2);

    printf("\nSUBTRACAO\n");
    imprimirRacional(racional1);
    printf(" - ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(resultado_subtracao_racionais);
    printf("\n");

    racional resultado_multiplicacao_racionais = multiplicarRacionais(racional1, racional2);

    printf("\nMULTIPLICACAO\n");
    imprimirRacional(racional1);
    printf(" * ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(resultado_multiplicacao_racionais);
    printf("\n");

    return 0;
}
