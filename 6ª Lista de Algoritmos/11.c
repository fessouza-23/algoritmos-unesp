#include <stdio.h>

int main(){
    float i, sinal = 1, s = 0, j, fat, n, x, cont;
    scanf("%f %f", &x, &n);
    for(i = 1, cont = 1; i <= n; i++, cont += 2){
        fat = 1;
        for(j = 1; j <= cont; j++){
            fat *= j;
        }
        s += sinal*(pow(x, cont)/fat);
        sinal = -sinal;
    }
    printf("%.2f\nsen(x): %.2f\n", s, sin(x));
}