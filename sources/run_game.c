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
#include <stdbool.h>
#include "struct.h"

lvl_t *init_level(void)
{
    lvl_t *level = malloc(sizeof(lvl_t));

    level->mob = create_mob();
    level->scene_bg = scene_create();
    return level;
}

void run_level(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->level->scene_bg->sprite,
        NULL);
    anime_mob(game->window, game->level->mob);
    mob_running(game->window, game->level->mob);
}
