#ifndef RANKING_H
#define RANKING_H

#include <stdio.h>

#include "character.h"
#include "linked_list.h"

typedef struct Ranking {
    char name[50];
    int totalWins;  
    int rankingPosition;
} Ranking;

void updateRanking(Player *winnerNode);
void displayRanking();
void bubbleSortv2(Ranking *rankings, int n);


#endif
