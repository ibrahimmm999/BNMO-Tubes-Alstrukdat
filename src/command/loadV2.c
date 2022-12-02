#include "start.h"
#include "loadV2.h"

void LOAD(char *savefile, Arr *arrgame, StackW *history, SetV2 *SB)
{
    MakeEmpty(arrgame);
    CreateEmptyStackV2(history);
    CreateEmptySet(SB);
    STARTWORD(savefile);

    int i;
    // int lenOfArr = currentWord.TabWord[0] - 48;
    int lenOfArr = WordToInt(currentWord);
    int lenOfStack;
    StackW histemp;
    CreateEmptyStackV2(&histemp);
    ADVWORD();
    int temp = 0;
    for (i = 0; i < lenOfArr; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        SetEl(arrgame, i, currentWord);
        ADVWORD();
    }

    lenOfStack = WordToInt(currentWord);
    // lenOfStack = currentWord.TabWord[0] - 48;
    ADVWORD();
    for (i = 0; i < lenOfStack; i++)
    {
        // printf("%s\n", currentWord.TabWord);
        PushStackV2(&histemp, currentWord);
        ADVWORD();
    }

    ReverseStack(histemp, history);
    int j;
    // printf("\ncurrent : %s\n", wordToString(currentWord, false));
    for (i = 0; i < lenOfArr; i++)
    {
        MapV2 currentGame;
        CreateEmptyMapV2(&currentGame);
        int count = WordToInt(currentWord);
        ADVWORD();
        for (j = 0; j < count; j++)
        {
            valuetypeMapV2 y;
            y.name = wordToString(accessIndexWord(currentWord, 1), false);
            y.score = WordToInt(accessIndexWord(currentWord, 2));
            InsertMapV2(&currentGame, j, y);
            ADVWORD();
        }
        infotypeSetV2 c;
        Word cg = arrgame->A[i];
        c.game = wordToString(cg, false);
        c.M = currentGame;
        InsertSetV2(SB, c);
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
