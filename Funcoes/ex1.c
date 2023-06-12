#include<stdio.h>

int func(int num){
    if(num > 0){
        return 1;
    } else if(num == 0){
        return 0;
    } else{
        return -1;
    }
}

int main(){
    float num;
    printf("Digite um numero: caso queira parar, 123.123\n");
    do {
        scanf("%f", &num);
        printf("%d\n", func(num));
    } while(1);
    return 0;
}