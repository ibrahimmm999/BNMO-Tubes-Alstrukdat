#ifndef setV2_H
#define setV2_H
#include <stdio.h>
#include "../boolean.h"
#include "mapV2.h"

/* MODUL Set
ADT Set berisi elemen berupa tipe bentukan nama game dan Map (Scoreboard game)
Digunakan untuk implementasi scoreboard dan reset scoreboard
*/

#define NilSetV2 0
#define MaxElsetV2 30

typedef int addressSetV2;
typedef struct
{
        char *game;
        MapV2 M;
} infotypeSetV2;

typedef struct
{
        infotypeSetV2 Elements[MaxElsetV2];
        addressSetV2 Count;
} SetV2;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(SetV2 *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(SetV2 S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(SetV2 S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSetV2(SetV2 *S, infotypeSetV2 Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetV2(SetV2 *S, char *game);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberOfSet(SetV2 S, char *game);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif