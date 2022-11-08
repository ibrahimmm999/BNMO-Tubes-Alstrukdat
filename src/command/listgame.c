#include "listgame.h"
#include <stdio.h>

void listgame(Arr arrgame){
    printf("Berikut adalah daftar game yang tersedia\n");

    for (int i=0; i<arrgame.Neff; i++){
        printf("%d. %s\n", i+1, arrgame.A[i]);
    }
}