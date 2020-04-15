/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_spell
*/

#include "rpg.h"

spell_t animation_spell(spell_t spell)
{
    sfTime time = sfClock_getElapsedTime(spell.clock);
    float second = time.microseconds / 1000000.0;
    printf("seconds:%f\n", second);
    if (second > 0.09) {
        if (spell.rect.left < 393) {
            spell.rect.left += 56.125;
        } else {
            spell.rect.left = 0;
        }
        sfClock_restart(spell.clock);
    }
    sfSprite_setTextureRect(spell.sprite, spell.rect);
    return (spell);
}

spell_t update_fireball(spell_t spell)
{
    if (spell.activated == 1) {
        // spell = animation_spell(spell);
        printf("heyy\n");
        // printf("pos x : %f\npos y : %f\n", spell.pos.x, spell.pos.y);
        // printf("objectif : %f %f\n", spell.final_pos.x, spell.final_pos.y);
        if (spell.final_pos.x != spell.pos.x || spell.final_pos.y != spell.pos.y) {
            if (spell.direction == 0 || spell.direction == 5) {
                spell.pos.y += 5;
            } else if (spell.direction == 1) {
                spell.pos.y -= 5;
            } else if (spell.direction == 3) {
                spell.pos.x += 5;
            } else if (spell.direction == 7) {
                spell.pos.x -= 5;
            }
        } else {
            spell.activated = 0;
        }
        sfSprite_setPosition(spell.sprite, spell.pos);
    }
    return (spell);
    // si la firaball n'est tjs pas arrivé à l'endroit de fin, += 10
    //si c'est arrivé à la fin (ou après) -> activated à 0
}

void update_spell(fight_t *fight)
{
    // printf("AVANT : pos x %f | pos y %f\n", fight->spell[0].pos.x);
    fight->spell[0] = update_fireball(fight->spell[0]);
    // printf("APRES : pos x %f | pos y %f\n", fight->spell[0].pos.x);
}