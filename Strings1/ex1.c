#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int quantVog(char str[]){
    int cont = 0, i;

    for(i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            cont++;
        }
    }

    return cont;
}

int quantCons(char str[]){
    int cont = 0, i;

    for(i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] >= 'b' && str[i] <= 'z'){
            cont++;
        }
    }

    return cont;
}

int main(){
    char str[41];

    do {
        printf("Digite a frase: ");
        gets(str);
    } while(strlen(str) > 40);
    
    printf("Frase: %s\n", str);
    printf("Quantida de vogais: %d\n", quantVog(str));
    printf("Quantida de consoantes: %d\n", quantCons(str));

    return 0;
}
