#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void funcToUpper(char str[]){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = toupper(str[i]);
        }
    }
}

int main(){
    char str[100];
    printf("Digite a frase: ");
    gets(str);

    funcToUpper(str);
    printf("TO UPPER: %s", str);
    return 0;
}