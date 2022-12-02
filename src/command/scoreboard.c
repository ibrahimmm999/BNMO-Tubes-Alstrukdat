#include "scoreboard.h"

void PrintSpace(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void PrintSB(char *game, MapV2 SBGame)
{
    Word temp;
    char *nama;
    int skor, i;

    // header
    printf("***** SCOREBOARD GAME ");
    printf("%s", game);
    printf(" *****\n");
    printf(".______________________________.\n");
    printf("|        NAMA         |  SKOR  |\n");
    printf("|==============================|\n");

    // isi
    if (IsMapEmptyV2(SBGame))
    {
        printf("|      Scoreboard Kosong       |\n");
    }
    else
    {
        for (i = 0; i < SBGame.Count; i++)
        {
            nama = VName(SBGame, i);
            temp = stringToWord(nama);
            skor = VScore(SBGame, i);

            printf("| %s", nama);
            PrintSpace(20 - temp.Length);

            printf("| %d", skor);
            if (skor < 10)
            {
                PrintSpace(7 - 1);
            }
            else if (skor >= 10 && skor < 100)
            {
                PrintSpace(7 - 2);
            }
            else
            {
                PrintSpace(7 - 3);
            }

            printf("|\n");
        }
    }
    printf("|______________________________|\n");
}

void scoreboard(Set SetOfSB)
{
    int i;
    for (i = 0; i < SetOfSB.Count; i++)
    {
        PrintSB(SetOfSB.Elements[i].game, SetOfSB.Elements[i].M);
    }
}

void InsertScoreboard(char *nama, int skor, MapV2 *SBGame)
{
    if (!NameExist(*SBGame, nama))
    {
        int i, j;
        valuetypeMapV2 el;
        el.name = nama;
        el.score = skor;

        if (IsMapEmptyV2(*SBGame))
        {
            InsertMapV2(SBGame, 0, el);
        }
        else
        {
            // geser elemen yang skornya lebih kecil dari skor input
            i = SBGame->Count;
            while (i > 0 && VScore(*SBGame, i - 1) < skor)
            {
                SBGame->Elements[i].Key = i;
                SBGame->Elements[i].Value.name = SBGame->Elements[i - 1].Value.name;
                SBGame->Elements[i].Value.score = SBGame->Elements[i - 1].Value.score;
                i--;
            }

            // insert di posisi yang sesuai
            InsertMapV2(SBGame, i, el);
        }
    }
    else
    {
        printf("Nama sudah digunakan, mohon gunakan nama lain.\n");
    }
}

void CreateScoreboard(Set *SetOfSB, char *game)
{
    MapV2 M;
    CreateEmptyMapV2(&M);

    infotypeSetV2 val;
    val.game = game;
    val.M = M;
    InsertSet(SetOfSB, val);
}
