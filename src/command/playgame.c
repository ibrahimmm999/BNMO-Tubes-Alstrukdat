
#include "playgame.h"

void playCurrentGame(Queue *queueGame, StackW *history, Word currentGame, SetV2 *SBGame)
{
    int score = 0;
    if (IsWordEqual(currentGame, "RNG"))
    {
        RNG(&score);
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "Diner DASH"))
    {
        dinerDash(&score);
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "tictactoe"))
    {
        tictactoe();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "gbk"))
    {
        gbk();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "TOWER OF HANOI"))
    {
        TowerOfHanoi();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "SNAKE ON METEOR"))
    {
        SnakeOnMeteor(&score);
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "HANGMAN"))
    {
        hangman();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "Guess the Peter Parker"))
    {
        GPP(&score);
        addToHistory(history, currentGame);
    }
    else
    {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", wordToString(currentGame, false));
        addToHistory(history, currentGame);
    }
    printf("\nNama: \n");
    STARTSTDIN();
    while (NameExist(((*SBGame).Elements->M), wordToString(currentWord, false)))
    {
        printf("Nama sudah digunakan, mohon gunakan nama lain.\n");
        printf("Tampilkan daftar nama pada scoreboard (YA / TIDAK)? ");
        STARTSTDIN();
        if (IsWordEqual(currentWord, "YA"))
        {
            ShowNamesSB((*SBGame).Elements->M);
        }
        printf("\nNama: \n");
        STARTSTDIN();
    }

    int i, j;
    valuetypeMapV2 el;
    el.name = wordToString(currentWord, false);
    el.score = score;

    if (IsMapEmptyV2(SBGame->Elements->M))
    {
        printf("\ncek\n");
        InsertMapV2(&(*SBGame).Elements->M, 0, el);
    }
    else
    {
        // geser elemen yang skornya lebih kecil dari skor input
        i = SBGame->Count;
        while (i > 0 && VScore((*SBGame).Elements->M, i - 1) < score)
        {
            (*SBGame).Elements[i].M.Elements->Key = i;
            (*SBGame).Elements[i].M.Elements->Value.name = (*SBGame).Elements[i - 1].M.Elements->Value.name;
            (*SBGame).Elements[i].M.Elements->Value.score = (*SBGame).Elements[i - 1].M.Elements->Value.score;
            i--;
        }
        printf("\n%d\n", i);
        // insert di posisi yang sesuai
        InsertMapV2(&(*SBGame).Elements->M, i, el);
        // InsertMapV2(SBGame, i, el);
    }
}

void displayCurrentGame(Word CurrentGame)
{
    int j;
    for (j = 0; j < CurrentGame.Length; j++)
    {
        printf("%c", CurrentGame.TabWord[j]);
    }
}

void PLAYGAME(Queue *queueGame, StackW *history, SetV2 *SBGame)
{
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*queueGame);
    if (length(*queueGame) == 0)
    {
        printf("Tidak ada game di dalam antrian\n");
    }
    else
    {
        Word currentGame = HEAD(*queueGame);
        printf("Loading ");
        displayCurrentGame(currentGame);
        printf(" ...\n\n");
        playCurrentGame(queueGame, history, currentGame, SBGame);

        dequeue(queueGame, &currentGame);
    }
}