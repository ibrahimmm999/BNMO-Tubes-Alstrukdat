#include "resetscoreboard.h"
#include <stdio.h>

void reset_scoreboard(Map *SBrng, Map *SBdd, Map *SBhm, Map *SBtoh, Map *SBsom)
{
    int i, input;
    Word trash;
    trash.Length = 1;
    trash.TabWord[0] = 'X';

    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    printf("1. RNG\n");
    printf("2. Diner Dash\n");
    printf("3. HANGMAN\n");
    printf("4. TOWER OF HANOI\n");
    printf("5. SNAKE ON METEOR\n");

    // pilih nomor
    printf("Scoreboard yang ingin dihapus: ");
    STARTSTDIN();
    input = (currentWord.TabWord[0] - 48);

    // panggil prosedur sesuai input
    switch (input)
    {
    case 0:
        printf("Apakah Anda yakin ingin melakukan RESET ALL SCOREBOARD (YA / TIDAK)? ");
        STARTSTDIN();
        RSB("RNG", SBrng, true, currentWord);
        RSB("Diner Dash", SBdd, true, currentWord);
        RSB("HANGMAN", SBhm, true, currentWord);
        RSB("TOWER OF HANOI", SBtoh, true, currentWord);
        RSB("SNAKE ON METEOR", SBsom, true, currentWord);
        break;
    case 1:
        RSB("RNG", SBrng, false, trash);
        break;
    case 2:
        RSB("Diner Dash", SBdd, false, trash);
        break;
    case 3:
        RSB("HANGMAN", SBhm, false, trash);
        break;
    case 4:
        RSB("TOWER OF HANOI", SBtoh, false, trash);
        break;
    case 5:
        RSB("SNAKE ON METEOR", SBsom, false, trash);
        break;
    default:
        printf("Scoreboard tidak tersedia. Mohon periksa masukan Anda.\n");
    }
}

void RSB(char *game, Map *SBGame, boolean isALL, Word answer)
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
        if (IsMapV2Empty(*SBGame))
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
