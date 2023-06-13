#include<stdio.h>

void divisao(int x, int y, int *quo, int *rest){
    *quo = x/y;
    *rest = x%y;
}

int main(){
    int x, y, quo = 0, rest = 0;
    scanf("%d %d", &x, &y);
    divisao(x, y, &quo, &rest);
    printf("Quociente: %d\nResto: %d\n", quo, rest);
    return 0;
}