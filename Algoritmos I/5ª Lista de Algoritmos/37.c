#include <stdio.h>

int main(){
    float i, cont = 100, j, fat, s = 0;
    for(i = 0; i <= 11; i++, cont--){
        fat = 1;
        for(j = 1; j <= i; j++){
            fat *= j;
        }
        s += cont/fat;
    }
    printf("%.2f\n", s);
    return 0;
}