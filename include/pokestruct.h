/*
** POKEMON_auto PROJECT, 2026
** struct
** File description:
** struct
*/

#ifndef POKESTRUCT_H
    #define POKESTRUCT_H

enum TypeID {
    NORMAL = 0,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    STEEL,
    DARK,
    FAIRY
};
typedef struct poke_s {

    char *name;
    char *type;
    int pv;
    int atq;
    int def;
    int spd;
    int pv_max;
}poke_t;

#endif
