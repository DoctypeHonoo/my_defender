/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "struct.h"

void continue_first_way(mob_t *mob);

void move_mob(mob_t *mob, int way, int distance)
{
    if (way == 0) {
        while (mob->pos.x != distance) {
            mob->pos.x -= 5;
            sfSprite_setPosition(mob->sprite, mob->pos);
            sfClock_restart(mob->clock);
        }
    }
    if (way == 1) {
        while (mob->pos.y != distance) {
            mob->pos.y += 5;
            sfSprite_setPosition(mob->sprite, mob->pos);
            sfClock_restart(mob->clock);
        }
    }
    if (way == 2) {
        while (mob->pos.y != distance) {
            mob->pos.y -= 5;
            sfSprite_setPosition(mob->sprite, mob->pos);
            sfClock_restart(mob->clock);
        }
    }
}

void first_path(mob_t *mob)
{
    move_mob(mob, 0, 1230);
    move_mob(mob, 1, 520);
    move_mob(mob, 0, 800);
}

void use_first_way(mob_t *mob)
{
    if (mob->pos.x == 1230) {
        mob->pos.x += 5;
        mob->pos.y += 5;
        if (mob->pos.y >= 520) {
            mob->pos.y -= 5;
            if (mob->pos.y == 520) {
                continue_first_way(mob);
                sfSprite_setPosition(mob->sprite, mob->pos);
                sfClock_restart(mob->clock);
            }
            sfSprite_setPosition(mob->sprite, mob->pos);
            sfClock_restart(mob->clock);
        }
        sfSprite_setPosition(mob->sprite, mob->pos);
        sfClock_restart(mob->clock);
    }
}

void continue_first_way(mob_t *mob)
{
    if (mob->pos.x <= 800) {
        mob->pos.x += 5;
        if (mob->pos.y <= 20) {
            mob->pos.y -= 5;
            sfSprite_setPosition(mob->sprite, mob->pos);
            sfClock_restart(mob->clock);
        }
        sfSprite_setPosition(mob->sprite, mob->pos);
        sfClock_restart(mob->clock);
    }
}

void run_mob(float seconds, mob_t *mob)
{
    if (seconds > 0.01 && mob->pos.x >= 800)
        first_path(mob);
    if (seconds > 0.01 && mob->pos.x >= 1230) {
        mob->pos.x -= 5;
        use_first_way(mob);
        sfSprite_setPosition(mob->sprite, mob->pos);
        sfClock_restart(mob->clock);
    }
    if (mob->pos.x <= -240) {
        mob->pos.x = 1560;
        mob->pos.y = 200;
        sfSprite_setPosition(mob->sprite, mob->pos);
    }
}
