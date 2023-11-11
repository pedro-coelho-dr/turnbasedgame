#ifndef CHARACTER_H
#define CHARACTER_H

typedef enum{
    PHYSICAL,
    MAGICAL,
    FIRE,
    WATER,
    POISON,
    ELECTRIC,
} Type;

typedef struct Attack {
    char name[50];
    int damage;
    Type type;
} Attack;

typedef struct Character {
    char name[50];
    int health;
    Type type;
    Type immunity;
    Type resistances[2];
    Type weakness;
    Attack attacks[3];
} Character;


typedef struct Player {
    char name[50];
    Character characters[3];
    int currentCharacter;
} Player;


//PREDEFINED CHARACTERS

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
        {.name = "Nature´s Gift", .damage = 15, .type = MAGICAL},
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

#endif