#include <stdio.h>

#include "../ADT/queueV2.h"
#include "../games/rng.h"
#include "../games/tictactoe.h"

#ifndef PLAYGAME_H
#define PLAYGAME_H

void PLAYGAME(Queue *queueGame);
void displayCurrentGame(Word CurrentGame);

#endif