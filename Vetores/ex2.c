#include <stdio.h>
#include <stdlib.h>
#define max 5

int main(){
    int i, maior = 0;
    float v[max], soma = 0, md;
    for (i = 0; i < max; i++){
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &v[i]);
        soma += v[i];
        (v[i] > 5)? maior++ : 0;
    }
    md = soma/max;
    printf("Media aritmetica das notas: %.2f\n", md);
    if(maior == 0){
        printf("Nao tem alunos com nota acima de 5\n");
    } else{
        printf("%d notas acima de 5\n", maior);
    }
    return 0;
}