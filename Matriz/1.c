#include <stdio.h>
#define lin 10
#define col 10

int main(){
    int i, j, n1, n2;
    float A[lin][col], B[lin][col], C[lin][col];

    printf("Digite o tamanho das matrizes, obs: max[10][10]\n");
    scanf("%d %d", &n1, &n2);
    
    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            printf("elemento da matriz A[%d][%d] = ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }

    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            printf("elemento da matriz B[%d][%d] = ", i+1, j+1);
            scanf("%f", &B[i][j]);
        }
    }

    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++)
            printf("%10.2f + %.2f = %.2f ", A[i][j], B[i][j], C[i][j]);
        printf("\n");
    }

    return 0;
}