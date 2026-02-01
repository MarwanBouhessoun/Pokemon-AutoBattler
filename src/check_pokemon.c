/*
** POKEMON_auto PROJECT, 2026
** check_pokemon
** File description:
** check_pokemon
*/

#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "pokemon.h"

char *get_name_lower(char *name)
{
    char *safe_name = calloc(sizeof(char), strlen(name) + 1);

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 41 && name[i] <= 90) {
            safe_name[i] = name[i] + 32;
            continue;
        }
        safe_name[i] = name[i];
    }
    return safe_name;
}

int check_pokemon(char *name)
{
    poke_t *pokemons = init_pokemons();
    char *safe_name = get_name_lower(name);

    for (int i = 0; pokemons[i].name != NULL; i++) {
        if (strcmp(safe_name, pokemons[i].name) == 0) {
            free_pokemons(pokemons);
            free(safe_name);
            return EXIT;
        }
    }
    free_pokemons(pokemons);
    free(safe_name);
    return ERROR;
}
