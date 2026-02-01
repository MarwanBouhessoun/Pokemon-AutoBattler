/*
** POKEMON_auto PROJECT, 2026
** pokebattle
** File description:
** pokebattle
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pokemon.h"
#include "pokestruct.h"

static int len_array(poke_t *pokemons)
{
    int i = 0;

    for (; pokemons[i].name != NULL; i++);
    return i;
}

static void print_health_bar(char *name, int pv_curr, int pv_max)
{
    float percent = (float)pv_curr / pv_max;
    int bar_lenght = 20;
    int completed_lenght = percent * bar_lenght;

    printf("%s -> [", name);
    for (int i = 0; i < bar_lenght; i++)
        printf((i < completed_lenght) ? "#" : " ");
    printf("] %d/%d PV\n", pv_curr, pv_max);
}

static poke_t found_poke_used(poke_t *pokemons, char *poke_user)
{
    char *poke = get_name_lower(poke_user);

    for (int i = 0; pokemons[i].name; i++) {
        if (strcmp(pokemons[i].name, poke_user) == 0) {
            free(poke);
            return pokemons[i];
        }
    }
    free(poke);
    return pokemons[0];
}

static void attack(poke_t *attacker, poke_t *defender)
{
    int damage = 0;
    int total_damage = 0;
    int rand_var = (rand() % 6) - 2;
    int miss = rand() % 100;
    int crit = rand() % 5;
    float multiple = get_type_affinity(attacker->type, defender->type);

    if (miss < 10) {
        printf("%s attacks but... MISSED!!\n", attacker->name);
        return;
    }
    damage = (attacker->atq * 5) / defender->def;
    total_damage = damage + rand_var;
    if (crit == 0) {
        printf("CRITICAL HIT on %s!\n", defender->name);
        total_damage *= 2;
    }
    total_damage *= multiple;
    if (total_damage < 1)
        total_damage = 1;
    defender->pv -= total_damage;
    if (defender->pv < 0)
        defender->pv = 0;
    printf((multiple == 0) ? "It has no effect...\n" : "");
    printf((multiple == 2) ? "Its very effective !!\n" : "");
    printf((multiple == 0.5) ? "Its not very effective...\n" : " \b");
    printf("%s deals %d damage to %s! (%d HP left)\n",
        attacker->name, total_damage, defender->name, defender->pv);
    print_health_bar(defender->name, defender->pv, defender->pv_max);
    sleep(1);
}

static void turn(poke_t *poke1, poke_t *poke2, int turn_count)
{
    poke_t *first = (poke1->spd >= poke2->spd) ? poke1 : poke2;
    poke_t *second = (poke2->spd > poke1->spd) ? poke1 : poke2;

    printf("\n--- Turn n°%d---\n", turn_count);
    attack(first, second);
    if (second->pv <= 0)
        return;
    attack(second, first);
    printf("-----------\n");
}

static void battle(poke_t poke1, poke_t poke2)
{
    int turn_count = 0;

    while (true) {
        if (poke1.pv <= 0 || poke2.pv <= 0) {
            printf((poke1.pv <= 0) ? "you lose...\n" : "YOUR %s WINS\n",
                poke1.name);
            break;
        }
        turn(&poke1, &poke2, turn_count);
        turn_count++;
        sleep(1);
    }
}

void poke_battle(poke_t *pokemons, char *poke_user)
{
    poke_t poke_used = found_poke_used(pokemons, poke_user);
    poke_t poke_rand;
    int idx_poke = rand() % len_array(pokemons);

    if (poke_used.name == NULL)
        return;
    poke_rand = pokemons[idx_poke];
    battle(poke_used, poke_rand);
}