#include "stackV2.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(StackW *S){
    (*S).TOP = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(StackW S){
    return (S).TOP == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(StackW S){
    return (S).TOP == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(StackW * S, Word X){
    /* Kamus */
    int i = 0;
    /* Algoritma */
    (*S).TOP++;
    (*S).T[(*S).TOP].Length = 0;
    while(i < X.Length)
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
void PopStack(StackW * S, Word * X){
    /* Kamus */
    int i = 0;
    /* Algoritma */
    if(!IsStackEmpty(*S))
    {
        (*X).Length = 0;
        while(i < (*S).T[(*S).TOP].Length)
        {
            (*X).TabWord[i] = (*S).T[(*S).TOP].TabWord[i];
            (*X).Length++;
            i++;
        }
        (*S).TOP--;
    }
}

int lengthStack(StackW S){
    if (!IsStackEmpty(S)){
        return (S).TOP + 1;
    }
    else{
        return 0;
    }
}

void ReverseStack (StackW S, StackW * reserved)
{
    Word info;
    int i = 0;
    int len = lengthStack(S);
    if(!IsStackEmpty(S))
    {
        while(i < len)
        {
            PopStack(&S, &info);
            PushStack(reserved, info);
            i++;
        }
    }
}

void CopyStack (StackW S, StackW *copied)
{
    StackW reversed;
    CreateEmptyStack(&reversed);
    ReverseStack(S, &reversed);
    ReverseStack(reversed, copied);
}

void CetakStack (StackW S, int n)
{   
    StackW copied;
    Word info;
    CreateEmptyStack(&copied);
    CopyStack(S, &copied);
    int i = 0;
    int pjg, j;
    if(n > lengthStack(S))
    {
        n = lengthStack(S);
    }
    while(i < n)
    {
        printf("%d. ", i + 1);
        pjg = copied.T[copied.TOP].Length;
        j = 0;
        while(j < pjg)
        {
            printf("%c", copied.T[copied.TOP].TabWord[j]);
            j++;
        }
        PopStack(&copied, &info);
        i++;
        printf("\n");
    }
}

void PopAllStack(StackW *S)
{
    int len = lengthStack(*S);
    int i = 0;
    Word X;

    while(i < len)
    {
        PopStack(S, &X);
        i++;
    }
}