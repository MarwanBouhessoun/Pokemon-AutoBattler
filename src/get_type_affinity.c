/*
** EPITECH PROJECT, 2026
** get_type_affinity
** File description:
** type affinity
*/

#include <stdio.h>
#include <string.h>
#include "pokestruct.h"

static int get_type_id(char *type_str)
{
    if (type_str == NULL)
        return NORMAL;
    if (strcmp(type_str, "normal") == 0) return NORMAL;
    if (strcmp(type_str, "fire") == 0) return FIRE;
    if (strcmp(type_str, "water") == 0) return WATER;
    if (strcmp(type_str, "grass") == 0) return GRASS;
    if (strcmp(type_str, "electric") == 0) return ELECTRIC;
    if (strcmp(type_str, "ice") == 0) return ICE;
    if (strcmp(type_str, "fighting") == 0) return FIGHTING;
    if (strcmp(type_str, "poison") == 0) return POISON;
    if (strcmp(type_str, "ground") == 0) return GROUND;
    if (strcmp(type_str, "flying") == 0) return FLYING;
    if (strcmp(type_str, "psychic") == 0) return PSYCHIC;
    if (strcmp(type_str, "bug") == 0) return BUG;
    if (strcmp(type_str, "rock") == 0) return ROCK;
    if (strcmp(type_str, "ghost") == 0) return GHOST;
    if (strcmp(type_str, "dragon") == 0) return DRAGON;
    if (strcmp(type_str, "steel") == 0) return STEEL;
    if (strcmp(type_str, "dark") == 0) return DARK;
    if (strcmp(type_str, "fairy") == 0) return FAIRY;
    return NORMAL;
}

float get_type_affinity(char *atk_type, char *def_type)
{
    float type_table[18][18] = {
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
            0.0, 1.0, 0.5, 1.0, 1.0},
        {1.0, 0.5, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
            1.0, 0.5, 2.0, 1.0, 1.0},
        {1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
            1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0,
            1.0, 0.5, 0.5, 1.0, 1.0},
        {1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0,
            1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 0.5, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0,
            1.0, 2.0, 0.5, 1.0, 1.0},
        {2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
            0.0, 1.0, 2.0, 2.0, 0.5},
        {1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5,
            0.5, 1.0, 0.0, 1.0, 2.0},
        {1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0,
            1.0, 1.0, 2.0, 1.0, 1.0},
        {1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5,
            1.0, 1.0, 0.5, 1.0, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0,
            1.0, 1.0, 0.5, 0.0, 1.0},
        {1.0, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0,
            0.5, 1.0, 0.5, 2.0, 0.5},
        {1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0,
            1.0, 1.0, 0.5, 1.0, 1.0},
        {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
            2.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 2.0, 0.5, 1.0, 0.0},
        {1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0,
            1.0, 1.0, 0.5, 1.0, 2.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
            2.0, 1.0, 1.0, 0.5, 0.5},
        {1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0,
            1.0, 2.0, 0.5, 2.0, 1.0}
    };
    int atk_id = get_type_id(atk_type);
    int def_id = get_type_id(def_type);

    return type_table[atk_id][def_id];
}