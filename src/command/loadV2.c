#include "start.h"
#include "loadV2.h"

void LOAD(char *savefile, Arr *arrgame, StackW *history)
{
    MakeEmpty(arrgame);
    CreateEmptyStack(history);
    STARTWORD(savefile);

    int i;
    int lenOfArr = currentWord.TabWord[0] - 48;
    int lenOfStack;
    StackW histemp;
    CreateEmptyStack(&histemp);

    ADVWORD();
    int temp = 0;
    for (i = 0; i < lenOfArr; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        SetEl(arrgame, i, currentWord);
        ADVWORD();
    }

    lenOfStack = currentWord.TabWord[0] - 48;
    ADVWORD();
    for (i = 0; i < lenOfStack; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        PushStack(&histemp, currentWord);
        ADVWORD();
    }

    ReverseStack(histemp, history);

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
