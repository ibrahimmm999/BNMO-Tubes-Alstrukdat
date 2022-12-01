#include "stackV2.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackV2(StackW *S)
{
    (*S).TOP = NilStackV2;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmptyV2(StackW S)
{
    return (S).TOP == NilStackV2;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFullV2(StackW S)
{
    return (S).TOP == MaxElStackV2 - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackV2(StackW *S, Word X)
{
    /* Kamus */
    int i = 0;
    /* Algoritma */
    (*S).TOP++;
    (*S).T[(*S).TOP].Length = 0;
    while (i < X.Length)
    {
        (*S).T[(*S).TOP].TabWord[i] = X.TabWord[i];
        (*S).T[(*S).TOP].Length++;
        i++;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackV2(StackW *S, Word *X)
{
    /* Kamus */
    int i = 0;
    /* Algoritma */
    if (!IsStackEmptyV2(*S))
    {
        (*X).Length = 0;
        while (i < (*S).T[(*S).TOP].Length)
        {
            (*X).TabWord[i] = (*S).T[(*S).TOP].TabWord[i];
            (*X).Length++;
            i++;
        }
        (*S).TOP--;
    }
}

int lengthStackV2(StackW S)
{
    if (!IsStackEmptyV2(S))
    {
        return (S).TOP + 1;
    }
    else
    {
        return 0;
    }
}

void ReverseStack(StackW S, StackW *reserved)
{
    Word info;
    int i = 0;
    int len = lengthStackV2(S);
    if (!IsStackEmptyV2(S))
    {
        while (i < len)
        {
            PopStackV2(&S, &info);
            PushStackV2(reserved, info);
            i++;
        }
    }
}

void CopyStack(StackW S, StackW *copied)
{
    StackW reversed;
    CreateEmptyStackV2(&reversed);
    ReverseStack(S, &reversed);
    ReverseStack(reversed, copied);
}

void CetakStack(StackW S, int n)
{
    StackW copied;
    Word info;
    CreateEmptyStackV2(&copied);
    CopyStack(S, &copied);
    int i = 0;
    int pjg, j;
    if (n > lengthStackV2(S))
    {
        n = lengthStackV2(S);
    }
    while (i < n)
    {
        printf("%d. ", i + 1);
        pjg = copied.T[copied.TOP].Length;
        j = 0;
        while (j < pjg)
        {
            printf("%c", copied.T[copied.TOP].TabWord[j]);
            j++;
        }
        PopStackV2(&copied, &info);
        i++;
        printf("\n");
    }
}

void PopAllStack(StackW *S)
{
    int len = lengthStackV2(*S);
    int i = 0;
    Word X;

    while (i < len)
    {
        PopStackV2(S, &X);
        i++;
    }
}