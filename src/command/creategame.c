#include "creategame.h"
#include <stdio.h>

void CREATEGAME(Arr *arrgame){
    boolean exist = false;

    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTSTDIN();
    for (int i=0; i<NbElmt(*arrgame); i++){
        if (IsWordEqual(currentWord, (*arrgame).A[i].TabWord)){
            exist = true;
        }
    }
    if (!exist){
        SetEl(arrgame, (*arrgame).Neff, currentWord);
        printf("Game berhasil ditambahkan");
    } else {
        printf("Game sudah terdapat di daftar game");
    }
}
