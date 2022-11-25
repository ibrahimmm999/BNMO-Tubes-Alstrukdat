/* File history.h */

#include <stdio.h>
#include "../ADT/listV2.h"
#include "../ADT/mesinkata.h"

#ifndef _HISTORY__
#define _HISTORY__

void addToHistory(ListV2 *history, Word gamePlayed);

void HISTORY(ListV2 history, int n);

#endif