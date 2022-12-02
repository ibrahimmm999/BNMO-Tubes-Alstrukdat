#include <stdio.h>

#include "list.h"

int main()
{
    List testList = MakeList();
    Set(&testList, 0, 't');
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
    }

    return 0;
}