#include <stdio.h>

int main(){
    float i, j, fat, s = 1, sinal = -1, x, n;
    scanf("%f %f", &x, &n);
    for(i = 2; i <= n; i+=2){
        fat = 1;
        for(j = 1; j <= i; j++){
            fat *= j;
        }
        s += sinal*(pow(x, i)/fat);
        sinal = -sinal;
    }
    printf("%.2f\ncos(x): %.2f\n", s, cos(x));
    return 0;
}