#include "deletegame.h"
#include "listgame.h"
#include <stdio.h>

void DELETEGAME(Arr *arrgame, Queue queueGame){
    LISTGAME(*arrgame);
    printf("Masukkan nomor game yang akan dihapus:");
    STARTSTDIN();
    int input = WordToInt(currentWord);
    if (input > 5){
        boolean exist = false;
        for (int i=0; i<length(queueGame); i++){
            if (IsWordEqual((*arrgame).A[input-1], queueGame.buffer[i].TabWord)){
                exist = true;
            }
        }
        if (!exist){
            for (int j=input; j<NbElmt(*arrgame); j++){
                (*arrgame).A[j-1] = (*arrgame).A[j];
            }
            SetNeff(arrgame, NbElmt(*arrgame)-1);
        } else {
            printf("Game yang masih terdapat dalam queue game tidak dapat dihapus");
        }
    } else {
        printf("Game gagal dihapus");
    }
}