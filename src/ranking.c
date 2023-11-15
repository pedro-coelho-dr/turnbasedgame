// ranking.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ranking.h"

void printCentered(char *str, int width) {
    int len = strlen(str);
    int spaces = (width - len) / 2;
    printf("%*s%-*s", spaces, "", width - spaces, str);
}

void printCenteredNumber(int number, int width) {
    char numStr[3];  
    sprintf(numStr, "%d", number);
    
    printCentered(numStr, width);
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
            rankings[i].totalWins += 1;  // Incrementa o total de vitórias
            found = 1;
            break;
        }
    }

    if (!found) {
        // Procurar um slot vazio para adicionar um novo jogador
        int emptySlot = -1;
        for (int i = 0; i < numElements; i++) {
            if (rankings[i].totalWins == 0) {
                emptySlot = i;
                break;
            }
        }

        // Se não houver slot vazio, adiciona ao final da lista
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

    // Usar a estrutura para armazenar apenas as posições que serão exibidas
    Ranking *rankings = malloc(sizeof(Ranking) * numElements);

    if (rankings == NULL) {
        fprintf(stderr, "Erro ao alocar memória para rankings.\n");
        fclose(rankingFile);
        return;
    }
    
    fread(rankings, sizeof(Ranking), numElements, rankingFile);
    int maxPositionsToDisplay = (numElements < 10) ? numElements : 10;

    int columnWidth = 50;  // Largura total da linha

    printf("-------------------------------------------------------------------------------------------\n");
    printf("                                         Ranking\n");
    printf("-------------------------------------------------------------------------------------------\n");
    
    printf("|    %s\t |", "Posição");
    printCentered("Nome", columnWidth);
    printf("|    %s\t |\n", "Vitórias");

    for (int i = 0; i < maxPositionsToDisplay; i++) {
        printf("|%*d.\t |", 8, i + 1);

        if (i < numElements) {
            printCentered(rankings[i].name, columnWidth);
            printf("|");
            printCenteredNumber(rankings[i].totalWins, 17);  // Largura 11 para acomodar "Vitórias"
            printf(" \t |\n");
        } else {
            break;
        }
    }

    free(rankings);

    if (fclose(rankingFile) != 0) {
        fprintf(stderr, "Erro ao fechar o arquivo.\n");
    }
}







