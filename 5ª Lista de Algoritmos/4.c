#include <stdio.h>

int main(){
    int num1, num2, aux, cont, i, soma = 0;
    do {
        printf("Digite dois numeros inteiros positivos: ");
        scanf("%d %d", &num1, &num2);
    } while(num1 < 1 && num2 < 1);
    if(num2 > num1){
        cont = 1;
        for(i = num1; i <= num2; i++){
            soma += i;
            cont++;
        }
        printf("Média do intervalo entre os numeros: %d", soma/cont);
    } else if(num1 > num2){
        aux = num2;
        num2 = num1;
        num1 = aux;
        cont = 1;
        for(i = num1; i <= num2; i++){
            soma += i;
            cont++;
        }
        printf("Média do intervalo entre os numeros: %d", soma/cont);
    }
    return 0;
}