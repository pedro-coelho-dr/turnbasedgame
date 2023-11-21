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
    return (rand() % 2) + 1;
}


// TESTES
/* void printPlayer(const Player *player) {
    printf("Player Name: %s\n", player->name);
    printf("Current Character: %d\n", player->currentCharacter);
    printf("Switch Count: %d\n", player->switchCount);
   // printf("Initiative Choice: %d\n", player->initiativeChoice);
    printf("Characters:\n");
    for (int i = 0; i < 3; i++) {
        printCharacter(&player->characters[i]);
        printf("\n");
    }
}
void printCharacter(const Character *character) {
    printf("Name: %s\n", character->name);
    printf("Health: %d\n", character->health);
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
} */

void vencedor(Player *winnerNode){
    clear();
    displayLogo();
    printCharacterArt(winnerNode->characters[0].name);
    printf("\n\n\n\n                             ***********************************\n");
    printf("                                 %s, you`re the winner!!\n", winnerNode->name);
    printf("                               Congratulations on your journey.\n");
    printf("                                 You're on the right track!\n");
    printf("                              ***********************************\n\n\n\n\n");

    
}

void displayCredits(){
        printf("                                       - THE END - \n");
        printf("                                     TURN BASED GAME\n");
        printf("                                    POKÉMON INSPIRED\n\n");
        printf("                                       Cesar.School\n");
        printf("                 Projeto para a disciplina de Algoritimo e Estrutura de dados\n");
        printf("                                  Professora Natacha Targino\n");
        printf("                         Alunos: Camila Cirne e Pedro Coelho\n\n\n");

}