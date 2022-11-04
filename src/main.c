#include <stdio.h>
#include "console.h"

/*
RUN :
gcc main.c console.c ADT/mesinkata.c ADT/mesinkarakter.c command/help.c ADT/array.c command/start.c command/load.c -o main

.\main
*/

int main()
{
    DISPLAYBANNER();
    MAINMENU();

    return 0;
}