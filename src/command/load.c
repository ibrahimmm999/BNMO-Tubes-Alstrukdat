#include "start.h"

void LOAD(char *savefile, Arr *arrgame)
{
    MakeEmpty(arrgame);
    STARTWORD(savefile);

    int i;
    int lenOfArr = currentWord.TabWord[0] - 48;

    ADVWORD();
    int temp = 0;
    for (i = 0; i < lenOfArr; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        SetEl(arrgame, i, currentWord);
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
