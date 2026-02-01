/*
** POKEMON_auto PROJECT, 2026
** POKEMON
** File description:
** POKEMON
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"
#include "pokestruct.h"
#include "macro.h"

static int error_handling(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        printf("too much or less args, you can choose only one pokemon\n");
        return ERROR;
    }
    if (ac == 3 && strcmp(av[1], "-p") != 0) {
        printf("Use -p for see all pokemon usable. Choose only one pokemon\n");
        return ERROR;
    }
    if (strcmp(av[1], "-p") == 0) {
        print_pokemon(ac, av);
        return ERROR;
    }
    if (check_pokemon(av[1]) == ERROR) {
        printf("Try an existed Pokemon. See theme with '-p'\n");
        return ERROR;
    }
    return EXIT;
}

int main(int ac, char **av)
{
    poke_t *pokemons = NULL;
    char *poke_user;

    srand(time(NULL));
    if (error_handling(ac, av) == ERROR)
        return ERROR;
    pokemons = init_pokemons();
    poke_user = strdup(av[1]);
    poke_battle(pokemons, poke_user);
    free_pokemons(pokemons);
    free(poke_user);
    return EXIT;
}