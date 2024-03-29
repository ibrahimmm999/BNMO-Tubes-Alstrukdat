#include <stdio.h>
#include "console.h"

void DISPLAYBANNER()
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

void MAINMENU()

{
    Arr arrGame;
    Queue queueGame;
    CreateQueue(&queueGame);
    boolean cek = true;
    while (cek)
    {
        printf(":::::: PILIHAN MENU :::::: \n");
        printf("::                      ::\n");
        printf("::         START        ::\n");
        printf("::  LOAD <filename.txt> ::\n");
        printf("::                      ::\n");
        printf("::::::::::::::::::::::::::\n\n");
        printf("ENTER COMMAND: ");
        STARTSTDIN();
        if (IsWordEqual(currentWord, "START"))
        {
            STARTGAME(&arrGame);
            cek = false;
        }
        else if (IsWordEqual(accessIndexWord(currentWord, 1), "LOAD"))
        {
            if (currentWord.Length == 4)
            {
                printf("Masukkan nama file!\n");
            }
            else
            {
                Word x = accessIndexWord(currentWord, 2);
                int k = 8;
                int len = 8 + x.Length;
                char *c = malloc((len) * sizeof(char));
                char *dir = "../data/";
                int i, j;
                for (j = 0; j < k; j++)
                {
                    c[j] = dir[j];
                }
                for (i = 0; i < x.Length; i++)
                {

                    c[k] = x.TabWord[i];
                    k++;
                }
                c[k] = '\0';

                FILE *p;
                p = fopen(c, "r");
                if (p == NULL)
                {
                    printf("Masukkan file dengan benar\n");
                }
                else
                {
                    LOAD(wordToString(x, true), &arrGame);
                    fclose(p);
                    cek = false;
                }
            }
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    cek = true;
    while (cek)
    {
        printf("\n\n");
        printf(":::::: PILIHAN MENU :::::: \n");
        printf("::                      ::\n");
        printf("::  SAVE <filename.txt> ::\n");
        printf("::  CREATE GAME         ::\n");
        printf("::  LIST GAME           ::\n");
        printf("::  DELETE GAME         ::\n");
        printf("::  QUEUE GAME          ::\n");
        printf("::  PLAY GAME           ::\n");
        printf("::  SKIPGAME <n>        ::\n");
        printf("::  HELP                ::\n");
        printf("::  QUIT                ::\n");
        printf("::                      ::\n");
        printf("::::::::::::::::::::::::::\n\n");
        printf("ENTER COMMAND: ");
        STARTSTDIN();
        if (IsWordEqual(currentWord, "QUIT"))
        {
            quit(&cek);
        }
        else if (IsWordEqual(currentWord, "HELP"))
        {
            DISPLAYHELP();
        }
        else if (IsWordEqual(currentWord, "PLAY GAME"))
        {
            PLAYGAME(&queueGame);
        }
        else if (IsWordEqual(currentWord, "QUEUE GAME"))
        {
            QUEUEGAME(&queueGame, arrGame);
        }
        else if (IsWordEqual(currentWord, "LIST GAME"))
        {
            LISTGAME(arrGame);
        }
        else if (IsWordEqual(currentWord, "CREATE GAME"))
        {
            CREATEGAME(&arrGame);
        }
        else if (IsWordEqual(currentWord, "DELETE GAME"))
        {
            DELETEGAME(&arrGame, queueGame);
        }
        else if (IsWordEqual(accessIndexWord(currentWord, 1), "SKIPGAME") && accessIndexWord(currentWord, 1).Length == 8)
        {
            if (currentWord.Length > 9)
            {

                Word x = accessIndexWord(currentWord, 2);
                SKIPGAME(&queueGame, WordToInt(x));
            }
            else
            {
                printf("Masukkan command yang valid\n");
            }
        }
        else if (IsWordEqual(accessIndexWord(currentWord, 1), "SAVE"))
        {
            Word x = accessIndexWord(currentWord, 2);
            save(wordToString(x, true), arrGame);
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
}