#ifndef mapV2_H
#define mapV2_H
#include <stdio.h>
#include "../boolean.h"

#define NilMapV2 0
#define MaxElMapV2 30
#define Undefined -999

typedef int keytypeV2;
typedef int addressMapV2;

typedef struct
{
        char *name;
        int score;
} valuetypeMapV2;

typedef struct
{
        keytypeV2 Key;
        valuetypeMapV2 Value;
} infotypeMapV2;

typedef struct
{
        infotypeMapV2 Elements[MaxElMapV2];
        addressMapV2 Count;
} MapV2;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMapV2(MapV2 *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmptyV2(MapV2 M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapFullV2(MapV2 M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetypeMapV2 ValueMapV2(MapV2 M, keytypeV2 k);
/* Mengembalikan nilai value dengan key k pada M */

char *VName(MapV2 M, keytypeV2 k);
/* Mengembalikan nilai value name dengan key k pada M */
/* Jika tidak ada key k pada M, akan mengembalikan string kosong ("") */

int VScore(MapV2 M, keytypeV2 k);
/* Mengembalikan nilai value score dengan key k pada M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMapV2(MapV2 *M, keytypeV2 k, valuetypeMapV2 v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMapV2(MapV2 *M, keytypeV2 k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMapV2(MapV2 M, keytypeV2 k);
/* Mengembalikan true jika k adalah member dari M */

boolean NameExist(MapV2 M, char *name);
/* Mengembalikan true jika nama adalah member dari M */

#endif
