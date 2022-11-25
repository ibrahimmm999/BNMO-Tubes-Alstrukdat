#include "start.h"
#include "loadV2.h"

void LOAD(char *savefile, Arr *arrgame, ListV2 *history)
{
    MakeEmpty(arrgame);
    *history = MakeListV2();
    STARTWORD(savefile);

    int i;
    int lenOfArr = currentWord.TabWord[0] - 48;
    int lenOfList;

    ADVWORD();
    int temp = 0;
    for (i = 0; i < lenOfArr; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        SetEl(arrgame, i, currentWord);
        ADVWORD();
    }

    lenOfList = currentWord.TabWord[0] - 48;
    ADVWORD();
    for (i = 0; i < lenOfList; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        InsertLastV2(history, currentWord);
        ADVWORD();
    }

    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}
/*
int main()
{
    Arr arrgame;

    LOAD("../data/savefile.txt", &arrgame);
    TulisIsi(arrgame);
}
*/
