#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsLDPEmpty(ListDP L)
{
    return (First(L) == NilLDP && Last(L) == NilLDP);
}

void CreateEmpty(ListDP *L)
{
    First(*L) = NilLDP;
    Last(*L) = NilLDP;
}
addressLDP Alokasi(infotypeLdp X, POINT Y)
{
    addressLDP P = (addressLDP)malloc(sizeof(ElmtListDP));
    if (P != NilLDP)
    {
        Info(P) = X;
        Next(P) = NilLDP;
        Prev(P) = NilLDP;
        Pos(P) = Y;
    }
    return P;
}

void Dealokasi(addressLDP P)
{
    free(P);
}

addressLDP Search(ListDP L, POINT Y)
{
    addressLDP P = First(L);
    boolean ada = false;
    while (P != NilLDP && !ada)
    {
        if (Pos(P).x == Y.x && Pos(P).y == Y.y)
        {
            ada = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if (ada)
    {
        return P;
    }
    else
    {
        return NilLDP;
    }
}

void InsVLast(ListDP *L, infotypeLdp X, POINT Y)
{
    addressLDP P = Alokasi(X, Y);
    if (P != NilLDP)
    {
        if (!IsLDPEmpty(*L))
        {
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
        else
        {
            First(*L) = P;
            Last(*L) = P;
        }
    }
}

void DelFirst(ListDP *L, addressLDP *P)
{
    *P = First(*L);
    if (Next(*P) == NilLDP)
    {
        First(*L) = NilLDP;
        Last(*L) = NilLDP;
    }
    else
    {
        First(*L) = Next(*P);
        Prev(Next(*P)) = NilLDP;
    }
}

void DelLast(ListDP *L, addressLDP *P)
{
    *P = Last(*L);
    if (Prev(*P) == NilLDP)
    {
        First(*L) = NilLDP;
        Last(*L) = NilLDP;
    }
    else
    {
        Last(*L) = Prev(*P);
        Next(Prev(*P)) = NilLDP;
    }
}

void DelP(ListDP *L, POINT X)
{
    addressLDP P = Search(*L, X);
    if (P != NilLDP)
    {
        if (Prev(P) == NilLDP)
        {
            DelFirst(L, &P);
        }
        else if (Next(P) == NilLDP)
        {
            DelLast(L, &P);
        }
        else
        {
            addressLDP Q = Last(*L);
            addressLDP R;
            while (Q != P)
            {

                R = Prev(Q);
                Info(Q) = Info(R);
                if (R->prev->pos.x == X.x && R->prev->pos.y == X.y)
                {
                    Pos(Q).x = Pos(R).x;
                    Pos(Q).y = Pos(R).y;
                }
                Q = Prev(Q);
            }
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        }
        Dealokasi(P);
    }
}

void PrintForward(ListDP L)
{
    addressLDP P = First(L);
    if (IsLDPEmpty(L))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while (P != NilLDP)
        {
            if (P != Last(L))
            {
                printf("%d %d,", P->pos.x, P->pos.y);
            }
            else
            {
                printf("%d %d", P->pos.x, P->pos.y);
            }
            P = Next(P);
        }
        printf("]");
    }
}

void PrintBackward(ListDP L)
{
    addressLDP P = Last(L);
    if (IsLDPEmpty(L))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while (P != NilLDP)
        {
            if (P != First(L))
            {
                printf("%d,", Info(P));
            }
            else
            {
                printf("%d", Info(P));
            }
            P = Prev(P);
        }
        printf("]");
    }
}

POINT GetLastPos(ListDP L)
{
    return Pos(Last(L));
}
