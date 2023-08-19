#include <stdio.h>
#define lin 10
#define col 10

int main(){
    int i, j, n1, n2;
    float m[lin][col], soma = 0;

    printf("Digite o tamanho da matrize, obs: max[10][10]\n");
    scanf("%d %d", &n1, &n2);
    
    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            printf("elemento da matriz m[%d][%d] = ", i+1, j+1);
            scanf("%f", &m[i][j]);
        }
    }

    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            printf("%.2f + ", m[i][j]);
            soma += m[i][j];
        }
    }
    
    printf("0 = %.2f\n", soma);

    return 0;
}