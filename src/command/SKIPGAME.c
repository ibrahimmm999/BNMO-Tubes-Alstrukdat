#include "SKIPGAME.h"

void SKIPGAME(Queue *queueGame, int numSkip)
{
    /* Kamus */
    int i = 0;
    boolean notEmpty = false;
    ElType val;
    Word currentGame = HEAD(*queueGame);
    /* Algoritma */
    printf("Berikut adalah daftar Game-mu\n"); // Menampilkan antrean Game pemain
    displayQueue(*queueGame);                  // Menampilkan Game-Game dalam antrean pemain secara vertikal
    if (numSkip > 0)
    { // Percabangan untuk memastikan parameter input numSkip valid (bukan nol dan bukan pula bilangan negatif)
        while (i < numSkip && notEmpty == false)
        {                                     // Pengulangan untuk 'menghapus' numSkip buah Game pada antrean awal
            dequeue(queueGame, &currentGame); // 'Menghapus' Game pada antrean pertama
            if (length(*queueGame) == 0)
            {                    // Percabangan apabila sudah tidak ada lagi Game dalam antrean
                notEmpty = true; // Assign true
            }
            i++;
        }
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
        if (IsWordEqual(currentGame, "RNG"))
        {
            RNG();
        }
        else if (IsWordEqual(currentGame, "Diner DASH"))
        {
            printf("diner dash");
        }
        else if (IsWordEqual(currentGame, "tictactoe"))
        {
            tictactoe();
        }
        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.", wordToString(currentGame, false));
        }
    }
}
