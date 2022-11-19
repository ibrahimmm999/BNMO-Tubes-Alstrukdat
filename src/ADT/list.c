#include <stdio.h>

#include "list.h"

List MakeList()
{
    List L;
    int i;
    for (i = 0; i < MaxEl; i++)
    {
        L.A[i] = Mark;
    }
    return L;
}

/* boolean IsEmpty(List L)
{
    return (L.A[0] == Mark);
} */


EllType Get(List L, IdxType i)
{
    return (L.A[i]);
}

void Set(List *L, IdxType i, EllType v)
{
    (*L).A[i] = v;
}

int Length(List L)
{
    int i;
    int len = 0;
    for (i = 0; i < MaxEl; i++)
    {
        if (L.A[i] != Mark)
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
    while (L.A[i - 1] == Mark)
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

boolean Search(List L, EllType X)
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
void InsertFirst(List *L, EllType X)
{
    InsertAt(L, X, 0);
}

void InsertAt(List *L, EllType X, IdxType i)
{
    int j;
    if (Length(*L) < MaxEl)
    {
        for (j = Length(*L); j > i; j--)
        {
            (*L).A[j] = (*L).A[j - 1];
        }
        (*L).A[i] = X;
    }
}

void InsertLast(List *L, EllType X)
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
    (*L).A[Length(*L)] = Mark;
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