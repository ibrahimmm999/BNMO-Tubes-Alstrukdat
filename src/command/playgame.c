
#include "playgame.h"

void playCurrentGame(Queue *queueGame, StackW *history, Word currentGame)
{
    if (IsWordEqual(currentGame, "RNG"))
    {
        RNG();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "Diner DASH"))
    {
        dinerDash();
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
        SnakeOnMeteor();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "HANGMAN"))
    {
        hangman();
        addToHistory(history, currentGame);
    }
    else if (IsWordEqual(currentGame, "Guess the Peter Parker"))
    {
        addToHistory(history, currentGame);
    }
    else
    {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", wordToString(currentGame, false));
        addToHistory(history, currentGame);
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

void PLAYGAME(Queue *queueGame, StackW *history)
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
        playCurrentGame(queueGame, history, currentGame);

        dequeue(queueGame, &currentGame);
    }
}