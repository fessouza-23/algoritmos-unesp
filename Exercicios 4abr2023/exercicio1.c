#include <stdio.h>
#include <stdlib.h>

void main(){
	float valor1, valor2, resultSoma, resultMedia;
	printf("Digite valor 1: ");
	scanf("%f", &valor1);
	printf("Digite valor 2: ");
	scanf("%f", &valor2);
	
	 // Soma
	 resultSoma = valor1 + valor2;
	 // Média
	 resultMedia = (valor1 + valor2)/2;
	 
	 printf("\nValor da media aritmetica de %.2f e %.2f eh %.2f", valor1, valor2, resultMedia);
}