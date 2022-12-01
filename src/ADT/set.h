#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean.h"
#include "mesinkata.h"

#define NilSet 0
#define MaxElSet 100

typedef Word infotype;
typedef int address;

typedef struct
{
        infotype Elements[MaxElSet];
        address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
void CreateSet(Set *S);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
boolean IsSetEmpty(Set S);

/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
boolean IsSetFull(Set S);

/* ********** Operator Dasar Set ********* */

/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
void InsertElSet(Set *S, infotype Elmt);

/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
void DeleteElSet(Set *S, infotype Elmt);

/* Mengembalikan true jika Elmt adalah member dari S */
boolean IsMemberSet(Set S, infotype Elmt);

/* Menulis isi set secara menyamping*/
void TulisIsiSet(Set S);

#endif