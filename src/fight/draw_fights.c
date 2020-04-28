/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** draw_fights
*/

#include "rpg.h"

void display_rect(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    sfRectangleShape_setPosition(fight->inventory.show,
    (sfVector2f) {((fight->player.weapon - 1) * 110) + 603, 935});
    sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
}

void display_enns(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 0; i < fight->nb_enn && rpg->status != 10; i++)
        if (fight->enns[i].in_live) {
            if (fight->enns[i].life < 100) {
                sfRenderWindow_drawSprite(win, fight->enns[i].buttons[0].sprite, NULL);
                sfRenderWindow_drawSprite(win, fight->enns[i].buttons[1].sprite, NULL);
            }
            sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
        }   
}

void display_spells(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 0; i < 10; i++)
        if (fight->spell[i].activated == 1)
            sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
}

void display_cooldown(fight_t *fight, sfRenderWindow *win)
{
    // sfText_setString(fight->spell[0].text.text, "0");
    if (fight->spell[0].text.str)
        sfRenderWindow_drawText(win, fight->spell[0].text.text, NULL);
    if (fight->spell[1].text.str)
        sfRenderWindow_drawText(win, fight->spell[1].text.text, NULL);
    if (fight->spell[2].text.str)
        sfRenderWindow_drawText(win, fight->spell[2].text.text, NULL);
    if (fight->spell[3].text.str)
        sfRenderWindow_drawText(win, fight->spell[3].text.text, NULL);
    if (fight->spell[4].text.str)
        sfRenderWindow_drawText(win, fight->spell[4].text.text, NULL);
    // if (fight->spell[0].text.str != NULL) {
    //     printf("draw\n");
    //     printf("|||%s|||\n", fight->spell[0].text.str);
    //     sfRenderWindow_drawText(win, fight->spell[0].text.text, NULL);
    // } else {
    //     printf("not drawh\n");
    // }
}

void draw_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win, sfBlack);
    // sfRectangleShape_setPosition(fight->inventory.show,
    // (sfVector2f) {((fight->player.weapon - 1) * 110) + 603, 935});
    sfRenderWindow_drawSprite(win, fight->buttons[4].sprite, NULL);
    if (rpg->status == 10)
        sfRenderWindow_drawSprite(win, fight->buttons[9].sprite, NULL);
    display_enns(fight, win, rpg);
    // for (int i = 0; i < fight->nb_enn && rpg->status != 10; i++)
    //     if (fight->enns[i].in_live) {
    //         if (fight->enns[i].life < 100) {
    //             sfRenderWindow_drawSprite(win, fight->enns[i].buttons[0].sprite, NULL);
    //             sfRenderWindow_drawSprite(win, fight->enns[i].buttons[1].sprite, NULL);
    //         }
    //         sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
    //     }
    sfRenderWindow_drawSprite(win, fight->player.player, NULL);
    display_spells(fight, win, rpg);
    // for (int i = 0; i < 3; i++)
    //     if (fight->spell[i].activated == 1)
    //         sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[3].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->inventory.sprite, NULL);
    // sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
    display_rect(fight, win, rpg);
    sfRenderWindow_drawSprite(win, fight->buttons[5].sprite, NULL);
    display_cooldown(fight, win);
    for (int i = 6; i <= 8; i += 1)
        sfRenderWindow_drawSprite(win, fight->buttons[i].sprite, NULL);
    for (int i = 10; i <= 11; i += 1)
        sfRenderWindow_drawSprite(win, fight->buttons[i].sprite, NULL);
    sfRenderWindow_display(win);
}
