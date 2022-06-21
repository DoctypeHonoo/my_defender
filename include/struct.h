/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef struct_h_

typedef struct button_s {
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    void (* callback)(void);
} bt_t;

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfMusic *music;
} bg_t;

typedef struct mob_s {
    sfTexture *texture;
    sfClock *clock;
    sfClock *anim;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f pos;
} mob_t;

typedef struct level_s {
    mob_t *mob;
    bg_t *scene_bg;
    sfBool is_in;
} lvl_t;

typedef struct menu_s {
    bt_t *button, *button2, *button3;
    sfText *text;
    sfFont *font;
    bg_t *background;
    sfBool is_in;
} menus_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    menus_t *menu;
    menus_t *pause;
    lvl_t *level;
} game_t;

int button_is_clicked(bt_t *button, sfVector2f click_pos);
void mob_running(sfRenderWindow *window, mob_t *mob);
void locate_player(game_t *game);
void anime_mob(sfRenderWindow *window, mob_t *mob);
void init_mob_clock(float seconds, mob_t *mob);
void create_text(bt_t *button, char *buf);
void run_mob(float seconds, mob_t *mob);
void process_event(game_t *game);
void in_game(game_t *game);
void in_pause(game_t *game);
void in_menu(game_t *game);
void destroy_level(lvl_t *level);
void destroy_menus(menus_t *menu);
void set_buttons(game_t *game);
void call_pause(game_t *game);
void draw_menus(game_t *game);
void run_level(game_t *game);
void *print_hello(void);
bg_t *bg_create(void);
menus_t *init_pause(void);
mob_t *create_mob(void);
lvl_t *init_level(void);
bg_t *scene_create(void);
bg_t *bg_pause_init(void);
bt_t *init_button(sfVector2f pos, sfVector2f size, char *buf);

#endif /* !struct_h_ */
