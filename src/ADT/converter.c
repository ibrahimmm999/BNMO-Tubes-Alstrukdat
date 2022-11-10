#include "converter.h"
#include "queueV2.h"
#include <stdio.h>

char nConversion(int n){
    /* Kamus */
    Word num;
    char nConv;
    /* Algoritma */
    num.Length = 10;
    num.TabWord[0] = '0'; num.TabWord[1] = '1'; num.TabWord[2] = '2'; num.TabWord[3] = '3'; num.TabWord[4] = '4';
    num.TabWord[5] = '5'; num.TabWord[6] = '6'; num.TabWord[7] = '7'; num.TabWord[8] = '8'; num.TabWord[9] = '9';
    return(nConv = num.TabWord[n]);
    
}

void convert(Word *w, int n){
    /* Kamus */
    int ctr = 0;
    int i = 0;
    int j = 0;
    int num[100];
    /* Algoritma */
    (*w).Length = 0;
    while(n != 0){
        num[i] = n % 10;
        n /= 10;
        ctr++;
        i++;
    }
    (*w).Length = ctr;
    for(i = ctr-1; i >= 0; i--){
        (*w).TabWord[j] = nConversion(num[i]);
        (*w).Length++;
        j++;
    }
}