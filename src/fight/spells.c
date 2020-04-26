/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spells
*/

#include "rpg.h"

//0 ne bouge pas, 1 monte, 3 à droite, 5 descends, 7 à gauche

// void pos_rotat(sfVector2f *pos, sfVector2f player_pos, int rad, sfSprite *sprt)
// {
//     if (rad == 90) {
//         pos->y = player_pos.y + 300;
//         pos->x = player_pos.x;
//         sfSprite_setRotation(sprt, rad);
//     } else if (rad == 270) {
//         pos->y = player_pos.y - 300;
//         pos->x = player_pos.x;
//         sfSprite_setRotation(sprt, rad);
//     } else if (rad == 0) {
//         pos->y = player_pos.y;
//         pos->x = player_pos.x + 300;
//         sfSprite_setRotation(sprt, rad);
//     } else if (rad == 180) {
//         pos->y = player_pos.y;
//         pos->x = player_pos.x - 300;
//         sfSprite_setRotation(sprt, rad);
//     }
// }

// void fireball(fight_t *fight, sfVector2f player_pos)
// {
//     sfVector2f final_pos = {0, 0};
//     WEAPONS current = fight->player.weapon;

//     if (current == SHOVEL)
//       return;
//     if (current > SPELL_THREE)
//       current = SPELL_ONE;
//     if (fight->spell[current - 1].activated == 0 && current != SPELL_TWO) {
//         if (fight->player.direct == 0 || fight->player.direct == 5) {
//           pos_rotat(&final_pos, player_pos, 90, fight->spell[current - 1].sprite);
//         } else if (fight->player.direct == 1) {
//           pos_rotat(&final_pos, player_pos, 270, fight->spell[current - 1].sprite);
//         } else if (fight->player.direct == 3) {
//             pos_rotat(&final_pos, player_pos, 0, fight->spell[current - 1].sprite);
//         } else if (fight->player.direct == 7) {
//             pos_rotat(&final_pos, player_pos, 180, fight->spell[current - 1].sprite);
//         }
//         fight->spell[current - 1].pos = player_pos;
//         fight->spell[current - 1].direction = fight->player.direct;
//         sfSprite_setPosition(fight->spell[current - 1].sprite, fight->spell[current - 1].pos);
//         fight->spell[current - 1].final_pos = final_pos;
//         fight->spell[current - 1].activated = 1;
//     }
//     if (fight->spell[current - 1].activated == 0 && current == SPELL_TWO) {
//         fight->spell[current - 1].pos.x = player_pos.x + 50;
//         fight->spell[current - 1].pos.x = player_pos.y + 50;
//         sfSprite_setPosition(fight->spell[current - 1].sprite, fight->spell[current - 1].pos);
//         fight->spell[current - 1].final_pos = final_pos;
//         fight->spell[current - 1].activated = 1;
//     }
//     // printf("3\n");
// }

spell_t init_spell(char *path, spells_names_t type)
{
    spell_t spell;
    static int heigth = 31;

    spell.sprite = sfSprite_create();
    spell.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(spell.sprite, spell.texture, sfTrue);
    sfSprite_setPosition(spell.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(spell.sprite, (sfVector2f) {1, 1});
    sfSprite_setTextureRect(spell.sprite, (sfIntRect) {0, 0, 56, heigth});
    heigth = (heigth == 31) ? 42 : 49;
    sfSprite_setOrigin(spell.sprite, (sfVector2f) {28, 15.5});
    spell.velocity = 0.5;
    spell.clock = sfClock_create();
    spell.clock_cd.clock = sfClock_create();
    spell.type = type;
    if (type == FIREBALL) {
        spell.damage = 2;
        spell.protection = 0;
        spell.sec = 0.5;
    } else if (type == SHIELD) {
        spell.protection = 10;
        spell.damage = 10;
        sfSprite_setOrigin(spell.sprite, (sfVector2f) {18, heigth / 2});
        sfSprite_setScale(spell.sprite, (sfVector2f) {1.7, 1.7});
        spell.sec = 5;
    }
    if (type == BLACK_HOLE) {
        spell.damage = 15;
        spell.protection = 0;
        spell.sec = 10;
    }
    spell.activated = 0;
    return (spell);
}