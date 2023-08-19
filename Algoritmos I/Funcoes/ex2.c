#include<stdio.h>
#include<stdlib.h>

int soma(int a, int b){
    int i, soma = 0;
    for(i = a; i <= b; i++){
        soma += i;
    }
    return soma;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    func(a, b);
    printf("%d\n", soma(a, b));
    return 0;
}