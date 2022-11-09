#include <stdio.h>

#include "queueV2.h"
#include "mesinkata.h"
#include "boolean.h"
#include "PLAYGAME.h"

#ifndef _SKIPGAME_H_
#define _SKIPGAME_H_

void SKIPGAME(Queue *queueGame, int numSkip);
/* Proses: melakukan dequeue terhadap queueGame sebanyak numSkip kali */
/* I.S. queueGame terdefinisi, mungkin kosong */
/* F.S. queueGame dengan beberapa antrean game teratas dihapus, mungkin kosong */

#endif
