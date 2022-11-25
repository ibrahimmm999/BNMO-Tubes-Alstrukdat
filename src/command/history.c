#include "history.h"

void addToHistory(ListV2 *history, Word gamePlayed)
{
    InsertLastV2(history, gamePlayed);
}

void HISTORY(ListV2 history, int n)
{
    if(n <= 0)
    {
        printf("Masukan tidak valid. Mohon kembali berikan masukan yang valid (n > 0).\n");
    } else { // n valid (n > 0)
        if(LengthV2(history) > 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan:\n");
            CetakList(history, n);
        } else { // LengthV2(*history) <= 0
            printf("Tidak ada daftar Game dalam history.\n");
        }
    }
}