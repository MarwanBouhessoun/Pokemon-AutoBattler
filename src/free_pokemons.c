/*
** EPITECH PROJECT, 2026
** free pokemons
** File description:
** free pokemons
*/

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

void free_pokemons(poke_t *pokemons)
{
    if (pokemons == NULL)
        return;
    for (int i = 0; pokemons[i].name != NULL; i++)
        free(pokemons[i].name);
    free(pokemons);
}