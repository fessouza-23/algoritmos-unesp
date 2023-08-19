#include <stdio.h>

int main(){
    int ano_nasc, ano_atual;
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano_nasc);
    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);
    printf("Idade: %d\n", ano_atual - ano_nasc);
    printf("Idade em semanas: %d\n", (ano_atual - ano_nasc) * 52);
}