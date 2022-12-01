#include "hangman.h"
#include <stdio.h>

void hangman()
{
    displayHangmanTextArt();
    Set guessedAlphabet;
    Arr guessWords;
    generateWordList(&guessWords);
    int chance = 10;
    int idx = 0;
    int score = 0;
    CreateSet(&guessedAlphabet);
    while (chance > 0)
    {
        Word currentGuess = guessWords.A[idx];
        charUpper(&currentGuess);
        playHangman(&chance, currentGuess, &guessedAlphabet);
        if (chance != 0)
        {
            score += currentGuess.Length;
        }
        idx++;
        if (idx == NbElmt(guessWords))
        {
            printf("Selamat! Kamu berhasil menebak semua kata pada game ini\n");
            winMessage();
            chance = 0;
        }
        CreateSet(&guessedAlphabet);
    }
    printf("GAME OVER.\nSkor kamu: %d", score);
}

void playHangman(int *chance, Word currentGuess, Set *guessedAlphabet)
{
    boolean win = false;
    char *guessTemp = (char *)malloc(sizeof(currentGuess.TabWord));
    for (int i = 0; i < currentGuess.Length; i++)
    {
        guessTemp[i] = '_';
    }

    while (!win && *chance > 0)
    {
        printf("Tebakan sebelumnya: ");
        TulisIsiSet(*guessedAlphabet);
        printf("Kata: ");
        printStringWithSpace(guessTemp, currentGuess.Length);
        printf("Kesempatan: %d\n", *chance);

        printf("Masukkan tebakan: ");
        STARTSTDIN();

        if (currentWord.Length == 1)
        {
            charLower(&currentWord);
            if (IsMemberSet(*guessedAlphabet, currentWord))
            {
                printf("Kamu sudah pernah menebak huruf %c\n\n", currentWord.TabWord[0]);
                (*chance)--;
                hangmanPics(*chance);
            }
            else
            {
                charUpper(&currentWord);
                if (!IsAlphabetExist(currentWord.TabWord[0], currentGuess))
                {
                    printf("Tebakan kamu salah!\n\n");
                    charLower(&currentWord);
                    InsertElSet(guessedAlphabet, currentWord);
                    (*chance)--;
                    hangmanPics(*chance);
                }
                else
                {
                    printf("Selamat, tebakan kamu benar!\n\n");
                    charLower(&currentWord);
                    InsertElSet(guessedAlphabet, currentWord);
                    underscoreToAlphabet(currentWord.TabWord[0], guessTemp, currentGuess);
                    if (IsRoundFinished(guessTemp, currentGuess))
                    {
                        win = true;
                    }
                    else
                    {
                        win = false;
                        hangmanPics(*chance);
                    }
                }
            }
        }
        else if (currentWord.Length == 0)
        {
            printf("Input tidak boleh kosong\n\n");
        }
        else
        {
            printf("Anda hanya bisa menebak satu huruf per tebakan\n\n");
            (*chance)--;
            hangmanPics(*chance);
        }
    }
    if (win)
    {
        printf("Selamat! Anda berhasil menebak %s. Kamu mendapat %d poin\n\n", currentGuess.TabWord, currentGuess.Length);
    }
    if (*chance == 0)
    {
        printf("Kesempatan habis!\n");
    }
}

void charUpper(Word *w)
{
    for (int i = 0; i < (*w).Length; i++)
    {
        if ((*w).TabWord[i] >= 'a' && (*w).TabWord[i] <= 'z')
        {
            (*w).TabWord[i] -= 32;
        }
    }
}

void charLower(Word *w)
{
    if ((*w).TabWord[0] >= 'A' && (*w).TabWord[0] <= 'Z')
    {
        (*w).TabWord[0] += 32;
    }
}

boolean IsRoundFinished(char *guessTemp, Word currentGuess)
{
    for (int i = 0; i < currentGuess.Length; i++)
    {
        if ('_' == guessTemp[i])
        {
            return false;
        }
    }
    return true;
}

void underscoreToAlphabet(char c, char *guessTemp, Word currentGuess)
{
    for (int i = 0; i < currentGuess.Length; i++)
    {
        if (c == currentGuess.TabWord[i])
        {
            guessTemp[i] = c;
        }
        else if (c - 32 == currentGuess.TabWord[i])
        {
            guessTemp[i] = c - 32;
        }
    }
}

boolean IsAlphabetExist(char c, Word currentGuess)
{
    for (int i = 0; i < currentGuess.Length; i++)
    {
        if ((c == currentGuess.TabWord[i]) || (c - 32 == currentGuess.TabWord[i]))
        {
            return true;
        }
    }
    return false;
}

void printStringWithSpace(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
}

void generateWordList(Arr *word)
{
    FILE *p;
    p = fopen("../../data/hangman.txt", "r");
    MakeEmpty(word);
    STARTWORD("../../data/hangman.txt");

    int lenOfArr = currentWord.TabWord[0] - 48;

    for (int i = 0; i < lenOfArr; i++)
    {
        ADVWORD();
        SetEl(word, i, currentWord);
    }
    fclose(p);
}

void displayHangmanTextArt()
{
    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | |\n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n");
    printf("                    __/ |                      \n");
    printf("                   |___/   \n");
    printf("\n\n");
}

void hangmanPics(int chance)
{
    if (chance == 9)
    {
        printf("\n\n\n\n\n\n");
        printf("=========\n");
    }
    else if (chance == 8)
    {
        printf("\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 7)
    {
        printf("   +---+\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 6)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 5)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 4)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 3)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 2)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 1)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  /    |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if (chance == 0)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  / \\  |\n");
        printf("       |\n");
        printf("=========\n");
        printf("\n");
        printf("                      _                \n");
        printf("                     | |               \n");
        printf("  _   _  ___  _   _  | | ___  ___  ___ \n");
        printf(" | | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\\n");
        printf(" | |_| | (_) | |_| | | | (_) \\__ \\  __/\n");
        printf("  \\__, |\\___/ \\__,_| |_|\\___/|___/\\___|\n");
        printf("   __/ |                               \n");
        printf("  |___/                                \n");
    }
}

void winMessage()
{
    printf("                               _       \n");
    printf("                              (_)      \n");
    printf("  _   _  ___  _   _  __      ___ _ __  \n");
    printf(" | | | |/ _ \\| | | | \\ \\ /\\ / / | '_ \\ \n");
    printf(" | |_| | (_) | |_| |  \\ V  V /| | | | |\n");
    printf("  \\__, |\\___/ \\__,_|   \\_/\\_/ |_|_| |_|\n");
    printf("   __/ |                               \n");
    printf("  |___/                                \n");
}

// gcc hangman.c ../ADT/array.c ../ADT/mesinkarakter.c ../ADT/mesinkata.c ../ADT/set.c -o hangman
// int main(){
//     hangman();
//     return 0;
// }
