#include <stdio.h>
#include <stdlib.h>

#include "../include/main.h"
#include "../include/ui.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/assets.h"
#include "../include/utils.h"


int main() {


    clear();
    displayLogo();
    pressEnterToStart();
    clear();

    Player player1 = {0};
    Player player2 = {0};
    //displayRanking();
    printf("\nPlayer 1: ");
    getPlayerName(&player1);
// pega todas as infos do player 1

    clear();
    //displayRanking();
    printf("\nPlayer 2: ");
    getPlayerName(&player2);
// pega todas as infos do player 2


// inicia o combate

// retorna o vencedor

// salva no ranking

    //displayRanking();
    //displayGameOver();
    //displayCredits


}