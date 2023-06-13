#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void changeFrase(char str[]){
    int cont = 0, i, j;
    char vogais[] = "AEIOUaeiou";

    for(i = 0; i < strlen(str); i++){
        for(j = 0; j < strlen(vogais); j++){
            if(str[i] == vogais[j]){
                str[i] = '*';
            }
        }
    }
}

int main(){
    char str[41];

    do {
        printf("Digite a frase: ");
        gets(str);
    } while(strlen(str) > 40);
    
    printf("Frase: %s\n", str);
    changeFrase(str);
    printf("Frase diferenciada: %s\n", str);

    return 0;
}
