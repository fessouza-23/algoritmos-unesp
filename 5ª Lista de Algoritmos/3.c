#include <stdio.h>

int main(){
    int num1, num2, aux, i, soma = 0, mult = 1;
    do {
        printf("Digite dois numeros inteiros positivos: ");
        scanf("%d %d", &num1, &num2);
    } while(num1 < 1 && num2 < 1);
    if(num1 > num2){
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
    for(i = num1; i <= num2; i++){
        if(i % 2){
            soma += i;
        } else {
            mult *= i;
        }
    }
    printf("Soma dos numeros impares: %d\n", soma);
    printf("Multiplicacao dos numeros pares: %d\n", mult);
    return 0;
}