#include <stdio.h>
#include <stdlib.h>
#define max 100

int main(){
    int v[max], i;
    for (i = 0; i < max; i++){
        v[i] = 10;
    }
    for (i = 0; i < max; i++){
        printf("%d ", v[i]);
    }
    
    return 0;
}