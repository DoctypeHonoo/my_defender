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

bt_t *init_button(sfVector2f pos, sfVector2f size, char *buf)
{
    bt_t *button = malloc(sizeof(bt_t));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, (sfColor) {0, 0, 0, 0});
    create_text(button, buf);
    return button;
}

void create_text(bt_t *button, char *buf)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);

    button->text = sfText_create();
    button->font = sfFont_createFromFile("./ressources/GAME_glm.ttf");
    sfText_setString(button->text, buf);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 70);
    sfText_setPosition(button->text, (sfVector2f) {pos.x + 10, pos.y} );
    sfText_setColor(button->text, sfBlack);
}

int button_is_clicked(bt_t *button, sfVector2f click_pos)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);

    if (click_pos.x >= pos.x && click_pos.x <= (pos.x + size.x) &&
    click_pos.y >= pos.y && click_pos.y <= (pos.y + size.y)) {
        if (sfMouse_isButtonPressed(0))
            return 1;
    }
    return 0;
}
