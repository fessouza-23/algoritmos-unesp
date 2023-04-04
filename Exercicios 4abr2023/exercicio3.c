#include <stdio.h>
#include <stdlib.h>

void main(){
	float peso, altura, imc;
	printf("Peso: ");
	scanf("%f", &peso);
	
	printf("Altura (em metros): ");
	scanf("%f", &altura);
	
	imc = peso/(altura*altura);
	printf("IMC: %f", imc);
}