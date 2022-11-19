#include <stdio.h>

#include "listV2.h"

int main()
{
    List testList = MakeList();
    Word X, Y, get, get2, first, last, at;
    int i;

    X.Length = 3;
    X.TabWord[0] = 'I';
    X.TabWord[1] = 'y';
    X.TabWord[2] = 'a';
    Y.Length = 2;
    Y.TabWord[0] = 'G';
    Y.TabWord[1] = 'a';
    first.Length = 5;
    first.TabWord[0] = 'f';
    first.TabWord[1] = 'i';
    first.TabWord[2] = 'r';
    first.TabWord[3] = 's';
    first.TabWord[4] = 't';
    last.Length = 4;
    last.TabWord[0] = 'l';
    last.TabWord[1] = 'a';
    last.TabWord[2] = 's';
    last.TabWord[3] = 't';
    at.Length = 2;
    at.TabWord[0] = 'a';
    at.TabWord[1] = 't';

    if(IsBlank(testList) == 1)
    {
        printf("testList kosong\n");
    }

    Set(&testList, 0, X);
    Set(&testList, 1, Y);

    printf("testList setelah ditambah pada (idx == 0) dan (idx == 1)\n");
    CetakList(testList, Length(testList));

    if(IsBlank(testList) == 0)
    {
        printf("testList tidak kosong\n");
    }

    get = Get(testList, 1);
    get2 = Get(testList, 5);

    printf("Get (idx == 1): ");
    for(i = 0; i < get.Length; i++)
    {
        printf("%c", get.TabWord[i]);
    }

    printf("\nGet (idx == 5): ");
    for(i = 0; i < get2.Length; i++)
    {
        printf("%c", get2.TabWord[i]);
    }

    InsertFirst(&testList, first);
    InsertAt(&testList, at, 3);
    InsertLast(&testList, last);

    printf("\ntestList setelah ditambah di awal, akhir, dan tengah (idx == 3):\n");
    CetakList(testList, Length(testList));
    printf("\nPanjang list: %d", Length(testList));
    printf("\nFirst idx: %d", FirstIdx(testList));
    printf("\nLast idx: %d", LastIdx(testList));

    printf("\ntestList (3 baris): \n");
    CetakList(testList, 3);

    printf("\n");
    printf("\ntestList ('10' baris):\n");
    CetakList(testList, 10);

    DeleteFirst(&testList);
    DeleteLast(&testList);
    DeleteAt(&testList, 1);

    printf("\ntestList setelah dihapus di awal, akhir, dan tengah (idx == 1):\n");
    CetakList(testList, Length(testList));
    printf("\nPanjang list: %d", Length(testList));
    printf("\nFirst idx: %d", FirstIdx(testList));
    printf("\nLast idx: %d", LastIdx(testList));

    /* Set(&testList, 0, 't');
    Set(&testList, 1, 'e');
    Set(&testList, 2, 's');
    Set(&testList, 3, 't');
    int i;
    for (i = 0; i < Length(testList); i++)
    {
        printf("%c", Get(testList, i));
    }
    printf("\n");
    printf("%d\n", FirstIdx(testList));
    printf("%d\n", LastIdx(testList));
    InsertFirst(&testList, 'A');
    InsertAt(&testList, 'P', 2);
    InsertLast(&testList, 'X');
    for (i = 0; i < Length(testList); i++)
    {
        printf("%c", Get(testList, i));
    }
    printf("\n");
    DeleteFirst(&testList);
    DeleteAt(&testList, 1);
    DeleteLast(&testList);
    for (i = 0; i < Length(testList); i++)
    {
        printf("%c", Get(testList, i));
    } */
}
