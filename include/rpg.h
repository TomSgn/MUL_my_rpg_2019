/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include "richard.h"

typedef struct player_s
{
    sfSprite *sprt;
    sfTexture *txt;
    sfVector2f pos;
    char direct;
    int life;
}player_t;

typedef struct rpg_s
{
    sfRenderWindow *win;
    sfEvent evnt;

    game_obj_R_t *menu;
    text_R_t *text;
    clock_R_t *clock;
    int menu_status;
    int fps;
    int music_volume;
    int sound_volume;

    sfSprite *cop;

    sfSprite *delete_me;
    sfTexture *delete_me_too;

    // sfClock *clock;
    // sfTime time;
    // float sec;

    player_t player;

    int status;
}rpg_t;

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

//graphic
void clic_status_zero(sfMouseButtonEvent event, sfVector2i mouse, rpg_t *rpg);
void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg);
void draw_options(rpg_t *rpg, sfRenderWindow *win);
void draw_menu(rpg_t *rpg, sfRenderWindow *win);
int main_rpg(void);
void global_event(rpg_t *rpg);
void draw_statue(rpg_t *rpg, sfRenderWindow *win);
void clock_event(rpg_t *rpg, clock_s clock);

//lib
int my_strlen(char const *str);
int my_putstr(char const *str);

//menu
void set_menu_sprites(rpg_t *rpg);
void menu_destroy(rpg_t *rpg);
void click_menu(rpg_t *rpg, sfVector2i mouse);
char *int_to_char(int nb);
game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);
void make_text(text_R_t *text, char *str, char *file);
void set2(rpg_t *rpg, char **name);
void initialize_text(rpg_t *rpg, char **name);
void check_mouse_pos_menu(rpg_t *rpg);
void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse);

#endif /* !RPG_H_ */
