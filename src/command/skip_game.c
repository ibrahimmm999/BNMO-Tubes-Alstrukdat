#include <stdio.h>
#include "skip_game.h"

void SKIPGAME(Queue *Q, int n) {
    DISPLAYQUEUEGAME();
    ElType v;
    if(isEmpty(*Q)){
        printf("Tidak ada game.")
    } else {
        for(i=0;i<n;i++){
            dequeue(&(*Q), &v);
        }
        if(isEmpty(*Q)) {
            printf("Tidak ada game.")
        } else {
            printf("Loading ");
            printf("%s", HEAD(*Q));
            printf("...");
            STARTPLAYGAME();
        }
    }
}