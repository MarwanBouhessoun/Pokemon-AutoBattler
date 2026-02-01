/*
** POKEMON_auto PROJECT, 2026
** init_pokemons
** File description:
** init_pokemons
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokestruct.h"
#include "macro.h"

static int count_line(char *filename)
{
    int line = 0;
    char c;
    FILE *fd = fopen(filename, "r");

    if (fd == NULL)
        return ERROR;
    c = fgetc(fd);
    while (c != -1) {
        if (c == '\n')
            line++;
        c = fgetc(fd);
    }
    line++;
    fclose(fd);
    return line;
}

poke_t *init_pokemons(void)
{
    char *filename = "pokedex.csv";
    int nb_pokemon = count_line(filename);
    poke_t *pokemons = calloc(sizeof(poke_t), nb_pokemon + 1);
    FILE *fd = fopen(filename, "r");
    char buffer[256];
    char buffer_name[256];
    char buffer_type[256];
    int pv, atq, def, spd;
    int i = 0;

    if (nb_pokemon == ERROR || pokemons == NULL) {
        printf("Erreur : Fichier csv vide ou introuvable !\n");
        return NULL;
    }
    if (fd == NULL) {
        free(pokemons);
        return NULL;
    }
    while (fgets(buffer, sizeof(buffer), fd)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (sscanf(buffer, "%[^;];%d;%d;%d;%d;%s", buffer_name,
            &pv, &atq, &def, &spd, buffer_type) == 6) {
                pokemons[i].name = strdup(buffer_name);
                pokemons[i].pv = pv;
                pokemons[i].pv_max = pv;
                pokemons[i].atq = atq;
                pokemons[i].def = def;
                pokemons[i].spd = spd;
                pokemons[i].type = strdup(buffer_type);
                i++;
        }
    }
    fclose(fd);
    return pokemons;
}
