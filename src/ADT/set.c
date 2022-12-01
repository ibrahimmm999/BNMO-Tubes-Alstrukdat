#include "set.h"

void CreateSet(Set *S)
{
    (*S).Count = NilSet;
}

boolean IsSetEmpty(Set S)
{
    return S.Count == NilSet;
}

boolean IsSetFull(Set S)
{
    return S.Count == MaxElSet;
}

void InsertElSet(Set *S, infotype Elmt)
{
    if (!IsMemberSet(*S, Elmt))
    {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void DeleteElSet(Set *S, infotype Elmt)
{
    int idx = 0;
    if (IsMemberSet(*S, Elmt))
    {
        for (int i = 0; i < (*S).Count; i++)
        {
            if (IsWordEqual((*S).Elements[i], Elmt.TabWord))
            {
                idx = i;
            }
        }
        for (int j = idx + 1; j < (*S).Count; j++)
        {
            (*S).Elements[j - 1] = (*S).Elements[j];
        }
        (*S).Count--;
    }
}

boolean IsMemberSet(Set S, infotype Elmt)
{
    for (int i = 0; i < S.Count; i++)
    {
        if (IsWordEqual(S.Elements[i], Elmt.TabWord))
        {
            return true;
        }
    }
    return false;
}

void TulisIsiSet(Set S)
{
    if (IsSetEmpty(S))
    {
        printf("-\n");
    }
    else
    {
        for (int i = 0; i < S.Count; i++)
        {
            for (int j = 0; j < S.Elements[i].Length; j++)
            {
                printf("%c", S.Elements[i].TabWord[j]);
            }
        }
        printf("\n");
    }
}