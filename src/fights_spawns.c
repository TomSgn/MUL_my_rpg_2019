/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fights_spawns
*/

#include "rpg.h"

void chance_fight_spawn(rpg_t *rpg)
{
    int random = generate_random(1, 50);

    if (random == 1)
        rpg->status = 4;
}

void fights_spawns(rpg_t *rpg, game_obj_t *obj)
{
    sfVector2i pos = {((obj->rect.left) + 480 - 16) * 2,
    ((obj->rect.top) + 270 - 16) * 2};

    // pos.x *= 2;
    // pos.y *= 2;
    pos.x /= 32;
    pos.y /= 32;
    if (rpg->map[pos.y][pos.x] == 2) {
        if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyD)
        || sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS))
            chance_fight_spawn(rpg);
    }
}