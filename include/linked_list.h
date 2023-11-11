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


#endif