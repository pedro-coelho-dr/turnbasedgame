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

    //initialize characters
    CharacterNode *characterList = NULL;
    initializeCharacterList(&characterList);

    //PLAYER 1
        //initialize player1
    Player player1 = {0};
    player1.switchCount=0;

        //player 1 name
    clear();
    //displayRanking();
    printf("\nPlayer 1: ");
    getPlayerName(&player1);

        //choose characters
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player1, characterList);
    //PLAYER2
        //initialize player2
    Player player2 = {0};
    player2.switchCount=0;

        //player 2 name
    clear();
    //displayRanking();
    printf("\nPlayer 2: ");
    getPlayerName(&player2);

        //choose characters
    clear();
    displayCharacterList(characterList);
    selectCharacters(&player2, characterList);



    freeCharacterList(characterList);


// inicia o combate

// retorna o vencedor

// salva no ranking

    //displayRanking();
    //displayGameOver();
    //displayCredits


}