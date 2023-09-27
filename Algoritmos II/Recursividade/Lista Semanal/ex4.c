#include <stdio.h>

int tetranacci(int n){
    if(n == 1 || n == 2 || n == 3)
        return 0;
    else if(n == 4)
        return 1;
    return tetranacci(n-4) + tetranacci(n-3) + tetranacci(n-2) + tetranacci(n-1);
}

int main(){
    printf("%d\n", tetranacci(12));
    return 0;
}