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

void simplificarRacional(racional *racional)
{
    int divisor_comum = mdc(racional->denominador, racional->numerador);
    racional->numerador /= divisor_comum;
    racional->denominador /= divisor_comum;
}

racional realizarOperacao(racional racional1, racional racional2, char operador)
{
    racional result;

    if (operador == '+')
    {
        int mmc_var = mmc(racional1.denominador, racional2.denominador);

        racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
        racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

        result.numerador = racional1.numerador + racional2.numerador;
        result.denominador = mmc_var;
    }
    else if (operador == '-')
    {
        int mmc_var = mmc(racional1.denominador, racional2.denominador);

        racional1.numerador = (mmc_var / racional1.denominador) * racional1.numerador;
        racional2.numerador = (mmc_var / racional2.denominador) * racional2.numerador;

        result.numerador = racional1.numerador - racional2.numerador;
        result.denominador = mmc_var;
    }
    else if (operador == '*')
    {
        result.numerador = racional1.numerador * racional2.numerador;
        result.denominador = racional1.denominador * racional2.denominador;
    }
    else if (operador == '/')
    {
        result.numerador = racional1.numerador * racional2.denominador;
        result.denominador = racional1.denominador * racional2.numerador;
    }

    simplificarRacional(&result);

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

    printf("\nSOMA\n");
    imprimirRacional(racional1);
    printf(" + ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(realizarOperacao(racional1, racional2, '+'));
    printf("\n");

    printf("\nSUBTRACAO\n");
    imprimirRacional(racional1);
    printf(" - ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(realizarOperacao(racional1, racional2, '-'));
    printf("\n");

    printf("\nMULTIPLICACAO\n");
    imprimirRacional(racional1);
    printf(" * ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(realizarOperacao(racional1, racional2, '*'));
    printf("\n");


    printf("\nDIVISAO\n");
    imprimirRacional(racional1);
    printf(" / ");
    imprimirRacional(racional2);
    printf(" = ");
    imprimirRacional(realizarOperacao(racional1, racional2, '/'));
    printf("\n");
    return 0;
}
