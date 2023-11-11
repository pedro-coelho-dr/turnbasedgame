
typedef enum{
    PHYSICAL,
    MAGIC,
    FIRE,
    WATER,
    POISON,
    ELECTRIC,
} Type;

typedef struct Character {
    char name[50];
    int health;
    Type type;
    Type imunity;
    Type resistances[2];
    Type weakness;
    Attack attacks[3];
} Character;

typedef struct Attack {
    char name;
    int damage;
    Type type;
} Attack;

typedef struct Player {
    char name[50];
    Character characters[3];
    int currentCharacter;
} Player;


//tipos, struct attack, 