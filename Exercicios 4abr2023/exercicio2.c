#include <stdio.h>
#include <stdlib.h>

void main(){
	int valor, valorQuadrado;
	
	printf("Digite o valor: ");
	scanf("%d", &valor);
	
	valorQuadrado = valor*valor;
	
	printf("\nValor ao quadrado de %d eh %d", valor, valorQuadrado);
}