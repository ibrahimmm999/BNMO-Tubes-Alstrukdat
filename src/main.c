#include <stdio.h>
#include "console.h"

/*
RUN :
gcc main.c console.c ADT/queueV2.c ADT/mesinkata.c ADT/mesinkarakter.c command/help.c ADT/array.c command/start.c command/load.c command/playgame.c command/queuegame.c games/rng.c command/listgame.c command/creategame.c -o main

.\main
*/

int main()
{
    DISPLAYBANNER();
    MAINMENU();

    return 0;
}
