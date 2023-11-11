#include <stdio.h>
#include <stdlib.h>

#include "../include/character.h"

// Funções necessárias
// Calcular o dano
// Causar o ataque
// Selecionar ataque
// trocar personagem
// status do personagem(se está vivo ou morto)
// display do personagem o HP e o status podem ir no UI...




// PREDEFINED CHARACTERS
const Character charmander = {
    .name = "Charmander",
    .health = 100,
    .type = FIRE,
    .immunity = FIRE,
    .resistances = {POISON, ELECTRIC},
    .weakness = WATER,
    .attacks = {
        {.name = "Ember", .damage = 20, .type = FIRE},
        {.name = "Mystic Claw", .damage = 15, .type = MAGICAL},
        {.name = "Flamethrower", .damage = 40, .type = FIRE}
    }
};

const Character squirtle = {
    .name = "Squirtle",
    .health = 100,
    .type = WATER,
    .immunity = WATER,
    .resistances = {POISON, FIRE},
    .weakness = ELECTRIC,
    .attacks = {
        {.name = "Water Gun", .damage = 20, .type = WATER},
        {.name = "Tackle", .damage = 15, .type = PHYSICAL},
        {.name = "Bubble Beam", .damage = 40, .type = WATER}
    }
};

const Character bulbasaur = {
    .name = "Bulbasaur",
    .health = 100,
    .type = POISON,
    .immunity = POISON,
    .resistances = {WATER, ELECTRIC},
    .weakness = FIRE,
    .attacks = {
        {.name = "Vine Whip", .damage = 20, .type = POISON},
        {.name = "Nature Gift", .damage = 15, .type = MAGICAL},
        {.name = "Razor Leaf", .damage = 40, .type = POISON}
    }
};

const Character pikachu = {
    .name = "Pikachu",
    .health = 100,
    .type = ELECTRIC,
    .immunity = ELECTRIC,
    .resistances = {WATER, FIRE},
    .weakness = POISON,
    .attacks = {
        {.name = "Thunder Shock", .damage = 20, .type = ELECTRIC},
        {.name = "Quick Attack", .damage = 15, .type = PHYSICAL},
        {.name = "Electro Ball", .damage = 40, .type = ELECTRIC}
    }
};


const Character jigglypuff = {
    .name = "Jigglypuff",
    .health = 100,
    .type = MAGICAL,
    .immunity = MAGICAL,
    .resistances = {POISON, WATER},
    .weakness = PHYSICAL,
    .attacks = {
        {.name = "Sing", .damage = 20, .type = MAGICAL},
        {.name = "Body Slam", .damage = 15, .type = PHYSICAL},
        {.name = "Hyper Voice", .damage = 40, .type = MAGICAL}
    }
};

const Character rattata = {
    .name = "Rattata",
    .health = 100,
    .type = PHYSICAL,
    .immunity = PHYSICAL,
    .resistances = {FIRE, ELECTRIC},
    .weakness = MAGICAL,
    .attacks = {
        {.name = "Tackle", .damage = 20, .type = PHYSICAL},
        {.name = "Arcane Assault", .damage = 15, .type = MAGICAL},
        {.name = "Hyper Fang", .damage = 40, .type = PHYSICAL}
    }
};
