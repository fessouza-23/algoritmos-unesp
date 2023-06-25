#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POKEMONS 151
#define MAX_NAME_LENGTH 1001

int main() {
    int count, i, totalPokemons = MAX_POKEMONS;
    char pokemon[MAX_POKEMONS][MAX_NAME_LENGTH];
    int captured[MAX_POKEMONS] = {0}; // Vetor de flags para marcar Pokémon já capturados

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++) {
        fgets(pokemon[i], MAX_NAME_LENGTH, stdin);
        pokemon[i][strlen(pokemon[i]) - 1] = '\0';

        int index = atoi(pokemon[i]) - 1; // Índice do Pokémon atual

        if (index >= 0 && index < MAX_POKEMONS) {
            if (captured[index] == 0) {
                captured[index] = 1; // Marcar o Pokémon como capturado
                totalPokemons--;
            }
        }
    }

    printf("Falta(m) %d pomekon(s).\n", totalPokemons);

    return 0;
}
