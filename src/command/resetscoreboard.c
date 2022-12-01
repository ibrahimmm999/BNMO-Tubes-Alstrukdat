#include "resetscoreboard.h"
#include <stdio.h>

void reset_scoreboard(Set *S)
{
    int i, input;
    Word trash;
    trash.Length = 1;
    trash.TabWord[0] = 'X';

    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (i = 0; i < S->Count; i++) {
        printf("%d. %s\n", i+1, S->Elements[i].game);
    }

    // pilih nomor
    printf("Scoreboard yang ingin dihapus: ");
    STARTSTDIN();
    input = (currentWord.TabWord[0] - 48);

    // panggil prosedur sesuai input
    if (input == 0) {
        printf("Apakah Anda yakin ingin melakukan RESET SCOREBOARD (YA / TIDAK)? ");
        STARTSTDIN();
        for (i = 0; i < S->Count; i++) {
            RSB(S->Elements[i].game, &S->Elements[i].M, true, currentWord);
        }
    }
    else if (input > 0 && input <= S->Count) {
        RSB(S->Elements[i-1].game, &S->Elements[i-1].M, false, trash);
    }
    else {
        printf("Scoreboard tidak tersedia. Mohon periksa masukan Anda.\n");
    }
}

void RSB(char *game, MapV2 *SBGame, boolean isALL, Word answer)
{
    int i, j, len;
    Word confirm;

    if (!isALL)
    {
        printf("Apakah Anda yakin ingin melakukan RESET SCOREBOARD ");
        printf("%s", game);
        printf(" (YA / TIDAK)? ");
        STARTSTDIN();
        confirm = currentWord;
    }
    else
    {
        confirm = answer;
    }

    if (IsWordEqual(confirm, "YA"))
    {
        // hapus semua isi map
        len = SBGame->Count;
        for (j = 0; j < len; j++)
        {
            SBGame->Elements[j].Key = Undefined;
            SBGame->Elements[j].Value.name = "";
            SBGame->Elements[j].Value.score = Undefined;
        }
        SBGame->Count = 0;

        printf("Scoreboard ");
        printf("%s", game);
        if (IsMapEmptyV2(*SBGame))
        {
            printf(" berhasil di-reset.\n");
        }
        else
        {
            printf(" gagal di-reset.\n");
        }
    }

    else if (IsWordEqual(confirm, "TIDAK"))
    {
        printf("Scoreboard tidak di-reset.\n");
    }
    else
    {
        printf("Jawaban yang diberikan tidak valid.\n");
    }
}
