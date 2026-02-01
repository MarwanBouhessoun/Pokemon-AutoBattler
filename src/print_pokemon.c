/*
** POKEMON_auto PROJECT, 2026
** print_pokemon
** File description:
** print_pokemon
*/

#include <stdio.h>
#include <stdlib.h>
#include "pokestruct.h"
#include "pokemon.h"

static int get_generation(int ac, char **av)
{
    if (ac == 3)
        return atoi(av[2]);
    return 0;
}

static void print_pokemon_gen(int first, int end, poke_t *pokemons)
{
    for (int i = first; i < end; i++)
        printf("%s\n", pokemons[i].name);
}

static void print_per_gen(int generation, poke_t *pokemons)
{
    switch (generation) {
        case 1:
            print_pokemon_gen(0, 151, pokemons);
            break;
        case 2:
            print_pokemon_gen(151, 251, pokemons);
            break;
        case 3:
            print_pokemon_gen(251, 386, pokemons);
            break;
        case 4:
            print_pokemon_gen(386, 493, pokemons);
            break;
        case 5:
            print_pokemon_gen(493, 649, pokemons);
            break;
        case 6:
            print_pokemon_gen(649, 721, pokemons);
            break;
        case 7:
            print_pokemon_gen(721, 809, pokemons);
            break;
        case 8:
            print_pokemon_gen(809, 905, pokemons);
            break;
        case 9:
            print_pokemon_gen(905, 1025, pokemons);
            break;
    }
}

void print_pokemon(int ac, char **av)
{
    poke_t *pokemons = init_pokemons();
    int generation = get_generation(ac, av);

    printf("See all actual pokemon :\n\n");
    if (generation == 0)
        for (int i = 0; pokemons[i].name != NULL; i++)
            printf("%s\n", pokemons[i].name);
    else
        print_per_gen(generation, pokemons);
    free_pokemons(pokemons);
}
