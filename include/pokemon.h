/*
** POKEMON_auto PROJECT, 2026
** pokemon
** File description:
** pokefight
*/

#ifndef POKEMON_H
    #define POKEMON_H
    #include "pokestruct.h"

int check_pokemon(char *name);
void print_pokemon(int ac, char **av);
poke_t *init_pokemons(void);
void poke_battle(poke_t *pokemons, char *poke_user);
char *get_name_lower(char *name);
void free_pokemons(poke_t *pokemons);
#endif
