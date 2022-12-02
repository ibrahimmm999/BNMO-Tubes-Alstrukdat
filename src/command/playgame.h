#include <stdio.h>

#include "history.h"
#include "../ADT/queueV2.h"
#include "../ADT/stackV2.h"
#include "../ADT/MapV2.h"
#include "../ADT/setV2.h"
#include "../games/rng.h"
#include "../games/tictactoe.h"
#include "../games/dinerdash.h"
#include "../games/hangman.h"
#include "../games/guntingbatuk.h"
#include "../games/TowerOfHanoi.h"
#include "../games/snakeonmeteor.h"
#include "../games/guessthepeterparker.h"
#include "../command/scoreboard.h"

#ifndef PLAYGAME_H
#define PLAYGAME_H

void playCurrentGame(Queue *queueGame, StackW *history, Word currentGame, SetV2 *SBGame);
void PLAYGAME(Queue *queueGame, StackW *history, SetV2 *SBGame);
void displayCurrentGame(Word CurrentGame);

#endif