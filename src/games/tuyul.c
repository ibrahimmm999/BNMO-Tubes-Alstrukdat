#include <stdio.h>
#include <stdlib.h>
#include "../ADT/mesinkata.h"
#include "../ADT/array.h"
#include "../boolean.h"
#include <time.h>

void gbk()
{
    Arr board;
    Word gunting;
    MakeEmpty(&board);
    gunting.TabWord[0]='g';
    gunting.TabWord[1]='u';
    gunting.TabWord[2]='n';
    gunting.TabWord[3]='t';
    gunting.TabWord[4]='i';
    gunting.TabWord[5]='n';
    gunting.TabWord[6]='g'; 
    gunting.Length=7;
    SetEl(&board, 0, gunting);

    Word kertas;
    kertas.TabWord[0]='k';
    kertas.TabWord[1]='e';
    kertas.TabWord[2]='r';
    kertas.TabWord[3]='t';
    kertas.TabWord[4]='a';
    kertas.TabWord[5]='s';  
    kertas.Length=6;      
    SetEl(&board, 1, kertas);
 
}    

