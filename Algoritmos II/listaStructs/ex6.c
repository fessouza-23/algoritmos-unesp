#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} dma;

int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calcularDias(dma data1, dma data2) {
    int quant_dias = 0;
    int i;

    if (data2.ano > data1.ano || (data2.ano == data1.ano && data2.mes > data1.mes)) {
        for (i = data1.ano + 1; i < data2.ano; i++) {
            quant_dias += 365;
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
                quant_dias++; // Ano bissexto
            }
        }
        quant_dias += meses[data1.mes - 1] - data1.dia;
        quant_dias += data2.dia;
        for (i = data1.mes; i < 12; i++) {
            quant_dias += meses[i];
        }
        for (i = 0; i < data2.mes - 1; i++) {
            quant_dias += meses[i];
        }
    } else if (data2.ano == data1.ano && data2.mes == data1.mes) {
        quant_dias = abs(data2.dia - data1.dia);
    }

    return quant_dias;
}

int verificarData(dma data1, dma data2) {
    int i;
    
    if (data1.ano > data2.ano || 
        data1.dia > meses[data1.mes-1] || 
        data1.dia < 0 || data1.mes < 1 || 
        data1.mes > 12 || 
        data2.dia > meses[data2.mes-1] || 
        data2.dia < 0 || data2.mes < 1 || 
        data2.mes > 12) {
            return 1;
    } else {
        return 0;
    }
}

int main() {
    int quant_dias;
    dma data1, data2;
    
    system("cls");
    printf("--- CALCULADORA DE DATAS ---\nobs: favor colocar a primeira data como sendo a maior que a segunda\n\n");
    do {
        printf("Digite a primeira data (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);

        printf("Digite a segunda data (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

        (verificarData(data1, data2)) ? printf("Verifique as datas pfv. Lembra da obs.\n\n") : 0;
    } while(verificarData(data1, data2));


    printf("Distancia entre datas: %d dias\n", calcularDias(data1, data2));
}