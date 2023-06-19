#include <stdio.h>

int main() {
    int n, i, j;
    
    do {
        scanf("%d", &n);
        
        if (n == 0)
            break;
        
        int v[n][n];
        v[0][0] = 1;
        
        for (i = 0; i < n; i++) {
            if (i > 0){
                v[i][0] = v[i-1][1];
            }
                
            for (j = 1; j < n; j++) {
                v[i][j] = v[i][j-1] * 2;
            }
        }

        for (i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                printf("%3d", v[i][j]);
            printf("\n");
        }

        printf("\n");
    } while (1);
    
    return 0;
}
