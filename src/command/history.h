/* File history.h */

#include <stdio.h>
#include "../ADT/stackV2.h"
#include "../ADT/mesinkata.h"

#ifndef _HISTORY__
#define _HISTORY__

void addToHistory(StackW *history, Word gamePlayed);

void HISTORY(StackW history, int n);

#endif