/* File : skip_game.h */
/* Definisi SKIPGAME untuk menghapus n permainan pertama dari antrean dan langsung memulai permainan ke-(n+1) */

#ifndef __SKIPGAME__H
#define __SKIPGAME__H

#include "boolean.h"
#include "queue.h"

void SKIPGAME(Queue *Q, int n);
    /* Proses: */
    /* I.S. QUEUEGAME mungkin kosong */
    /* F.S. Ditampilkan QUEUEGAME pemain, melewati n buah permainan pada antrean awal. Mulai memainkan permainan pada antrean ke-(n+1) jika ada. QUEUEGAME mungkin kosong. */