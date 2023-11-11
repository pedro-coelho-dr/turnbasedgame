#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/ui.h"
#include "../include/character.h"
#include "../include/linked_list.h"

void pressEnterToStart(void) {
    int c;
    printf("\n                       PRESS ENTER TO START");
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
        printf("%d. %s - Type: %s\n    Attacks: ", 
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

    printf("Select 3 pokemons.\n");
    for (int i=0; i<3; i++) {
        do {
            printf("Select pokemon %d: ", i+1);
            scanf("%d", &choice);
            while (getchar() != '\n');
            if (choice<1 || choice>numCharacters) {
                printf("[INVALID] Number must be between 1 and %d.\n", numCharacters);
                continue;
            }

            aux = head;
            for (int index=1; aux!=NULL && index<choice; index++){
                aux = aux->next;
            }

            if (aux!=NULL) {
                player->characters[i] = aux->character;
                printf("%s, I choose you!\n", aux->character.name);
                //display pokemon ascii art ?
                break;
            }
        } while (true);
    }
}

void askInitiative(Player *player) {
    do {
        printf("Do you want to choose your pokemon first or wait for the opponent?\n1 - First\n2 - Wait\n>>> ");
        if (scanf("%d", &player->initiativeChoice) != 1 || 
                (player->initiativeChoice != 1 && player->initiativeChoice != 2)) {
            printf("[INVALID] 1 for first, 2 to wait...\n");
            while (getchar() != '\n'); 
        } else {
            while (getchar() != '\n');
            break;
        }
    } while (true);
}
