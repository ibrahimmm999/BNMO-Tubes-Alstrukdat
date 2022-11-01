#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

void rng()
{
    srand(time(NULL));
    int x = rand();
    int tebakan;
    boolean cek = false;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebakan);
    while (tebakan != x)
    {
        if (tebakan > x)
        {
            printf("Lebih kecil\n");
        }
        else if (tebakan < x)
        {
            printf("Lebih besar\n");
        }
        printf("Tebakan: ");
        scanf("%d", &tebakan);
    }
    printf("\nYa, X adalah %d.\n", x);
}
