#include "scoreboard.h"

void PrintSpace(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
}

void PrintSB(char *game, Map SBGame) {
    Word temp;
    char *nama;
    int skor, i;
    
    // header
    printf("**** SCOREBOARD GAME ");
    printf("%s", game);
    printf(" ****\n");
    printf("|      NAMA       |  SKOR  |\n");
    printf("|__________________________|\n");

    // isi
    if (IsEmpty(SBGame)) {
        printf("     Scoreboard Kosong      \n");
    }
    else {
        for (i = 0; i < SBGame.Count; i++) {
            nama = VName(SBGame, i);
            temp = stringToWord(nama);
            skor = VScore(SBGame, i);

            printf("| %s", nama);
            PrintSpace(16 - temp.Length);

            printf("| %d", skor);
            if (skor < 10) {
                PrintSpace(7-1);
            }
            else if (skor >= 10 && skor < 100) {
                PrintSpace(7-2);
            }
            else {
                PrintSpace(7-3);
            }

            printf("|\n");
        }
    }
}

void scoreboard(Map SBrng, Map SBdd, Map SBhm, Map SBtoh, Map SBsom) {
    PrintSB("RNG", SBrng);
    PrintSB("Diner Dash", SBdd);
    PrintSB("HANGMAN", SBhm);
    PrintSB("TOWER OF HANOI", SBtoh);
    PrintSB("SNAKE ON METEOR", SBsom);
}

void InsertScoreboard (char *nama, int skor, Map *SBGame) {
    if (!NameExist(*SBGame, nama)) {
        int i, j;
        valuetype el;
        el.name = nama;
        el.score = skor;

        if (IsEmpty(*SBGame)) {
            Insert(SBGame, 0, el);
        }
        else {
            // geser elemen yang skornya lebih kecil dari skor input
            i = SBGame->Count;
            while (i > 0 && VScore(*SBGame, i-1) < skor) {
                SBGame->Elements[i].Key = i;
                SBGame->Elements[i].Value.name = SBGame->Elements[i-1].Value.name;
                SBGame->Elements[i].Value.score = SBGame->Elements[i-1].Value.score;
                i--;
            }
            
            // insert di posisi yang sesuai
            Insert(SBGame, i, el);
        }
    }
}
