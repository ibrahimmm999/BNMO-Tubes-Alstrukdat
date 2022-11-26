#include <stdio.h>

#include "../ADT/queueV2.h"
#include "../games/rng.h"
#include "../games/tictactoe.h"
#include "../games/dinerdash.h"
#include "../games/guntingbatuk.h"
#include "../ADT/stackV2.h"
#include "history.h"
#include "../games/TowerOfHanoi.h"

#ifndef PLAYGAME_H
#define PLAYGAME_H

void PLAYGAME(Queue *queueGame, StackW *history);
void displayCurrentGame(Word CurrentGame);

#endif