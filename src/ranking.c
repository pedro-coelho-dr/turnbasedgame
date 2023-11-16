// ranking.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ranking.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/ui.h"

void updateRanking(Player *winnerNode) {
    FILE *rankingFile = fopen("data/ranking.dat", "r+b");

    if (rankingFile == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }
    
    fseek(rankingFile, 0, SEEK_END);
    long fileSize = ftell(rankingFile);
    rewind(rankingFile);
    int numElements = fileSize / sizeof(Ranking);

    Ranking *rankings = malloc(fileSize);

    if (rankings == NULL) {
        fprintf(stderr, "Erro ao alocar memória para rankings.\n");
        fclose(rankingFile);
        return;
    }

    fread(rankings, sizeof(Ranking), numElements, rankingFile);

    int found = 0;
    for (int i = 0; i < numElements; i++) {
        if (strcmp(rankings[i].name, winnerNode->name) == 0) {
            rankings[i].totalWins += 1;
            found = 1;
            break;
        }
    }

    if (!found) {
        int emptySlot = -1;
        for (int i = 0; i < numElements; i++) {
            if (rankings[i].totalWins == 0) {
                emptySlot = i;
                break;
            }
        }
        if (emptySlot == -1) {
            emptySlot = numElements;
            numElements++;
        }

        strcpy(rankings[emptySlot].name, winnerNode->name);
        rankings[emptySlot].totalWins = 1;
    }

    bubbleSortv2(rankings, numElements);

    for (int i = 0; i < numElements; i++) {
        rankings[i].rankingPosition = i + 1;
    }

    fseek(rankingFile, 0, SEEK_SET);
    fwrite(rankings, sizeof(Ranking), numElements, rankingFile);

    free(rankings);

    if (fclose(rankingFile) != 0) {
        fprintf(stderr, "Erro ao fechar o arquivo.\n");
    }
}



void displayRanking() {
    FILE *rankingFile = fopen("data/ranking.dat", "rb");

    if (rankingFile == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(rankingFile, 0, SEEK_END);
    long fileSize = ftell(rankingFile);
    rewind(rankingFile);
    int numElements = fileSize / sizeof(Ranking);

    Ranking *rankings = malloc(sizeof(Ranking) * numElements);

    if (rankings == NULL) {
        fprintf(stderr, "Erro ao alocar memória para rankings.\n");
        fclose(rankingFile);
        return;
    }
    
    fread(rankings, sizeof(Ranking), numElements, rankingFile);
    int maxPositionsToDisplay = (numElements < 10) ? numElements : 10;

    int columnWidth = 50;

    printf("-------------------------------------------------------------------------------------------\n");
    printf("                                      Hall of Fame\n");
    printf("-------------------------------------------------------------------------------------------\n");
    
    printf("|    %s\t |", "Posição");
    printCentered("Nome", columnWidth);
    printf("|    %s\t |\n", "Vitórias");

    for (int i = 0; i < maxPositionsToDisplay; i++) {
        printf("|%*d.\t |", 8, i + 1);

        if (i < numElements) {
            printCentered(rankings[i].name, columnWidth);
            printf("|");
            printCenteredNumber(rankings[i].totalWins, 17);  
            printf(" \t |\n");
            
        } else {
            break;
        }
    }

    printf("\n\n\n\n\n");

    free(rankings);

    if (fclose(rankingFile) != 0) {
        fprintf(stderr, "Erro ao fechar o arquivo.\n");
    }
}


void bubbleSortv2(Ranking *rankings, int n) {
     int k =1, troca = 1;
    while(k <= n && troca == 1){
        troca = 0;
    for (int i = 0; i < n - 1; i++) {
            if (rankings[i].totalWins < rankings[i + 1].totalWins) {
                Ranking temp = rankings[i];
                rankings[i] = rankings[i + 1];
                rankings[i + 1] = temp;
                troca = 1;
            }
        }
        ++k;
    }
}   	





