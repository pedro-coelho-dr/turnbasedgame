#include <stdio.h>
#include <stdlib.h>

#include "../include/main.h"
#include "../include/ui.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/assets.h"
#include "../include/utils.h"
#include "../include/linked_list.h"


int main() {

    clear();
    displayLogo();
    pressEnterToStart();

    CharacterNode *characterList = NULL;
    initializeCharacterList(&characterList);

    Player player1 = {0};
    player1.switchCount=0;
    clear();
    //displayRanking();
    printf("\nPlayer 1: ");
    getPlayerName(&player1);
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player1, characterList);
    clear();
    askInitiative(&player1);

    Player player2 = {0};
    player2.switchCount=0;
    clear();
    //displayRanking();
    printf("\nPlayer 2: ");
    getPlayerName(&player2);
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player2, characterList);
    clear();
    askInitiative(&player2);

    freeCharacterList(characterList);

    int firstPlayer = determineInitiative(&player1, &player2);
    if (firstPlayer == 1) {
     //   startCombat(&player1, &player2);
    } else {
      //  startCombat(&player2, &player1);
    }

    



// inicia o combate

// retorna o vencedor

// salva no ranking

    //displayRanking();
    //displayGameOver();
    //displayCredits

    return 0;

}