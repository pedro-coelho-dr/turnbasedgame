#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "character.h"
typedef struct CharacterNode {
    Character character;
    struct CharacterNode *next;
} CharacterNode;

void addCharacterList(CharacterNode **head, Character character);
void initializeCharacterList(CharacterNode **head);
void freeCharacterList(CharacterNode *head);

typedef struct TurnNode {
    Player *player;
    struct TurnNode *next;
} TurnNode;

TurnNode* createCircularList(Player *player1, Player *player2);

#endif