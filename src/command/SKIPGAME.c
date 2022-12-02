#include "SKIPGAME.h"

void SKIPGAME(Queue *queueGame, StackW *history, int numSkip, MapV2 *SBGame)
{
    /* Kamus */
    int i = 0;
    boolean notEmpty = false;
    ElType val;
    Word currentGame = HEAD(*queueGame);
    /* Algoritma */
    if (numSkip > 0)
    { // Percabangan untuk memastikan parameter input numSkip valid (bukan nol dan bukan pula bilangan negatif)
        if (length(*queueGame) == 0)
        {
            printf("Antrean Game kosong. Kamu belum/sudah tidak memiliki daftar Game yang ingin dimainkan dalam antrean. Tidak ada Game yang perlu dilewati. Mohon masukkan dahulu sejumlah Game dalam antrean melalui command QUEUE GAME\n");
        }
        else if (length(*queueGame) > 0)
        {
            printf("Berikut adalah daftar Game-mu\n"); // Menampilkan antrean Game pemain
            displayQueue(*queueGame);                  // Menampilkan Game-Game dalam antrean pemain secara vertikal
            while (i < numSkip && notEmpty == false)
            {                                     // Pengulangan untuk 'menghapus' numSkip buah Game pada antrean awal
                dequeue(queueGame, &currentGame); // 'Menghapus' Game pada antrean pertama
                if (length(*queueGame) == 0)
                {                    // Percabangan apabila sudah tidak ada lagi Game dalam antrean
                    notEmpty = true; // Assign true
                }
                i++;
            }
            if (length(*queueGame) == 0)
            { // Percabangan apabila tidak ada Game untuk dimainkan dalam antrean Game pemain
                printf("Tidak ada permainan lagi dalam daftar Game-mu\n");
            }
            else
            { // length(*queueGame) != 0 -> memulai permainan pada antrean teratas
                dequeue(queueGame, &currentGame);
                printf("Loading ");
                displayCurrentGame(currentGame);
                printf(" ...\n");

                playCurrentGame(queueGame, history, currentGame, SBGame);
            }
        }
    }
    else
    {
        printf("Command kurang tepat. Mohon masukkan kembali n yang valid (n > 0).");
    }
}
