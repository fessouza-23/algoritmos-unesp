#include<stdio.h>

int func(int a, int b, int c){
    int i, soma = 0;
    for(i = b; i <= c; i++){
        if(i % a == 0){
            soma += i;
        }
    }
    return soma;
}

int main(){
    int a, b, c;

    do{
        printf("Digite tres numeros inteiros: ");
        scanf("%d %d %d", &a, &b, &c);
    } while(a <= 0 && b <= 0 && c <= 0);

    printf("Soma =t %d\n", func(a, b, c));

    return 0;
}