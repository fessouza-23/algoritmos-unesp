#include <stdio.h>

int main() {
    int n, i, j, a, b, c, d;
    
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    
    printf("Termos da sequencia de Farey relativos a %d:\n", n);
    printf("0/1, ");
    
    a = 0;
    b = 1;
    c = 1;
    d = n;
    
    while (c <= n) {
        int k = (n + b) / d;
        int temp_a = a;
        int temp_b = b;
        
        a = c;
        b = d;
        c = k * c - temp_a;
        d = k * d - temp_b;
        
        printf("%d/%d, ", a, b);
    }
    
    printf("1/1\n");
    
    return 0;
}
