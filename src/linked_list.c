#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/linked_list.h"
#include "../include/character.h"

// UI: criar character node para ordenar os pokemons para a escolha,
// COMBAT: criar o player node da lista circular, 
// UI: criar ranking node para ordenar o ranking

// CHARACTER LIST
void addCharacterList(CharacterNode **head, Character character) {
    CharacterNode *new = malloc(sizeof(CharacterNode));
    CharacterNode *aux;

    new->character = character;

    if (*head==NULL || 
        (*head)->character.type > character.type ||
        ((*head)->character.type == character.type &&
        strcmp((*head)->character.name, character.name) > 0)) 
        {
        new->next = *head;
        *head = new;
    } else {
        aux = *head;
        while (aux->next != NULL &&
               (aux->next->character.type < character.type ||
               (aux->next->character.type == character.type && strcmp(aux->next->character.name, character.name) <= 0))) 
               {
            aux = aux->next;
        }
        new->next = aux->next;
        aux->next = new;
    }
}
void initializeCharacterList(CharacterNode **head) {
    *head = NULL;
    addCharacterList(head, charmander);
    addCharacterList(head, squirtle);
    addCharacterList(head, bulbasaur);
    addCharacterList(head, pikachu);
    addCharacterList(head, jigglypuff);
    addCharacterList(head, rattata);
}

void freeCharacterList(CharacterNode *head) {
    CharacterNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// RANKING LIST


// COMBAT LIST


