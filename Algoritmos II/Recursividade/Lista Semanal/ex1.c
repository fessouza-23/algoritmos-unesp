#include <stdio.h>
#include <math.h>

int soma_cubos_rec(int n){
    if (n == 1) 
        return 1;
    return pow(n, 3) + soma_cubos_rec(n - 1);
}

int main() {
    printf("%d\n", soma_cubos_rec(5));
    return 0;
}