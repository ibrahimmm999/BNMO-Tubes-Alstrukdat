#include <"array.h">
#include <stdio.h>
#include <stdlib.h>

#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;

void IgnoreNewLine()
{
    while (currentChar == '\n')
    {
        ADV();
    }
}
void IgnoreBlanks()
{
    while (currentChar == '\n')
    {
        ADV();
    }
}

void STARTWORD(char savefile[])
{
    START(savefile);
    // IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreNewLine();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
    }
}

void CopyWord()
{
    int i = 0;
    while ((i < NMax) && (currentChar != '\n') && (!EOP))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

int WordToInt(Word word)
{
    int result = 0;
    int i;
    result += word.TabWord[0] - 48;
    if (word.Length > 1)
    {
        for (i = 1; i < word.Length; i++)
        {
            result *= 10;
            result += word.TabWord[i] - 48;
        }
    }

    return result;
}

void STARTSTDIN()
{
    STARTINPUT();
    if (currentChar == '\0')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

boolean IsWordEqual(Word k1, char *k2)
{
    boolean sama = true;
    for (int i = 0; i < k1.Length; i++)
    {
        if (k2[i] != k1.TabWord[i])
        {

            sama = false;
        }
    }

    return sama;
}

Word accessIndexWord(Word command, int indexWord)
{
    /*Mengakses kata dalam kalimat
    I.S. pita kata terdefinisi
    F.S. diakuisisi ke dalam w
    */
    Word word;
    boolean cek = false;
    int i = 0, counter = 0, length = 0;
    while (counter != indexWord - 1 && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            counter++;
        }

        i++;
        if (i == command.Length)
        {
            counter++;
        }
    }

    while (!cek && i < command.Length)
    {
        if (command.TabWord[i] == ' ')
        {
            cek = true;
        }
        else
        {
            word.TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    word.Length = length;
    return word;
}

char *wordToString(Word w, boolean isLoadOrSave)
{
    if (isLoadOrSave)
    {
        int k = 8;
        int len = 8 + w.Length;
        char *c = malloc((len) * sizeof(char));
        char *dir = "../data/";
        int i, j;
        for (j = 0; j < k; j++)
        {
            c[j] = dir[j];
        }
        for (i = 0; i < w.Length; i++)
        {

            c[k] = w.TabWord[i];
            k++;
        }
        c[k] = '\0';
        // printf("%s\n", c);
        return c;
    }
    else
    {
        char *c = malloc((w.Length) * sizeof(char));
        int i;
        for (i = 0; i < w.Length; i++)
        {

            c[i] = w.TabWord[i];
        }
        c[i] = '\0';
        // printf("%s\n", c);
        return c;
    }
}
