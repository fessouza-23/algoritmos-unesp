#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, x, y, aux, a, b, c;
    srand(time(NULL));
    do {
        printf("Digite o intervalo: ");
        scanf("%d %d", &x, &y);
    } while(x < 0 && y < 0 || (y - x) < 2);
    (x > y)? aux = x, x = y, y = aux : 0;
    printf("Gerando numero leatorio entre %d e %d: \n", x, y);
    do {
        a = rand() % (y - x + 1) + x;
        b = rand() % (y - x + 1) + x;
        c = rand() % (y - x + 1) + x;
    } while(a == b | a == c | b == c);
    printf("\t%d\n", a);
    printf("\t%d\n", b);
    printf("\t%d\n", c);
    return 0;
}