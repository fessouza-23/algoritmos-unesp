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
    int mmc_var;
    racional result;

    mmc_var = mmc(racional1.denominador, racional2.denominador);

    racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
    racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

    result.numerador = racional1.numerador + racional2.numerador;
    result.denominador = mmc_var;

    return result;
}

racional subtrairRacionais(racional racional1, racional racional2)
{
    int mmc_var;
    racional result;

    mmc_var = mmc(racional1.denominador, racional2.denominador);

    racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
    racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

    result.numerador = racional1.numerador - racional2.numerador;
    result.denominador = mmc_var;

    return result;
}

racional multiplicarRacionais(racional racional1, racional racional2) {
    racional result;

    result.numerador = racional1.numerador * racional2.numerador;
    result.denominador = racional1.denominador * racional2.denominador;

    return result;
}

    int main()
{
    racional racional1, racional2;

    lerRacional(&racional1);
    lerRacional(&racional2);

    racional resultado_soma_racionais = somarRacionais(racional1, racional2);

    printf("SOMA\n");
    printf("%d/%d + %d/%d = %d/%d\n",
           racional1.numerador, racional1.denominador,
           racional2.numerador, racional2.denominador,
           resultado_soma_racionais.numerador, resultado_soma_racionais.denominador);

    racional resultado_subtracao_racionais = subtrairRacionais(racional1, racional2);

    printf("\nSUBTRACAO\n");
    printf("%d/%d + %d/%d = %d/%d\n",
           racional1.numerador, racional1.denominador,
           racional2.numerador, racional2.denominador,
           resultado_subtracao_racionais.numerador, resultado_subtracao_racionais.denominador);

    racional resultado_multiplicacao_racionais = multiplicarRacionais(racional1, racional2);
    
    printf("\nMULTIPLICACAO\n");
    printf("%d/%d + %d/%d = %d/%d\n",
           racional1.numerador, racional1.denominador,
           racional2.numerador, racional2.denominador,
           resultado_multiplicacao_racionais.numerador, resultado_multiplicacao_racionais.denominador);

    return 0;
}