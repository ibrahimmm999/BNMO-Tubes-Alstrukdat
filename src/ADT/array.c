#include <stdio.h>

#include "array.h"
#include "mesinkata.h"

void MakeEmpty(Arr *T)
{
    (*T).Neff = 0;
}

int NbElmt(Arr T)
{
    return T.Neff;
}

int MaxNbEl(Arr T)
{
    return IdxMax;
}

IdxType GetFirstIdx(Arr T)
{
    return IdxMin;
}

IdxType GetLastIdx(Arr T)
{
    return T.Neff;
}

ElType GetElmt(Arr T, IdxType i)
{
    return T.A[i];
}

void SetEl(Arr *T, IdxType i, ElType v)
{
    int j;
    (*T).A[i].Length = v.Length;
    for (j = 0; j < v.Length; j++)
    {
        (*T).A[i].TabWord[j] = v.TabWord[j];
        // printf("%c", (*T).A[i].TabWord[j]);
    }
    SetNeff(T, (*T).Neff + 1);
    // printf("\n %d\n", (*T).Neff);
}

void SetNeff(Arr *T, IdxType N)
{
    (*T).Neff = N;
}

boolean IsIdxValid(Arr T, IdxType i)
{
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(Arr T, IdxType i)
{
    return (i >= IdxMin && i <= T.Neff);
}

boolean IsEmpty(Arr T)
{
    return (T.Neff == 0);
}

boolean IsFull(Arr T)
{
    return T.Neff == IdxMax;
}

void TulisIsi(Arr T)
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong\n");
    }
    else
    {
        int i;
        for (i = 0; i < T.Neff; i++)
        {
            // printf("%s", T.A[i].TabWord);

            printf("%d. ", i + 1);
            int j;
            for (j = 0; j < T.A[i].Length; j++)
            {
                printf("%c", T.A[i].TabWord[j]);
            }

            printf("\n");
        }
    }
}
