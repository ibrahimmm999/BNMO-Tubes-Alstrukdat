#include <stdio.h>

#include "boolean.h"
#include "./ADT/mesinkata.h"
#include "./ADT/array.h"
#include "./command/help.h"
#include "./command/start.h"
#include "./command/load.h"

/*
RUN :
gcc main.c ADT/mesinkata.c ADT/mesinkarakter.c command/help.c ADT/array.c command/start.c command/load.c -o main

.\main
*/

void displayBanner()
{
    printf("\n");
    printf("---------------------------------------- W E L C O M E  T O  B I N O M O ----------------------------------------------\n");
    printf("\n");
    printf(" ________          ___          ________           ________          _____ ______           ________     \n");
    printf("|\\   __  \\        |\\  \\        |\\   ___  \\        |\\   __  \\        |\\   _ \\  _   \\        |\\   __  \\    \n");
    printf("\\ \\  \\|\\ /_       \\ \\  \\       \\ \\  \\\\ \\  \\       \\ \\  \\|\\  \\       \\ \\  \\\\\\__\\ \\  \\       \\ \\  \\|\\  \\   \n");
    printf(" \\ \\   __  \\       \\ \\  \\       \\ \\  \\\\ \\  \\       \\ \\  \\\\\\  \\       \\ \\  \\\\|__| \\  \\       \\ \\  \\\\\\  \\  \n");
    printf("  \\ \\  \\|\\  \\       \\ \\  \\       \\ \\  \\\\ \\  \\       \\ \\  \\\\\\  \\       \\ \\  \\    \\ \\  \\       \\ \\  \\\\\\  \\ \n");
    printf("   \\ \\_______\\       \\ \\__\\       \\ \\__\\\\ \\__\\       \\ \\_______\\       \\ \\__\\    \\ \\__\\       \\ \\_______\\ \n");
    printf("    \\|_______|        \\|__|        \\|__| \\|__|        \\|_______|        \\|__|     \\|__|        \\|_______| \n");
    printf("\n");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n\n\n");
}

boolean cekInput(Word command)
{
    if (currentWord.Length == command.Length)
    {
        int i = 0;
        boolean isEqual = true;
        while (isEqual && i < command.Length)
        {
            if (currentWord.TabWord[i] != command.TabWord[i])
            {
                isEqual = false;
            }
            i++;
        }
        return isEqual;
    }
    return false;
}

int main()

{
    Arr arraycommand;
    MakeEmpty(&arraycommand);
    Arr arrgame;

    Word commandstart;
    commandstart.TabWord[0] = 'S';
    commandstart.TabWord[1] = 'T';
    commandstart.TabWord[2] = 'A';
    commandstart.TabWord[3] = 'R';
    commandstart.TabWord[4] = 'T';
    commandstart.Length = 5;
    SetEl(&arraycommand, 0, commandstart);

    Word commandhelp;
    commandhelp.TabWord[0] = 'H';
    commandhelp.TabWord[1] = 'E';
    commandhelp.TabWord[2] = 'L';
    commandhelp.TabWord[3] = 'P';
    commandhelp.Length = 4;
    SetEl(&arraycommand, 1, commandhelp);

    Word commandload;
    commandload.TabWord[0] = 'L';
    commandload.TabWord[1] = 'O';
    commandload.TabWord[2] = 'A';
    commandload.TabWord[3] = 'D';
    commandload.Length = 4;
    SetEl(&arraycommand, 2, commandload);

    displayBanner();
    STARTSTDIN();
    int i;
    // printf("%d\n", arraycommand.Neff);
    for (i = 0; i < arraycommand.Neff; i++)
    {
        if (cekInput(arraycommand.A[i]))
        {
            if (i == 0)
            {
                STARTGAME(&arrgame);
                TulisIsi(arrgame);
            }
            else if (i == 1)
            {
                DISPLAYHELP();
            }
            else if (i == 2)
            {
                LOAD("../data/savefile.txt", &arrgame);
                TulisIsi(arrgame);
            }
        }
    }
}
