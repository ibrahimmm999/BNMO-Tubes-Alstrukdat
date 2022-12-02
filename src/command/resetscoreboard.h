#include "../ADT/setV2.h"
#include "../ADT/mesinkata.h"

#ifndef RESETSCOREBOARD_H
#define RESETSCOREBOARD_H


/*
Prosedur Menampilkan daftar scoreboard dan meminta masukan berupa nomor
scoreboard yang ingin di-reset.
Reset dilakukan dengan memanggil prosedur lain (RSB) sesuai dengan nomor yang dimasukkan.
*/
void reset_scoreboard(Set *SB);

/*
Prosedur untuk menghapus (reset) semua informasi
pada scoreboard setiap permainan atau salah satu permainan.
*/
void RSB(char *game, MapV2 *SBGame, boolean isALL, Word answer);

#endif
