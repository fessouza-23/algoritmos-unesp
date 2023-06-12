#include <stdio.h>

int main(){
    int n, i, cont;
    
    do{
        printf("Digite a quantidade de elementos: obs[max=30]\n");
        scanf("%d", &n);
    } while(n < 1 || n > 30);

    float A[n], B[n];

    for(i = 0; i < n; i++){
        printf("A[%d] = ", i+1);
        scanf("%f", &A[i]);
    }

    for(i = 1, cont = 0; i <= n; i++, cont++){
        if(i % 2){
            B[cont] = A[cont] * 3;
        } else{
            B[cont] = A[cont] / 2;
        }
    }

    for(i = 0; i < n; i++){
        printf("%.1f ", B[i]);
    }

    return 0;
}