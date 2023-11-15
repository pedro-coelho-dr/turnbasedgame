#ifndef RANKING_H
#define RANKING_H

#include <stdio.h>
#include "../include/character.h"
#include "../include/linked_list.h"

typedef struct Ranking {
    char name[50];
    int totalWins;  
    int rankingPosition;
} Ranking;

void printCentered(char *str, int width);
void printCenteredNumber(int number, int width);
void bubbleSortv2(Ranking *rankings, int n);
void updateRanking(Player *winnerNode);
void displayRanking();



#endif
