#include "array.h"
#include <stdio.h>

int main()
{
    Arr bocol;
    MakeEmpty(&bocol);
    //buat array kosong

    int NbElmt(Arr T);
    Word gunting;

    gunting.TabWord[0]='g';
    gunting.TabWord[1]='u';
    gunting.TabWord[2]='n';
    gunting.TabWord[3]='t';
    gunting.TabWord[4]='i';
    gunting.TabWord[5]='n';
    gunting.TabWord[6]='g'; 
    gunting.Length=7;

    SetEl(&bocol, 0, gunting);

    NbElmt(bocol);
    //nilai element bocol
    MaxNbEl(bocol);
    // nilai element maksimal

    GetFirstIdx(bocol);

    GetLastIdx(bocol);
    return 0;
}
















