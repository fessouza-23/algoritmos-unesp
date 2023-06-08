#include <stdio.h>

int main(){
    char carac;
    printf("Digite um caractere: ");
    scanf("%c", &carac);
    printf("Sucessor de %c eh: %c\nAntecessor de %c eh: %c", carac, carac + 1, carac, carac - 1);
    return 0;
}