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

void load_pregame(game_t *game)
{
    sfVideoMode mode = {1560, 920, 32};

    game->window = sfRenderWindow_create(mode,
        "my_defender", sfResize | sfClose, NULL);
    game->menu->is_in = sfTrue;
    game->menu->button = malloc(sizeof(bt_t));
    game->menu->button2 = malloc(sizeof(bt_t));
    game->menu->button3 = malloc(sizeof(bt_t));
    game->menu->background = bg_create();
    game->menu->text = sfText_create();
    game->menu->font = sfFont_createFromFile("./ressources/GAME_glm.ttf");
    sfText_setString(game->menu->text, "MY DEFENDER");
    sfText_setFont(game->menu->text, game->menu->font);
    sfText_setCharacterSize(game->menu->text, 150);
    sfText_setPosition(game->menu->text, (sfVector2f) {100, 60});
    sfText_setColor(game->menu->text, sfBlack);
    game->level = init_level();
    game->pause = init_pause();
}

void run_game(game_t *game)
{
    set_buttons(game);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            process_event(game);
        locate_player(game);
    }
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->menu = malloc(sizeof(menus_t));
    game->pause = malloc(sizeof(menus_t));
    game->level = malloc(sizeof(lvl_t));

    load_pregame(game);
    run_game(game);
}
