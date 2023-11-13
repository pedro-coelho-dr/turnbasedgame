#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/ui.h"
#include "../include/character.h"
#include "../include/linked_list.h"
#include "../include/utils.h"

#define MAX_SWITCHES 3

void pressEnterToStart(void) {
    int c;
    printf("\n                       [PRESS ENTER TO START]");
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void getPlayerName(Player *player) {
/*     int c;
    while ((c = getchar()) != '\n' && c != EOF) {} */
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = '\0';
}

void displayCharacterList(CharacterNode *head) {
    int index = 1;
    CharacterNode *aux = head;

    while (aux != NULL) {
        printf("\n%d. %s - Tipo: %s\n    Ataques: ", 
            index, 
            aux->character.name, 
            getType(aux->character.type));
        for (int i=0; i<3; i++) {
            printf("%s (%s)", 
                aux->character.attacks[i].name, 
                getType(aux->character.attacks[i].type));
            if (i < 2) printf(", ");
        }
        printf("\n");

        aux = aux->next;
        index++;
    }
}

void selectCharacters(Player *player, CharacterNode *head) {
    int choice, numCharacters = 0;
    CharacterNode *aux = head;

    while (aux != NULL) {
        numCharacters++;
        aux = aux->next;
    }

    printf("\n(Escolha 3 pokemons)\n\n");
    for (int i=0; i<3; i++) {
        do {
            printf("Selecione pokemon %d: ", i+1);
            printf("\n>>> ");
            scanf("%d", &choice);
            while (getchar() != '\n');
            if (choice<1 || choice>numCharacters) {
                printf("\n[INVALIDO]\n");
                continue;
            }

            aux = head;
            for (int index=1; aux!=NULL && index<choice; index++){
                aux = aux->next;
            }

            if (aux!=NULL) {
                player->characters[i] = aux->character;
                printf("%s, eu escolho você!\n\n", aux->character.name);
                break;
            }
        } while (true);
    }
}
/* 
void askInitiative(Player *player) {
    do {
        printf("Você quer escolher seu pokemon primeiro ou esperar pelo seu oponente?\n1 - Primeiro\n2 - Esperar\n>>> ");
        if (scanf("%d", &player->initiativeChoice) != 1 || 
                (player->initiativeChoice != 1 && player->initiativeChoice != 2)) {
            printf("[INVALIDO]\n");
            while (getchar() != '\n'); 
        } else {
            while (getchar() != '\n');
            break;
        }
    } while (true);
}
 */
void actionMenu(Player *currentPlayer, Player *opponentPlayer) {
    int choice;

    int alive = 0;
    for (int i=0; i<3; i++) {
        if (currentPlayer->characters[i].health > 0) {
            alive++;
        }
    }

    printf("\n--------------\n");
    printf("\nInimigo: %s (VIDA: %d)\n", opponentPlayer->characters[opponentPlayer->currentCharacter].name, opponentPlayer->characters[opponentPlayer->currentCharacter].health);
    printf("\n\n# %s #\n", currentPlayer->name);
    printf("\n*%s (VIDA: %d)*", currentPlayer->characters[currentPlayer->currentCharacter].name, currentPlayer->characters[currentPlayer->currentCharacter].health);

    if (currentPlayer->characters[currentPlayer->currentCharacter].health <= 0) {
        printf("\n\n%s desmaiou!\n", currentPlayer->characters[currentPlayer->currentCharacter].name);
        chooseCharacter(currentPlayer);
    }

    do {
        printf("\n\n1. LUTAR\n");
        if (alive > 1 && currentPlayer->switchCount < MAX_SWITCHES) {
            printf("2. TROCAR [%d]\n", MAX_SWITCHES - currentPlayer->switchCount);
        }
        printf("\n>>> ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (choice==2 && (alive<=1 || currentPlayer->switchCount >= MAX_SWITCHES)) {
            printf("\nTroca nao permitida!\n");
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                attackMenu(currentPlayer, opponentPlayer);
                break;
            case 2:
                currentPlayer->switchCount++;
                chooseCharacter(currentPlayer);
                break;
            default:
                printf("[INVALIDO]\n");
                choice = 0; 
                break;
        }
    } while (choice!=1 && choice!=2);
}

void attackMenu(Player *currentPlayer, Player *opponentPlayer) {
    int choice;
    Character *attackingCharacter = &currentPlayer->characters[currentPlayer->currentCharacter];
    printf("\n# %s #\n", currentPlayer->name);
    printf("\n*%s (VIDA: %d)*\n", currentPlayer->characters[currentPlayer->currentCharacter].name, currentPlayer->characters[currentPlayer->currentCharacter].health);
    printf("\nInimigo: %s (VIDA: %d)\n\n\n", opponentPlayer->characters[opponentPlayer->currentCharacter].name, opponentPlayer->characters[opponentPlayer->currentCharacter].health);

    for (int i=0; i<3; i++) {
        printf("%d. %s (TIPO: %s)", i+1, attackingCharacter->attacks[i].name, getType(attackingCharacter->attacks[i].type));
        if (i==2) { 
            printf(" [%d]", attackingCharacter->specialAttack);
        }
        printf("\n");
    }
    printf("\n>>> ");
    scanf("%d", &choice);
    while (choice<1 || choice>3 || (choice==3 && attackingCharacter->specialAttack == 0)) {
        printf("[INVALIDO]\n>>> ");
        scanf("%d", &choice);
    } 
    while (getchar() != '\n'); 
    if (choice==3) {
        attackingCharacter->specialAttack = 0;
    }
    printCharacterArt(currentPlayer->characters[currentPlayer->currentCharacter].name);
    printf("%s usou %s!\n", currentPlayer->characters[currentPlayer->currentCharacter].name, attackingCharacter->attacks[choice-1].name);
    attack(&opponentPlayer->characters[opponentPlayer->currentCharacter], &attackingCharacter->attacks[choice-1]);
}

void chooseCharacter(Player *player) {
    int alive = 0;
    int lastAlive = -1;
    for (int i = 0; i < 3; i++) {
        if (player->characters[i].health > 0) {
            alive++;
            lastAlive = i;
        }
    }
    if (alive == 1 && lastAlive != player->currentCharacter) {
        player->currentCharacter = lastAlive;
        printCharacterArt(player->characters[player->currentCharacter].name);
        printf("\n\nVai! %s!\n", player->characters[player->currentCharacter].name);
        return;
    }

    int choice;
    printf("\n\n%s, escolha seu pokemon:\n", player->name);
    for (int i = 0; i < 3; i++) {
        if (i == player->currentCharacter) {
            printf("[*] %s (VIDA: %d)\n", player->characters[i].name, player->characters[i].health);
        } else if (player->characters[i].health > 0) {
            printf("%d. %s (VIDA: %d)\n", i+1, player->characters[i].name, player->characters[i].health);
        } else {
            printf("%d. %s [Desmaiado]\n", i+1, player->characters[i].name);
        }
    }
    printf("\n>>> ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3 || choice-1 == player->currentCharacter || player->characters[choice-1].health <= 0) {
        printf("[INVALIDO]\n>>> ");
        scanf("%d", &choice);
    }
    while (getchar() != '\n');

    player->currentCharacter = choice-1;
    printCharacterArt(player->characters[player->currentCharacter].name);
    printf("\n\nVai! %s!\n", player->characters[player->currentCharacter].name);
}
