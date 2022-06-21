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

mob_t *create_mob(void)
{
    mob_t *mob = malloc(sizeof(mob_t));

    mob->texture = sfTexture_createFromFile("./ressources/g.png", NULL);
    mob->clock = sfClock_create();
    mob->anim = sfClock_create();
    mob->sprite = sfSprite_create();
    mob->pos = (sfVector2f) {1560, 200};
    mob->rect = (sfIntRect) {0, 0, 60, 80};

    sfSprite_setPosition(mob->sprite, mob->pos);
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->rect);
    return mob;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void init_mob_clock(float seconds, mob_t *mob)
{
    if (seconds > 0.09) {
        move_rect(&(mob->rect), 60, 240);
        sfClock_restart(mob->anim);
    }
}

void anime_mob(sfRenderWindow *window, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->anim);
    float seconds = time.microseconds / 1000000.0;
    sfSprite_setTextureRect(mob->sprite, mob->rect);

    init_mob_clock(seconds, mob);
    sfRenderWindow_drawSprite(window, mob->sprite, NULL);
}

void mob_running(sfRenderWindow *window, mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    float seconds = time.microseconds / 1000000.0;

    run_mob(seconds, mob);
    sfRenderWindow_drawSprite(window, mob->sprite, NULL);
}