/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

int player_deplacement(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_up(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_down(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_left(&rpg->player);
    else if (sfKeyboard_isKeyPressed(sfKeyD))
        move_right(&rpg->player);
    else {
        dont_move(&rpg->player);
    }
    return (0);
}

void analyse_event(rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->evnt.type == sfEvtClosed || (rpg->evnt.type == sfEvtKeyPressed \
    && rpg->evnt.key.code == sfKeyEscape)) {
        sfRenderWindow_close(rpg->win);
    }
    if (rpg->evnt.type == sfEvtMouseButtonPressed) {
        clics_handlings(rpg->evnt.mouseButton, rpg, obj);
    }
    if (rpg->evnt.type == sfEvtKeyPressed) {
        keys_handlings(rpg->evnt, rpg, obj);
    }
}

void move_x(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.x -= 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x + 1 < 140 && rpg->map[pos.y][pos.x + 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    } else {
        pos.x += 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x > 0 && rpg->map[pos.y][pos.x - 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    }
}

void move_y(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.y -= 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y + 1 < 140 && rpg->map[pos.y + 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    } else {
        pos.y += 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y > 0 && rpg->map[pos.y - 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    }
}

void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg)
{
    sfVector2i pos = {((obj->rect.left) + 480 - 16),
    ((obj->rect.top) + 270 - 16)};

    pos.x *= 2;
    pos.y *= 2;
    //printf("\n\npos x : %d | pos y : %d\nleft = %d, top = %d\n", pos.x, pos.y, obj->rect.left, obj->rect.top);
    if (mouvement.x != 0)
        move_x(pos, obj, rpg, mouvement.x);
    if (mouvement.y != 0)
        move_y(pos, obj, rpg, mouvement.y);
    pos.x /= 32;
    pos.y /= 32;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    rpg->perspec.rect = obj->rect;
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

void global_event(rpg_t *rpg, game_obj_t *background)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg, background);
    }
    if (mouse.x > 20 && mouse.x < 20 && mouse.y > 20 && mouse.y < 120) {
        rpg->menu[18].rect.left = rpg->menu[18].rect.width;
        rpg->fight->buttons[5].rect.left = rpg->fight->buttons[5].rect.width;
    } else {
        rpg->menu[18].rect.left = 0;
        rpg->fight->buttons[5].rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->menu[18].sprite, rpg->menu[18].rect);
    sfSprite_setTextureRect(rpg->fight->buttons[5].sprite, rpg->fight->buttons[5].rect);
    if (rpg->status == 3) {
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            move_rect(background, (sfVector2f) {-5, 0}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_rect(background, (sfVector2f) {5, 0}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            move_rect(background, (sfVector2f) {0, -5}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            move_rect(background, (sfVector2f) {0, 5}, rpg);
        player_deplacement(rpg);
        handling_items(rpg);
    }
    if (rpg->status == 8)
        script_death(rpg, background);
    if (rpg->status == 7)
        tuto(rpg, background);
    if (rpg->status == 0)
        check_mouse_pos_menu(rpg);
}