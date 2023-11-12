#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/combat.h"
#include "../include/character.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/ui.h"

int determineInitiative(Player *player1, Player *player2) {
    if (player1->initiativeChoice == player2->initiativeChoice) {
        return randomInitiative();
    } else {
        return (player1->initiativeChoice==1) ? 1 : 2;
    }
}

Player* startCombat(Player *player1, Player *player2) {

    displayStartCombat();

    chooseCharacter(player1);
    printf("\n--------------\n");
    chooseCharacter(player2);

    TurnNode *turn = createCircularList(player1, player2);

    Player* winner = combatLoop(turn);

    free(turn->next);
    free(turn);

    return winner;
}

Player* combatLoop(TurnNode *turn) {
    while (true) {
        Player *currentPlayer = turn->player;
        Player *opponentPlayer = turn->next->player;

        actionMenu(currentPlayer, opponentPlayer);

        if(isDefeated(opponentPlayer)){
            return currentPlayer;
        }
        turn = turn->next;
    }
}

bool isDefeated(Player *player) {
    for (int i=0; i<3; i++) {
        if (player->characters[i].health > 0) {
            return false;
        }
    }
    return true;
}

void attack(Character *defender, Attack *chosenAttack) {
    float damageMultiplier = 1.0f;

    if (defender->immunity==chosenAttack->type) {
        printf("\n\n%s e imune a ataque do tipo %s!\n", defender->name, getType(chosenAttack->type));
        damageMultiplier = 0;
    }

    for (int i = 0; i < 2; i++) {
        if (defender->resistances[i]==chosenAttack->type) {
            printf("\n\n%s tem resistencia a ataque do tipo %s!\n", defender->name, getType(chosenAttack->type));
            damageMultiplier = 0.5f;
            break;
        }
    }

    if (defender->weakness==chosenAttack->type) {
        printf("\n\n%s e vuneravel a ataque do tipo %s!\n", defender->name, getType(chosenAttack->type));
        damageMultiplier *= 2.0f;
    }

    int damage = (int)(chosenAttack->damage*damageMultiplier);
    defender->health -= damage;

    if (damageMultiplier>0) {
        printf("\n\n%s recebeu %d de dano!\n", defender->name, damage);
    } else {
        printf("\n\n%s não sentiu nenhum efeito!\n", defender->name);
    }
    if (defender->health <= 0) {
        defender->health = 0;
    }
}



