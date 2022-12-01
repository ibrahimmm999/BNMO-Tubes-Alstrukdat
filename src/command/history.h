/* File history.h */

#include <stdio.h>
#include "../ADT/stackV2.h"
#include "../ADT/mesinkata.h"

#ifndef _HISTORY__
#define _HISTORY__

void addToHistory(StackW *history, Word gamePlayed);
// I.S. history terdefinisi, mungkin kosong, gamePlayed terdefinisi, length gamePlayed > 0
// F.S. Top history berubah menjadi gamePlayed

void HISTORY(StackW history, int n);
// I.S. history terdefinisi, mungkin kosong, n pasti integer
// F.S. Ditampilkan n urutan teratas history

#endif