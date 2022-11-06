#include "queuegame.h"

void QUEUEGAME(Queue *queueGame, Arr arrGame)
{
    printf("Berikut adalah daftar antrian game-mu\n");
    displayQueue(*queueGame);
    printf("\nBerikut adalah daftar game yang tersedia\n");
    TulisIsi(arrGame);
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTSTDIN();
    int currentGame = WordToInt(currentWord);
    if (currentGame > arrGame.Neff || currentGame <= 0)
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else
    {
        enqueue(queueGame, arrGame.A[currentGame - 1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n\n");
        displayQueue(*queueGame);
    }
}