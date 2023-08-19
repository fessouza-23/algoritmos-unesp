#include <stdio.h>

int main(){
    int i, j, n;
    char resp;

    do{
        do{
            printf("Digite a quantidade de elementos: ");
            scanf("%d", &n);
        }while(n < 1);

        int a[n], b[n], result = 0;

        for(i = 0; i < n; i++){
            printf("A[%d] = ", i+1);
            scanf("%d", &a[i]);
        }

        for(i = 0; i < n; i++){
            printf("B[%d] = ", i+1);
            scanf("%d", &b[i]);
        }

        for(i = 0; i < n; i++){
            result += (a[i] * b[i]);
        }

        printf("Resultado: %d\n", result);

        do{
            printf("Executar novamente? (s/n)\n");
            scanf(" %c", &resp);
        }while(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n');

    }while(resp == 'S' || resp == 's');

    return 0;
}