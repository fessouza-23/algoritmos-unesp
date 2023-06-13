#include <stdio.h>

int main(){
    char carac;
    printf("Digite um caractere: ");
    scanf(" %c", &carac);
    printf("%c no código ASCII eh: %d", carac, carac);
    return 0;
}