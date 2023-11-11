#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ui.h"
#include "../include/character.h"

void pressEnterToStart(void) {
    int c;
    printf("\n                       PRESS ENTER TO START");
    while ((c=getchar()) != '\n' && c!=EOF);
}

void getPlayerName(Player *player) {
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = '\0';
}

