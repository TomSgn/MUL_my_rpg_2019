// /*
// ** EPITECH PROJECT, 2020
// ** Visual Studio Live Share (Workspace)
// ** File description:
// ** update_spell
// */

// #include "rpg.h"

// spell_t animation_spell(spell_t spell)
// {
//     sfTime time = sfClock_getElapsedTime(spell.clock);
//     float second = time.microseconds / 1000000.0;
//     printf("seconds:%f\n", second);
//     if (second > 0.09) {
//         if (spell.rect.left < 393) {
//             spell.rect.left += 56.125;
//         } else {
//             spell.rect.left = 0;
//         }
//         sfClock_restart(spell.clock);
//     }
//     sfSprite_setTextureRect(spell.sprite, spell.rect);
//     return (spell);
// }

// spell_t update_fireball(spell_t spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
// {
//     static int test = 0;
//     sfTime time;

//     if (spell.protection != 0 && spell.activated == 1 && test == 0) {
//         test = 1;
//         sfClock_restart(spell.clock);
//     }
//     if (test == 1) {
//         time = sfClock_getElapsedTime(spell.clock);
//         if (time.microseconds / 1000000 > 1) {
//             spell.activated = 2;
//             test = 0;
//         }
//     }
//     if (spell.activated == 1) {
//         // spell.= animation_spell(spell.;
//         // printf("pos x : %f\npos y : %f\n", spell.pos.x, spell.pos.y);
//         // printf("objectif : %f %f\n", spell.final_pos.x, spell.final_pos.y);
//         if (spell.final_pos.x != spell.pos.x || spell.final_pos.y != spell.pos.y) {
//             if (spell.protection != 0)
//                 spell.pos = (sfVector2f) {pos.x - 5, pos.y + 10};
//             else if (spell.direction == 0 || spell.direction == 5) {
//                 spell.pos.y += 5;
//             } else if (spell.direction == 1) {
//                 spell.pos.y -= 5;
//             } else if (spell.direction == 3) {
//                 spell.pos.x += 5;
//             } else if (spell.direction == 7) {
//                 spell.pos.x -= 5;
//             }
//         } else {
//             spell.activated = 2;
//         }
//         sfSprite_setPosition(spell.sprite, spell.pos);
//         for (int i = 0; i < fight->nb_enn; i++) {
//             if (fight->enns[i].in_live == 1)
//                 if (spell.pos.x > fight->enns[i].pos.x - 25 &&
//                 spell.pos.x < fight->enns[i].pos.x + 25 &&
//                 spell.pos.y > fight->enns[i].pos.y - 35 &&
//                 spell.pos.y < fight->enns[i].pos.y + 35) {
//                     fight->enns[i].life -= spell.damage;
//                     if (fight->enns[i].life <= 0)
//                         rpg->quest.scd_quest.nb_kills += 1;
//                 }
//             fight->enns[i].buttons[1].rect.width = fight->enns[i].life + 2;
//             sfSprite_setTextureRect(fight->enns[i].buttons[1].sprite, fight->enns[i].buttons[1].rect);
//         }
//     }
//     return (spell);
//     // si la firaball n'est tjs pas arrivé à l'endroit de fin, += 10
//     //si c'est arrivé à la fin (ou après) -> activated à 0
// }

// void update_spell(fight_t *fight, rpg_t *rpg)
// {
//     WEAPONS current = fight->player.weapon;
//     static int tmp = 0;

//     if (current == SHOVEL)
//       return;
//     if (current > SPELL_THREE)
//       current = SPELL_ONE;
//     // printf("AVANT : pos x %f | pos y %f\n", fight->spell[0].pos.x);
//     fight->spell[current - 1] = update_fireball(fight->spell[current - 1], fight->player.pos, fight, rpg);
//     // printf("APRES : pos x %f | pos y %f\n", fight->spell[0].pos.x);
//     for (int i = 0; i < 3; i += 1) {
//         fight->spell[i].clock_cd.time = sfClock_getElapsedTime(fight->spell[i].clock_cd.clock);
//         fight->spell[i].clock_cd.seconds = fight->spell[i].clock_cd.time.microseconds / 1000000.0;
//         if (fight->spell[i].activated == 2 && tmp == 0) {
//             sfClock_restart(fight->spell[i].clock_cd.clock);
//             tmp = 1;
//         }
//         if (fight->spell[i].activated == 2 && fight->spell[i].clock_cd.seconds >= fight->spell[i].sec) {
//             fight->spell[i].activated = 0;
//             tmp = 0;
//             sfClock_restart(fight->spell[i].clock_cd.clock);
//         }
//     }
// }