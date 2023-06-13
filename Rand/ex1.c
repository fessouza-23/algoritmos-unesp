#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, x, y, aux;
    srand(time(NULL));
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);
    (x > y)? aux = x, x = y, y = aux : 0;
    printf("Gerando numero leatorio entre %d e %d: ", x, y);
    printf("\t%d\n", rand() % (y - x + 1) + x);
    return 0;
}