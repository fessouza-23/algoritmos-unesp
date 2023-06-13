#include <stdio.h>

int main(){
    int i, j, n, cont = 1, s;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        s = 0;
        for(j = 1; j <= i; j++){
            s += cont;
            cont += 2;
        }
    }
    printf("%d\n", s);
}