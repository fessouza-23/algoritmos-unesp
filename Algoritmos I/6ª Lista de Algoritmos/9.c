#include <stdio.h>
#include <math.h>

int main(){
    float i, fat, j, x, n, s = 0;
    scanf("%f %f", &x, &n);
    for(i = 0; i <= n; i++){
        fat = 1;
        for(j = 1; j <= i; j++){
            fat *= j;
        }
        s += pow(x, i)/fat;
    }
    printf("%.2f\nexp: %.2f\n", s, exp(x));
}