#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../include/main.h"
#include "../include/ui.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/assets.h"
#include "../include/utils.h"
#include "../include/linked_list.h"


int main() {
    srand((unsigned int)time(NULL));

    clear();
    displayLogo();
    printf("\n\n\n");
    displayRanking(); 
    pressEnterToStart();
    

//CHARACTERS INIT
    CharacterNode *characterList = NULL;
    initializeCharacterList(&characterList);

//PLAYER 1
    Player player1 = {0};
    player1.switchCount=0;
    player1.currentCharacter = -1;
    clear();
    //displayRanking();
    printf("\n[JOGADOR 1] \n\n>>> ");
    getPlayerName(&player1);
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player1, characterList);
    clear();
    //askInitiative(&player1);

//PLAYER 2
    Player player2 = {0};
    player2.switchCount=0;
    player2.currentCharacter = -1;
    clear();
    //displayRanking();
    printf("\n[JOGADOR 2]\n\n>>> ");
    getPlayerName(&player2);
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player2, characterList);
    clear();
    //askInitiative(&player2);
//TESTES
    //printPlayer(&player1);
    //printPlayer(&player2);
    //printCharacterList(characterList);
    
    freeCharacterList(characterList);


//COMBAT
    int firstPlayer = randomInitiative();
    Player *winner;
    if (firstPlayer == 1) {
        winner = startCombat(&player1, &player2);
    } else {
        winner = startCombat(&player2, &player1);
    }
    clear();
    updateRanking(winner); 
    vencedor(winner);
    sleep(4);
    displayRanking(); 
    sleep(2);
    displayCredits();

    return 0;
}