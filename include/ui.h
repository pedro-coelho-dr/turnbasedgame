#ifndef UI_H
#define UI_H

#include "character.h" 
#include "linked_list.h"

void pressEnterToStart(void);
void getPlayerName(Player *player);
void displayCharacterList(CharacterNode *head);
void selectCharacters(Player *player, CharacterNode *head);
//void askInitiative(Player *player);
void actionMenu(Player *currentPlayer, Player *opponentPlayer);
void attackMenu(Player *currentPlayer, Player *opponentPlayer);
void chooseCharacter(Player *player);
void printCentered(char *str, int width);
void printCenteredNumber(int number, int width);

#endif