#include <stdio.h>
#include <stdlib.h>
#define max 30

int main(){
    int T1, T2, i, j, cont, vMin, vMax;
    float A[max], B[max];

    do {
        printf("Digite o tamanho do vetor A: obs[max=30]\n");
        scanf("%d", &T1);

        printf("Digite o tamanho do vetor A: obs[max=30]\n");
        scanf("%d", &T2);
    } while((T1 <= 0 || T1 > 30) && (T1 <= 0 || T2 > 30));

    float C[T1+T2];

    for(i = 0; i < T1; i++){
        printf("A[%d] = ", i+1);
        scanf("%f", &A[i]);
    }

    for(i = 0; i < T2; i++){
        printf("B[%d] = ", i+1);
        scanf("%f", &B[i]);
    }

    if(T1 > T2){
        vMin = T2;
        vMax = T1;
    } else {
        vMin = T1;
        vMax = T2;
    }

    i = 0;
    cont = 0;
    while(i < vMin){
        C[cont] = A[i];
        cont+=2;
        i++;
    }

    i = 0;
    cont = 1;
    while(i < vMax){
        C[cont] = B[i];
        i++;
        cont+=2;
    }

    for (i = 0; i < (T1 + T2); i++) {
        printf("C[%d] = %.1f\n", i+1, C[i]);
    }

    return 0;
}