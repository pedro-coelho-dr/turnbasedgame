#ifndef CHARACTER_H
#define CHARACTER_H

typedef enum{
    ELECTRIC,
    FIRE,
    MAGICAL,
    PHYSICAL,
    POISON,
    WATER,
} Type;

typedef struct Attack {
    char name[50];
    int damage;
    Type type;
} Attack;

typedef struct Character {
    char name[50];
    int health;
    int specialAttack;
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
    int switchCount;
    int initiativeChoice;
} Player;


//PREDEFINED CHARACTERS

extern const Character charmander;
extern const Character squirtle;
extern const Character bulbasaur;
extern const Character pikachu;
extern const Character jigglypuff;
extern const Character rattata;

// FUNCTIONS

const char* getType(Type type);

#endif