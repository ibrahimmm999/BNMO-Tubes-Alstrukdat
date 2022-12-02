#include "../ADT/setV2.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

/*
Prosedur untuk menuliskan spasi sebanyak n kali ke layar.
*/
void PrintSpace(int n);

/*
Prosedur untuk menampilkan nama dan skor untuk semua game.
Urutan scoreboard game yang ditampilkan mengikuti urutan pada List Game.
Urutan nama pada scoreboard diurutkan berdasarkan skor (descending).
Pre-kondisi : Map Scoreboard sudah terurut berdasarkan skor.
*/
void PrintSB(char *game, MapV2 SBGame);

/*
Prosedur untuk memanggil prosedur yang menampilkan nama dan skor untuk semua game.
*/
void scoreboard(Set SB);

/*
Prosedur memasukkan/menyimpan nama dan skor pemain yang telah
mencapai kondisi menang atau game over ke dalam Map Scoreboard suatu game (SBGame).
Jika nama sudah ada dalam scoreboard, maka proses insert tidak dilakukan.
I.S. Map Scoreboard terdefinisi dan mungkin kosong.
    Jika tidak kosong, scoreboard sudah terurut dari skor paling besar
    ke skor paling kecil. Nama dan skor milik pemain bukan anggota dari Map.
F.S. Nama dan skor milik pemain adalah anggota dari Map.
    Scoreboard tetap terurut secara descending seperti kondisi awal.
*/
void InsertScoreboard (char *nama, int skor, MapV2 *SBGame);

/*
Prosedur membuat Scoreboard Game (Map) baru di dalam sebuah Set of Scoreboards
Jika game sudah terdaftar dalam set, maka proses tidak dilakukan
*/
void CreateScoreboard (Set *SB, char* game);

/*
Prosedur menghapus scoreboard dari daftar scoreboard.
Scoreboard yang dapat dihapus hanya scoreboard game buatan pemain.
*/
void DeleteScoreboard (Set *SB, char *game);

/*
Prosedur menampilkan nama-nama pemain yang terdaftar pada scoreboard suatu game.
*/
void ShowNamesSB(MapV2 SBGame);

#endif
