#include <stdio.h>

int main(){
    float vol, raio, pi = 3.14;
    for(raio = 0; raio <= 20; raio += 0.5){
        vol = 0;
        vol = (4./3.)*pi*(raio*raio*raio);
        printf("Volume da esfera de %.1f de raio eh: %.2f\n", raio, vol);
    }
    return 0;
}