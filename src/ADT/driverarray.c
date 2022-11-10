#include "array.h"
#include <stdio.h>

int main()
{
    Arr testArr;
    MakeEmpty(&testArr);
    printf("%d\n", NbElmt(testArr));
    SetNeff(&testArr, 2);
    printf("%d\n", NbElmt(testArr));

    Word gunting;
    gunting.TabWord[0] = 'g';
    gunting.TabWord[1] = 'u';
    gunting.TabWord[2] = 'n';
    gunting.TabWord[3] = 't';
    gunting.TabWord[4] = 'i';
    gunting.TabWord[5] = 'n';
    gunting.TabWord[6] = 'g';
    gunting.Length = 7;

    Word test;
    test.TabWord[0] = 't';
    test.TabWord[1] = 'e';
    test.TabWord[2] = 's';
    test.TabWord[3] = 't';
    test.Length = 4;

    SetEl(&testArr, 0, gunting);
    SetEl(&testArr, 1, test);
    printf("%d\n", MaxNbEl(testArr));
    printf("%d\n", GetFirstIdx(testArr));
    printf("%d\n", GetLastIdx(testArr));
    
    
    Word testGetElmt = GetElmt(testArr, 1);
    printf("%d\n", testGetElmt.Length);
    int i;
    for (i = 0; i < testGetElmt.Length; i++)
    {
        printf("%c", testGetElmt.TabWord[i]);
    }
    printf("\n");

    
    if (IsIdxValid(testArr, 1))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    if (IsIdxEff(testArr, 1))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    if (IsEmpty(testArr))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    if (IsFull(testArr))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    TulisIsi(testArr);

    return 0;
}
