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

void set_buttons(game_t *game)
{
    sfVector2f pos = (sfVector2f) {290, 300};
    sfVector2f size = (sfVector2f) {195, 100};
    sfVector2f pos2 = (sfVector2f) {680, 300};
    sfVector2f pos3 = (sfVector2f) {1070, 300};

    game->menu->button = init_button(pos, size, "Quit");
    game->menu->button2 = init_button(pos2, size, "Play");
    game->menu->button3 = init_button(pos3, size, "Help");
    game->pause->button = init_button(pos, size, "Resume");
    game->pause->button2 = init_button(pos2, size, "Home");
    game->pause->button3 = init_button(pos3, size, "Quit");
}

void draw_menus(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu->background->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->menu->text, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->menu->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->menu->button2->rect, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->menu->button3->rect, NULL);
    sfRenderWindow_drawText(game->window, game->menu->button->text, NULL);
    sfRenderWindow_drawText(game->window, game->menu->button2->text, NULL);
    sfRenderWindow_drawText(game->window, game->menu->button3->text, NULL);
    sfRenderWindow_display(game->window);
}

void process_event(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
        destroy_menus(game->menu);
        destroy_level(game->level);
        destroy_menus(game->pause);
        exit(0);
    }
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape) {
        if (game->level->is_in == sfTrue) {
            game->level->is_in = sfFalse;
            game->pause->is_in = sfTrue;
        }
    }
}

void locate_player(game_t *game)
{
    if (game->menu->is_in == sfTrue)
        in_menu(game);
    if (game->level->is_in == sfTrue)
        in_game(game);
    if (game->pause->is_in == sfTrue)
        in_pause(game);
}

void in_pause(game_t *game)
{
    (void) game;
}

void in_game(game_t *game)
{
    sfMusic_play(game->level->scene_bg->music);
    run_level(game);
    sfRenderWindow_display(game->window);
}

void in_menu(game_t *game)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window);

    draw_menus(game);
    if (button_is_clicked(game->menu->button, (sfVector2f) {(int)m.x, (int)m.y})) {
        sfRenderWindow_close(game->window);
        sfMusic_destroy(game->menu->background->music);
        exit(0);
    }
    if (button_is_clicked(game->menu->button2, (sfVector2f) {(int)m.x, (int)m.y})) {
        game->level->is_in = sfTrue;
        game->menu->is_in = sfFalse;
    }
}

void destroy_level(lvl_t *level)
{
    sfTexture_destroy(level->mob->texture);
    sfSprite_destroy(level->mob->sprite);
    sfTexture_destroy(level->scene_bg->texture);
    sfSprite_destroy(level->scene_bg->sprite);
    sfMusic_destroy(level->scene_bg->music);
    free(level->mob);
    free(level->scene_bg);
    free(level);
}

void destroy_menus(menus_t *menu)
{
    sfText_destroy(menu->button->text);
    sfText_destroy(menu->button2->text);
    sfText_destroy(menu->button3->text);
    sfRectangleShape_destroy(menu->button->rect);
    sfRectangleShape_destroy(menu->button2->rect);
    sfRectangleShape_destroy(menu->button3->rect);
    sfMusic_destroy(menu->background->music);
    sfTexture_destroy(menu->background->texture);
    sfSprite_destroy(menu->background->sprite);
}
