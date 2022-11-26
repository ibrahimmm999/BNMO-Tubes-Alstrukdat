#include <stdio.h>

#include "../ADT/queueV2.h"
#include "../ADT/mesinkata.h"
#include "../boolean.h"
#include "PLAYGAME.h"
#include "history.h"

#ifndef _SKIPGAME_H_
#define _SKIPGAME_H_

void SKIPGAME(Queue *queueGame, StackW *history, int numSkip);
/* Proses: melakukan dequeue terhadap queueGame sebanyak numSkip kali */
/* I.S. queueGame terdefinisi, mungkin kosong */
/* F.S. queueGame dengan beberapa antrean game teratas dihapus, mungkin kosong */

#endif
