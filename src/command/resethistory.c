#include "resethistory.h"

void RESETHISTORY(ListV2 *history)
{
    printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY (YA/TIDAK)? ");
    STARTSTDIN();
    if(IsWordEqual(currentWord, "YA"))
    {
        if(LengthV2(*history) > 0)
        {
            DeleteAll(history);
            printf("\nHistory berhasil di-reset.");
        } else { // LengthV2(*history) == 0
            printf("\nTidak ada daftar Game dalam history, tidak perlu melakukan reset.\n");
        }
    } else if(IsWordEqual(currentWord, "TIDAK")) {
        printf("\nHistory tidak jadi di-reset. ");
        if(LengthV2(*history) > 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan:\n");
            CetakList(*history, LengthV2(*history));
        } else { // LengthV2(*history) == 0
            printf("Tidak ada daftar Game dalam history.\n");
        }
    } else { // masukan bukan "YA" atau "TIDAK"
        printf("\nMohon berikan kembali masukan yang valid (hanya berupa 'YA' atau 'TIDAK'\n");
    }
}