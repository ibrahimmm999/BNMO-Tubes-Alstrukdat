#include <stdio.h>
#include "console.h"

/*
RUN :
gcc main.c console.c ADT/list.c ADT/queueV2.c ADT/mesinkata.c ADT/mesinkarakter.c command/help.c ADT/array.c command/start.c command/load.c command/playgame.c command/queuegame.c games/rng.c command/SKIPGAME.c command/listgame.c command/creategame.c command/deletegame.c command/save.c command/quit.c games/tictactoe.c games/guntingbatuk.c games/dinerDash.c ADT/prioqueue.c -o main

.\main
*/

int main()
{
    DISPLAYBANNER();
    MAINMENU();

    return 0;
}
