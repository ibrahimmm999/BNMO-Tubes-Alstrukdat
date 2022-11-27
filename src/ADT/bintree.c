#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

#define max(a, b) a>b?a:b

BinTree Tree (Word Akar, BinTree L, BinTree R){
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    BinTree P;
    P = (BinTree)malloc(sizeof(BinTree));
    if(P != Nil)
    {
        int i = 0;
        int len = Akar.Length;
        (*P).info.Length = 0;
        while(i < len)
        {
            (*P).info.TabWord[i] = Akar.TabWord[i];
            (*P).info.Length++;
            i++;
        }
        Left(P) = L;
        Right(P) = R;
    }
  return P;
}

void MakeTree (Word Akar, BinTree L, BinTree R, BinTree *P){
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
    *P = (BinTree)malloc(sizeof(BinTree));
    if(P != Nil)
    {
        int i = 0;
        int len = Akar.Length;
        (*P)->info.Length = 0;
        while(i < len)
        {
            (*P)->info.TabWord[i] = Akar.TabWord[i];
            (*P)->info.Length++;
            i++;
        }
        Left(*P) = L;
        Right(*P) = R;
    }
}

addrNode AlokNode (Word X){
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    addrNode P;
    P = (addrNode) malloc(sizeof(Node));
    if (P != Nil)
    {
        int i = 0;
        int len = X.Length;
        (*P).info.Length = 0;
        while(i < len)
        {
            (*P).info.TabWord[i] = X.TabWord[i];
            (*P).info.Length++;
            i++;
        }
        Left(P) = Nil;
        Right(P)= Nil;
    }
    return P;
}

void DealokNode (addrNode P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
    free(P);
}

boolean IsTreeEmpty (BinTree P){
/* Mengirimkan true jika P adalah pohon biner kosong */
    return P == Nil;
}

boolean IsTreeOneElmt (BinTree P){
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    return !IsTreeEmpty(P) && (Left(P) == Nil) && (Right(P) == Nil);
}

boolean IsUnerLeft (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else 
    {
        return Left(P) != Nil && Right(P) == Nil;
    }
}

boolean IsUnerRight (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        return Left(P) == Nil && Right(P) != Nil;
    }
}

boolean IsBiner (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        return Left(P) != Nil && Right(P) != Nil;
    }
}

void PrintPreorder (BinTree P){
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        int i = 0;
        int len = (*P).info.Length;
        while(i < len)
        {
            printf("%c", (*P).info.TabWord[i]);
            i++;
        }
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
    }
}

boolean SearchTree (BinTree P, Word X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
    char arrx[100];
    int i, len;
    len = 0;
    for(i = 0; i < X.Length; i++)
    {
        arrx[i] = X.TabWord[i];
        len++;
    }
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if(IsWordEqual((P)->info, arrx))
        {
            return true;
        }
        else
        {
            if (SearchTree(Left(P), X)) return true;
            else return (SearchTree(Right(P), X));
        }
    }
}

int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if(IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
    }
}

int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if(IsTreeEmpty(P))
    {
        return 0;
    }
    if(IsTreeOneElmt(P))
    {
        return 1;
    }
    else
    {
        if (IsUnerLeft(P))
        {
            return NbDaun(Left(P));
        }
        else if (IsUnerRight(P))
        {
            return NbDaun(Right(P));
        }
        else
        {
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
    }
}

boolean IsSkewLeft (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else if (IsTreeOneElmt(P))
    {
        return true;
    }
    else
    {
        return IsSkewLeft(Left(P)) && (Right(P) == Nil);
    }
}

boolean IsSkewRight (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else if (IsTreeOneElmt(P))
    {
        return true;
    }
    else
    {
        return IsSkewRight(Right(P)) && (Left(P) == Nil);
    }
}

int Level (BinTree P, Word X){
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
    char arrx[100];
    int i;
    
    for(i = 0; i < X.Length; i++)
    {
        arrx[i] = X.TabWord[i];
    }

    if (IsWordEqual(X, arrx))
    {
        return 1;
    }
    else
    {
        if(SearchTree(Left(P), X)) return 1 + Level(Left(P), X);
        else if (SearchTree(Right(P), X)) return 1 + Level(Right(P), X);
    }
}

int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    if(IsTreeEmpty(P)) 
    {
        return 0;
    }
    else
    {
      if (Tinggi(Left(P)) > Tinggi(Right(P)))
      {
        return 1 + Tinggi(Left(P));
      }
      else
      {
        return 1 + Tinggi(Right(P));
      }
    }
}


void AddDaunTerkiri (BinTree *P, Word X){
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
        // *P = Tree(X, Nil, Nil);
    }
    else
    {
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun (BinTree *P, Word X, Word Y, boolean Kiri){
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
    char arrx[100];
    int i;

    for(i = 0; i < X.Length; i++)
    {
        arrx[i] = X.TabWord[i];
    }
    if (IsTreeOneElmt(*P) && IsWordEqual(X, arrx))
    {
        if (Kiri)
        {
            Left(*P) = Tree(Y, Nil, Nil);
        }
        else
        {
            Right(*P) = Tree(Y, Nil, Nil);
        }
    }
    else
    {
        if (SearchTree(Left(*P), X))
        {
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else
        {
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri (BinTree *P, Word *X){
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
  if(IsTreeOneElmt(*P))
  {
    int i = 0;
    (*X).Length = 0;
    while (i < (*P)->info.Length)
    {
        (*X).TabWord[i] = (*P)->info.TabWord[i];
        (*X).Length++;
        i++;
    }
    addrNode del = *P;
    *P = Nil;
    DealokNode(del); 
  }
  else
  {
    if(Left(*P)!=Nil) DelDaunTerkiri(&Left(*P), X);
    else DelDaunTerkiri(&Right(*P), X);
  }
}

void DelDaun (BinTree *P, Word X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    char arrx[100];
    int i;

    for(i = 0; i < X.Length; i++)
    {
        arrx[i] = X.TabWord[i];
    }
    if (!IsTreeEmpty(*P))
    {
        if (IsTreeOneElmt(*P) && (IsWordEqual(X, arrx)))
        {
            (*P) = Nil;
            DealokNode(*P);
        }
        else
        {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}