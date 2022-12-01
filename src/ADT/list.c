#include <stdio.h>

#include "list.h"

List MakeList()
{
    List L;
    int i;
    for (i = 0; i < MaxElList; i++)
    {
        L.A[i] = MarkList;
    }
    return L;
}

/* boolean IsEmpty(List L)
{
    return (L.A[0] == MarkList);
} */

ElTypeList GetElList(List L, IdxTypeList i)
{
    return (L.A[i]);
}

void SetElList(List *L, IdxTypeList i, ElTypeList v)
{
    (*L).A[i] = v;
}

int LengthList(List L)
{
    int i;
    int len = 0;
    for (i = 0; i < MaxElList; i++)
    {
        if (L.A[i] != MarkList)
        {
            len++;
        }
    }
    return len;
}

IdxTypeList FirstIdx(List L)
{
    return 0;
}

IdxTypeList LastIdx(List L)
{
    int i = MaxElList;
    while (L.A[i - 1] == MarkList)
    {
        i--;
    }
    return i - 1;
}
/*
boolean IsIdxValid(List L, IdxTypeList i)
{
    return (i >= 0 && i <= (MaxElList - 1));
}

boolean IsIdxEff(List L, IdxTypeList i)
{
    return (i >= 0 && i <= LastIdx(L));
}

boolean Search(List L, ElTypeList X)
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
void InsertFirstList(List *L, ElTypeList X)
{
    InsertAtList(L, X, 0);
}

void InsertAtList(List *L, ElTypeList X, IdxTypeList i)
{
    int j;
    if (LengthList(*L) < MaxElList)
    {
        for (j = LengthList(*L); j > i; j--)
        {
            (*L).A[j] = (*L).A[j - 1];
        }
        (*L).A[i] = X;
    }
}

void InsertLastList(List *L, ElTypeList X)
{
    InsertAtList(L, X, LastIdx(*L) + 1);
}

void ElListDeleteFirstList(List *L)
{
    DeleteAtList(L, 0);
}

void DeleteAtList(List *L, IdxTypeList i)
{
    int j;
    for (j = i; j < LengthList(*L); j++)
    {
        (*L).A[j] = (*L).A[j + 1];
    }
    (*L).A[LengthList(*L)] = MarkList;
}

void DeleteLastList(List *L)
{
    DeleteAtList(L, LastIdx(*L));
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