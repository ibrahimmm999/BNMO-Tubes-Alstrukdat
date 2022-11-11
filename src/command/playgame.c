
#include "playgame.h"

void displayCurrentGame(Word CurrentGame)
{
    int j;
    for (j = 0; j < CurrentGame.Length; j++)
    {
        printf("%c", CurrentGame.TabWord[j]);
    }
}

void PLAYGAME(Queue *queueGame)
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
        if (IsWordEqual(currentGame, "RNG"))
        {
            RNG();
        }
        else if (IsWordEqual(currentGame, "Diner DASH"))
        {
            dinerDash();
        }
        else if (IsWordEqual(currentGame, "tictactoe"))
        {
            tictactoe();
        }
        else if (IsWordEqual(currentGame, "gbk"))
        {
            gbk();
        }
        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", wordToString(currentGame, false));
        }

        dequeue(queueGame, &currentGame);
    }
}