#ifndef UI_H
#define UI_H

#include "character.h" 
#include "linked_list.h"

void pressEnterToStart(void);
void getPlayerName(Player *player);
void displayCharacterList(CharacterNode *head);
void selectCharacters(Player *player, CharacterNode *head);
void askInitiative(Player *player);

#endif