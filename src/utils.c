#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/utils.h"

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