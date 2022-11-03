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

void SetTab(Arr Tin, Arr *Tout)
{
    int i = 0;
    for (i = 0; i < Tin.Neff; i++)
    {
        (*Tout).A[i] = Tin.A[i];
    }
    (*Tout).Neff = Tin.Neff;
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

/*
Arr PlusTab(Arr T1, Arr T2)
{
    Arr T3;
    int i;
    for (i = IdxMin; i <= T1.Neff; i++)
    {
        T3.A[i] = T1.A[i] + T2.A[i];
    }
    T3.Neff = T2.Neff;
    return T3;
}

Arr MinusTab(Arr T1, Arr T2)
{
    Arr T3;
    int i;
    for (i = IdxMin; i <= T1.Neff; i++)
    {
        T3.A[i] = T1.A[i] - T2.A[i];
    }
    T3.Neff = T2.Neff;
    return T3;
}
ElType ValMax(Arr T)
{
    IdxType i = IdxMin;
    ElType max = -99999;

    for (i; i <= NbElmt(T); i++)
    {
        if (T.A[i] > max)
        {
            max = T.A[i];
        }
    }
    return max;
}
ElType ValMin(Arr T)
{
    IdxType i = IdxMin;
    ElType min = 99999;

    for (i; i <= NbElmt(T); i++)
    {
        if (T.A[i] < min)
        {
            min = T.A[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(Arr T)
{
    int i, max, idxmax, curr;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        curr = T.A[i];
        if (i == IdxMin)
        {
            max = curr;
        }
        if (curr > max)
        {
            max = curr;
            idxmax = i;
        }
    }
    return idxmax;
}

IdxType IdxMinTab(Arr T)
{
    int i, min, idxmin, curr;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        curr = T.A[i];
        if (i == IdxMin)
        {
            min = curr;
        }
        if (curr < min)
        {
            min = curr;
            idxmin = i;
        }
    }
    return idxmin;
}
*/