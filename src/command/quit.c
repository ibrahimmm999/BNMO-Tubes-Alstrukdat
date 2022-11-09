
#include "quit.h"

void quit(boolean *isQuit)
{
    /*
    Prosedur untuk keluar dari program.
    *tidak ada validasi kondisi game sudah disimpan atau belum
    I.S. daftar permainan user tidak kosong atau mungkin kosong
    F.S. daftar permainan user kosong, keluar dari program
    int i;
    ElType temp;

    // hapus daftar permainan yang dimiliki user
    int list_len = length(your_games);
    for (i = 0; i < list_len; i++)
    {
        dequeue(&your_games, &temp);
    }

    printf("Anda telah keluar dari BNMO.\n");
    printf("Thanks for playing!\n");
    exit();
    */
    *isQuit = false;
}