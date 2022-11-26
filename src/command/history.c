#include "history.h"

void addToHistory(StackW *history, Word gamePlayed)
{
    PushStack(history, gamePlayed);
}

void HISTORY(StackW history, int n)
{
    if(n <= 0)
    {
        printf("Masukan tidak valid. Mohon kembali berikan masukan yang valid (n > 0).\n");
    } else { // n valid (n > 0)
        if(lengthStack(history) > 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan:\n");
            CetakStack(history, n);
        } else { // lengthStack(history) <= 0
            printf("Tidak ada daftar Game dalam history.\n");
        }
    }
}