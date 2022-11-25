#include <stdio.h>
#include <stdlib.h>

#include "listlinier.h"

boolean IsEmpty(List L)
{
    return (L.First == Nil);
}

void CreateEmpty(List *L)
{
    (*L).First = Nil;
}

address Alokasi(infotype x, infotype y)
{
    ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        P->x = x;
        P->y = y;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi(address *P)
{
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X, infotype Y)
{
    address result = Nil;
    if (!IsEmpty(L))
    {
        address P = First(L);
        boolean cek = false;
        while (P != Nil && !cek)
        {
            if (P->x == X && P->y == Y)
            {
                cek = true;
                result = P;
            }
            else
            {
                P = Next(P);
            }
        }
    }
    return result;
}

int IndexOf(List L, infotype X, infotype Y)
{
    address result = Nil;
    int index = -1;
    if (!IsEmpty(L))
    {
        address P = First(L);
        boolean cek = false;
        while (P != Nil && !cek)
        {
            if (P->x == X && P->y == Y)
            {
                cek = true;
                result = P;
            }
            else
            {
                P = Next(P);
            }
            index++;
        }
    }
    if (result == Nil)
    {
        return -1;
    }
    else
    {
        return index;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X, infotype Y)
{
    address addr = Alokasi(X, Y);
    if (addr != Nil)
    {
        InsertFirst(L, addr);
    }
}
void InsVLast(List *L, infotype X, infotype Y)
{
    address addr = Alokasi(X, Y);
    if (addr != Nil)
    {
        InsertLast(L, addr);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X, infotype *Y)
{
    address result;
    DelFirst(L, &result);
    *X = X(result);
    *Y = Y(result);
    Dealokasi(&result);
}
void DelVLast(List *L, infotype *X, infotype *Y)
{
    address result;
    DelLast(L, &result);
    *X = X(result);
    *Y = Y(result);
    Dealokasi(&result);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, address P)
{
    if (IsEmpty(*L))
    {
        Next(P) = Nil;
        First(*L) = P;
    }
    else
    {
        address x = First(*L);
        while (Next(x) != Nil)
        {
            x = Next(x);
        }
        InsertAfter(L, P, x);
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    *P = First(*L);
    if (Next(*P) == Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}
void DelP(List *L, infotype X, infotype Y)
{
    address P = Search(*L, X, Y);
    if (P != Nil)
    {
        address addr = First(*L);
        address prec = Nil;
        address x;
        boolean found = (X(addr) == X && Y(addr) == Y);
        if (found)
        {
            DelFirst(L, &P);
        }
        else
        {
            while (addr != Nil && !found)
            {
                if (X(addr) == X && Y(addr) == Y)
                {
                    found = true;
                    DelAfter(L, &x, prec);
                }
                else
                {
                    prec = addr;
                    addr = Next(addr);
                }
            }
        }
    }
    Dealokasi(&P);
}
void DelLast(List *L, address *P)
{
    address x = First(*L);
    if (Next(x) == Nil)
    {
        *P = First(*L);
        CreateEmpty(L);
    }
    else
    {
        address y = First(*L);
        while (Next(Next(y)) != Nil)
        {
            y = Next(y);
        }
        DelAfter(L, P, y);
    }
}
void DelAfter(List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    if (Next(*Pdel) == Nil)
    {
        Next(Prec) = Nil;
    }
    else
    {
        Next(Prec) = Next(Next(Prec));
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    if (!IsEmpty(L))
    {
        address P = First(L);
        printf("[");
        while (P != Nil)
        {
            if (Next(P) != Nil)
            {
                printf("%d %d,", X(P), Y(P));
            }
            else
            {
                printf("%d %d,", X(P), Y(P));
            }
            P = Next(P);
        }
        printf("]");
    }
    else
    {
        printf("[]");
    }
}
int NbElmt(List L)
{
    int count = 0;
    if (!IsEmpty(L))
    {
        address P = First(L);
        while (P != Nil)
        {
            count += 1;
            P = Next(P);
        }
    }
    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

/****************** PROSES TERHADAP LIST ******************/
void Konkat1(List *L1, List *L2, List *L3)
{
    CreateEmpty(L3);
    address addrFirst = First(*L1);
    address addrSecond = First(*L2);
    if (!IsEmpty(*L1))
    {
        First(*L3) = First(*L1);
        while (Next(addrFirst) != Nil)
        {
            addrFirst = Next(addrFirst);
        }
        Next(addrFirst) = addrSecond;
    }
    else
    {
        First(*L3) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
/****************** PROSES TERHADAP LIST ******************/

void InversList(List *L)
{
    if (NbElmt(*L) > 1)
    {
        address addrFirst = First(*L);
        address P = First(*L);
        address addr1 = Nil;
        address addr2 = Nil;
        while (P != Nil)
        {
            addr2 = Next(P);
            Next(P) = addr1;
            addr1 = P;
            P = addr2;
        }
        First(*L) = addr1;
    }
}

address CopyAddress(address addr)
{
    int a = addr->x;
    int b = addr->y;
    address p = Alokasi(a, b);
    return p;
}