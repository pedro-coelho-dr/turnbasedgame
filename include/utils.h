#ifndef UTILS_H
#define UTILS_H

#include "character.h"
#include "linked_list.h"

void clear();
int randomInitiative();
/* void printPlayer(const Player *player);
void printCharacter(const Character *character);
void printCharacterList(const CharacterNode *head); */
void vencedor(Player *winnerNode);
void displayCredits();

#endif