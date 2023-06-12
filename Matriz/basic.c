#include <stdio.h>
#define lin 3
#define col 4

int main(){
    int i, j;
    float matriz[lin][col];
    
    for (i = 0; i < lin; i++){
        for (j = 0; j < col; j++){
            printf("elemento matriz[%d][%d]\n", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
    
    for (i = 0; i < lin; i++){
        for (j = 0; j < col; j++)
            printf("%10.2f ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}