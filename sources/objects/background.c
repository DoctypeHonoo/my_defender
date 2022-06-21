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

bg_t *bg_create(void)
{
    bg_t *bg = malloc(sizeof(bg_t));

    bg->texture = sfTexture_createFromFile("./ressources/bg.jpg", NULL);
    bg->sprite = sfSprite_create();
    bg->position = (sfVector2f) {0, 10};
    bg->music = sfMusic_createFromFile("./ressources/theme.ogg");
    sfMusic_setVolume(bg->music, 100.0f);
    sfMusic_setLoop(bg->music, sfTrue);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    return bg;
}

bg_t *bg_pause_init(void)
{
    bg_t *bg_p = malloc(sizeof(bg_t));

    bg_p->texture = sfTexture_createFromFile("./ressources/pause.jpg", NULL);
    bg_p->sprite = sfSprite_create();
    bg_p->position = (sfVector2f) {0, 10};
    sfSprite_setTexture(bg_p->sprite, bg_p->texture, sfTrue);
    return bg_p;
}
