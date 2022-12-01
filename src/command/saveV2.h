#include "../ADT/array.h"
#include "../ADT/stackV2.h"
#include "../ADT/mapV2.h"

#ifndef SAVEV2_H
#define SAVEV2_H

/*
Prosedur untuk menyimpan state game (list game, history, scoreboard yang dimiliki sistem)
I.S. game belum disimpan
F.S. state game disimpan pada suatu file. Jika file sudah ada sebelumnya, make file akan dioverwrite
*/
void save(char *file_name, Arr list_game, StackW history, Map SBrng, Map SBdd, Map SBhm, Map SBtoh, Map SBsom);

/*
Prosedur simpan scoreboard ke dalam file
*/
void SaveSB(Map SBGame, FILE *fp);

#endif
