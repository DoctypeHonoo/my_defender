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

menus_t *init_pause(void)
{
    menus_t *pause = malloc(sizeof(menus_t));

    pause->background = bg_pause_init();
    pause->text = sfText_create();
    pause->font = sfFont_createFromFile("./ressources/Outwrite.ttf");
    sfText_setString(pause->text, "Pause");
    sfText_setFont(pause->text, pause->font);
    sfText_setCharacterSize(pause->text, 150);
    sfText_setPosition(pause->text, (sfVector2f) {530, 60});
    sfText_setColor(pause->text, sfBlack);
    return pause;
}

void call_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->pause->background->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->pause->text, NULL);

    sfRenderWindow_drawRectangleShape(game->window, game->pause->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->pause->button2->rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->pause->button3->rect, NULL);
    sfRenderWindow_drawText(game->window, game->pause->button->text, NULL);
    sfRenderWindow_drawText(game->window, game->pause->button2->text, NULL);
    sfRenderWindow_drawText(game->window, game->pause->button3->text, NULL);
}
