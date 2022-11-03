#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char *savefile)
{
    pita = fopen(savefile, "r");
    ADV();
}

void STARTINPUT()
{
    pita = stdin;
    ADV();
}

void ADV()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK || feof(pita));
    if (EOP)
    {
        fclose(pita);
    }
}

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    return (currentChar == MARK);
}
