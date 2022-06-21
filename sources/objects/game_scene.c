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

bg_t *scene_create(void)
{
    bg_t *scene_bg = malloc(sizeof(bg_t));

    scene_bg->texture = sfTexture_createFromFile("./ressources/bg_scene.png",
        NULL);
    scene_bg->sprite = sfSprite_create();
    scene_bg->position = (sfVector2f) {0, 10};
    scene_bg->music = sfMusic_createFromFile("./ressources/theme.ogg");
    sfSprite_setTexture(scene_bg->sprite, scene_bg->texture, sfTrue);
    sfMusic_setVolume(scene_bg->music, 100.0f);
    sfMusic_setLoop(scene_bg->music, sfTrue);
    return scene_bg;
}
