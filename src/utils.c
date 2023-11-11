#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/utils.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/linked_list.h"

void clear() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int randomInitiative() {
    srand((unsigned int)time(NULL));
    return (rand() % 2) + 1;
}


// testes
void printPlayer(const Player *player) {
    printf("Player Name: %s\n", player->name);
    printf("Current Character: %d\n", player->currentCharacter);
    printf("Switch Count: %d\n", player->switchCount);
    printf("Initiative Choice: %d\n", player->initiativeChoice);
    printf("Characters:\n");
    for (int i = 0; i < 3; i++) {
        printCharacter(&player->characters[i]);
        printf("\n");
    }
}
void printCharacter(const Character *character) {
    printf("Name: %s\n", character->name);
    printf("Health: %d\n", character->health);
    printf("Status: %s\n", character->status == ALIVE ? "Alive" : "Dead");
    printf("Type: %s\n", getType(character->type));
    printf("Immunity: %s\n", getType(character->immunity));
    printf("Resistances: %s, %s\n", getType(character->resistances[0]), getType(character->resistances[1]));
    printf("Weakness: %s\n", getType(character->weakness));
    printf("Attacks:\n");
    for (int i = 0; i < 3; i++) {
        printf("  - %s (Damage: %d, Type: %s)\n", character->attacks[i].name, character->attacks[i].damage, getType(character->attacks[i].type));
    }
}
void printCharacterList(const CharacterNode *head) {
    const CharacterNode *current = head;
    while (current != NULL) {
        printCharacter(&current->character);
        printf("\n");
        current = current->next;
    }
}
