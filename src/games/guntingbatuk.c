#include <stdio.h>
#include <stdlib.h>
#include "guntingbatuk.h"
#include <time.h>

void gbk()
{
    Arr board;
    Word gunting;
    MakeEmpty(&board);
    gunting.TabWord[0] = 'g';
    gunting.TabWord[1] = 'u';
    gunting.TabWord[2] = 'n';
    gunting.TabWord[3] = 't';
    gunting.TabWord[4] = 'i';
    gunting.TabWord[5] = 'n';
    gunting.TabWord[6] = 'g';
    gunting.Length = 7;
    SetEl(&board, 0, gunting);

    Word kertas;
    kertas.TabWord[0] = 'k';
    kertas.TabWord[1] = 'e';
    kertas.TabWord[2] = 'r';
    kertas.TabWord[3] = 't';
    kertas.TabWord[4] = 'a';
    kertas.TabWord[5] = 's';
    kertas.Length = 6;
    SetEl(&board, 1, kertas);

    Word batu;
    batu.TabWord[0] = 'b';
    batu.TabWord[1] = 'a';
    batu.TabWord[2] = 't';
    batu.TabWord[3] = 'u';
    batu.Length = 4;
    SetEl(&board, 2, batu);

    int playerwin = 0;
    int i;
    printf("Mau bermain? ");
    printf("Ketik 1 untuk bermain\n");
    printf("Ketik 2 untuk keluar\n");
    printf("ENTER CHOICE : ");    
    STARTSTDIN();
    while (IsWordStr(currentWord, "2"))
    {
        break;
    }
    while (IsWordStr(currentWord, "1"))
    {
        srand(time(NULL));
        int x = rand() % 3;
        printf("Keluarkan pilihanmu..");
        ADVWORD();
        if (x == 0 && IsWordEqual(currentWord, "gunting")){
            printf("yah seri\n");
        }
        else if (x == 0 && IsWordEqual(currentWord, "kertas")){
        printf("kamu kalah\n");
        }
        else if (x == 0 && IsWordEqual(currentWord, "batu"))
        {
            printf("kamu menang\n");
        }
        else if (x == 1 && IsWordEqual(currentWord, "kertas"))
        {
            printf("yah seri\n");
        }
        else if (x == 1 && IsWordEqual(currentWord, "batu"))
        {
            printf("kamu kalah\n");
        }
        else if (x == 1 && IsWordEqual(currentWord, "gunting"))
        {
            printf("kamu menang\n");
        }
        else if (x == 2 && IsWordEqual(currentWord, "batu"))
        {
            printf("yah seri\n");
        }
        else if (x == 2 && IsWordEqual(currentWord, "gunting"))
        {
            printf("kamu kalah\n");
        }
        else if (x == 2 && IsWordEqual(currentWord, "kertas"))
        {
            printf("kamu menang\n");
        }
        printf("Ketik satu untuk main lagi\n");
        ADVWORD();
    }
}
