#include <stdio.h>
#define lin 10
#define col 10

int main(){
    int i, j;
    int matriz[lin][col];
    
    for (i = 0; i < lin; i++)
        for (j = 0; j < col; j++)
            matriz[i][j] = i * j;
    
    for (i = 0; i < lin; i++){
        for (j = 0; j < col; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}