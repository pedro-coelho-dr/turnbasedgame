#include <stdio.h>
#include <stdlib.h>

#include "../include/combat.h"

#define MAX_SWITCHES 3


// Após decidir a iniciativa, os jogadores sao postos em uma lista circular,
// Haverá um loop principal que checa se o jogo acabou
// (se todos os pokemons de um player morreram)
// senao ele chama a funcao do turno (que termina passando pro proximo turno)
// e ao concluir a ação de atacar ou trocar, a lista gira
// volta pro loop principal -- vê se a luta acabou
// chama novamente a funcao do turno, e assim segue...
// pra troca/ataque tem que checar os pokemons vivos


// loop principal (retorna com o Player winner)
// fim do jogo (pro loop principal parar)



