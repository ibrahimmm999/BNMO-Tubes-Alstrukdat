#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
{
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
{
    return Top(S) == NilStack;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S)
{
    return Top(S) == MaxElStack - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack *S, infotypestack X)
{
    if (!IsStackEmpty(*S))
    {
        Top(*S) = Top(*S) + 1;
        InfoTop(*S) = X;
    }
    else
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, infotypestack *X)
{
    (*X) = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}

int lengthStack(Stack S)
{
    if (!IsStackEmpty(S))
    {
        return Top(S) + 1;
    }
    else
    {
        return 0;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */