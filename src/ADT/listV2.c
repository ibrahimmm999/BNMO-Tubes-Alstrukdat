
#include <stdio.h>

#include "ListV2.h"

ListV2 MakeListV2()
{
    ListV2 L;
    int i;
    for (i = 0; i < MaxEl; i++)
    {
        L.A[i].TabWord[0] = Mark;
        L.A[i].Length = 1;
    }
    return L;
}

boolean IsBlank(ListV2 L)
{
    return (L.A[0].TabWord[0] == Mark);
}

ElType GetV2(ListV2 L, IdxType i)
{
    return (L.A[i]);
}

void SetV2(ListV2 *L, IdxType i, ElType v)
{
    int j; 
    for(j = 0; j < v.Length; j++)
    {
        (*L).A[i].TabWord[j] = v.TabWord[j];
        (*L).A[i].Length++;
    }
}

int LengthV2(ListV2 L)
{
    int i;
    int len = 0;
    for (i = 0; i < MaxEl; i++)
    {
        if (L.A[i].TabWord[0] != Mark)
        {
            len++;
        }
    }
    return len;
}

IdxType FirstIdxV2(ListV2 L)
{
    return 0;
}

IdxType LastIdxV2(ListV2 L)
{
    int i = MaxEl;
    while (L.A[i - 1].TabWord[0] == Mark)
    {
        i--;
    }
    return i - 1;
}
/*
boolean IsIdxValid(ListV2 L, IdxType i)
{
    return (i >= 0 && i <= (MaxEl - 1));
}

boolean IsIdxEff(ListV2 L, IdxType i)
{
    return (i >= 0 && i <= LastIdx(L));
}

boolean Search(ListV2 L, ElType X)
{
    int i;
    boolean cond = false;
    for (i = FirstIdx(L); i <= LastIdx(L); i++)
    {
        if (L.A[i] == X)
        {
            cond = true;
        }
    }
    return cond;
}

*/
void InsertFirstV2(ListV2 *L, ElType X)
{
    InsertAtV2(L, X, 0);
}

void InsertAtV2(ListV2 *L, ElType X, IdxType i)
{
    int j, k;
    if (LengthV2(*L) < MaxEl)
    {
        for (j = LengthV2(*L); j > i; j--)
        {
            (*L).A[j] = (*L).A[j - 1];
        }
        for (k = 0; k < X.Length; k++)
        {
            (*L).A[i].TabWord[k] = X.TabWord[k];
            (*L).A[i].Length++;
        }
    }
}

void InsertLastV2(ListV2 *L, ElType X)
{
    InsertAtV2(L, X, LastIdxV2(*L) + 1);
}

void DeleteFirstV2(ListV2 *L)
{
    DeleteAtV2(L, 0);
}

void DeleteAtV2(ListV2 *L, IdxType i)
{
    int j;
    for (j = i; j < LengthV2(*L); j++)
    {
        (*L).A[j] = (*L).A[j + 1];
    }
    (*L).A[LengthV2(*L)].TabWord[0] = Mark;
    (*L).A[LengthV2(*L)].Length = 0;
}

void DeleteLastV2(ListV2 *L)
{
    DeleteAtV2(L, LastIdxV2(*L));
}

void DeleteAll(ListV2 *L)
{
    /* Kamus */
    int i;
    int lastIdx = LastIdxV2(*L);
    /* Algoritma */
    for(i = 0; i <= lastIdx; i++)
    {
        DeleteFirstV2(L);
    }
}
/*
ListV2 Concat(ListV2 L1, ListV2 L2)
{
    ListV2 L3 = MakeListV2();
    int i;
    for (i = 0; i < LengthV2(L1); i++)
    {
        L3.A[i] = L1.A[i];
    }
    for (i = 0; i < LengthV2(L2); i++)
    {
        L3.A[i + LengthV2(L1)] = L2.A[i];
    }
    return L3;
}
*/

void CetakList(ListV2 L, IdxType untilIdx)
{
    int i, j;
    for(i = 0; i < untilIdx; i++)
    {
        if(i < LengthV2(L))
        {
            printf("%d. ", i+1);
            for(j = 0; j < L.A[i].Length; j++)
            {
                printf("%c", L.A[i].TabWord[j]);
            }
            printf("\n");
        }    
    }
}