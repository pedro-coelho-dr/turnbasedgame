#ifndef COMBAT_H
#define COMBAT_H

#include <stdbool.h>

#include "linked_list.h"
#include "character.h"

int determineInitiative(Player *player1, Player *player2);
Player* startCombat(Player *player1, Player *player2);
Player* combatLoop(TurnNode *turn);
bool isDefeated(Player *player);
void attack(Character *defender, Attack *chosenAttack);
#endif