#include <stdio.h>

#include "listV2.h"

List MakeList()
{
    List L;
    int i;
    for (i = 0; i < MaxEl; i++)
    {
        L.A[i].TabWord[0] = Mark;
        L.A[i].Length = 1;
    }
    return L;
}

boolean IsBlank(List L)
{
    return (L.A[0].TabWord[0] == Mark);
}

ElType Get(List L, IdxType i)
{
    return (L.A[i]);
}

void Set(List *L, IdxType i, ElType v)
{
    int j; 
    for(j = 0; j < v.Length; j++)
    {
        (*L).A[i].TabWord[j] = v.TabWord[j];
        (*L).A[i].Length++;
    }
}

int Length(List L)
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

IdxType FirstIdx(List L)
{
    return 0;
}

IdxType LastIdx(List L)
{
    int i = MaxEl;
    while (L.A[i - 1].TabWord[0] == Mark)
    {
        i--;
    }
    return i - 1;
}
/*
boolean IsIdxValid(List L, IdxType i)
{
    return (i >= 0 && i <= (MaxEl - 1));
}

boolean IsIdxEff(List L, IdxType i)
{
    return (i >= 0 && i <= LastIdx(L));
}

boolean Search(List L, ElType X)
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
void InsertFirst(List *L, ElType X)
{
    InsertAt(L, X, 0);
}

void InsertAt(List *L, ElType X, IdxType i)
{
    int j, k;
    if (Length(*L) < MaxEl)
    {
        for (j = Length(*L); j > i; j--)
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

void InsertLast(List *L, ElType X)
{
    InsertAt(L, X, LastIdx(*L) + 1);
}

void DeleteFirst(List *L)
{
    DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i)
{
    int j;
    for (j = i; j < Length(*L); j++)
    {
        (*L).A[j] = (*L).A[j + 1];
    }
    (*L).A[Length(*L)].TabWord[0] = Mark;
    (*L).A[Length(*L)].Length = 0;
}

void DeleteLast(List *L)
{
    DeleteAt(L, LastIdx(*L));
}

/*
List Concat(List L1, List L2)
{
    List L3 = MakeList();
    int i;
    for (i = 0; i < Length(L1); i++)
    {
        L3.A[i] = L1.A[i];
    }
    for (i = 0; i < Length(L2); i++)
    {
        L3.A[i + Length(L1)] = L2.A[i];
    }
    return L3;
}
*/

void CetakList(List L)
{
    int i, j;
    for(i = 0; i < Length(L); i++)
    {
        printf("%d. ", i+1);
        for(j = 0; j < L.A[i].Length; j++)
        {
            printf("%c", L.A[i].TabWord[j]);
        }
        printf("\n");
    }
}