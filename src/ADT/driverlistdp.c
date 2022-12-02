#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

int main()
{
    ListDP L;
    printf("List kosong\n");
    CreateEmptyListdp(&L);
    printf("Is Empty = %d\n", IsEmptyListdp(L));

    // Alokasi
    POINT Y = MakePOINT(1, 2);
    addressLDP P = AlokasiListdp(3, Y);
    printf("%d\n", Info(P));
    DealokasiListdp(P);

    // Insert To List
    InsVLast(&L, 1, Y);
    Y = MakePOINT(1, 3);
    InsVLast(&L, 2, Y);
    Y = MakePOINT(1, 5);
    InsVLast(&L, 3, Y);
    Y = MakePOINT(1, 6);
    InsVLast(&L, 4, Y);
    printf("print forward: ");
    PrintForwardListdp(L);
    printf("\nprint backward: ");
    PrintBackwardListdp(L);
    printf("\n");

    // Search List
    POINT T = MakePOINT(1, 5);
    addressLDP Q = Search(L, T);
    printf("%d\n", Info(Q));

    // Delete
    DelP(&L, T);
    PrintForwardListdp(L);
    DelFirst(&L, &P);
    PrintForwardListdp(L);
    DelLast(&L, &P);
    PrintForwardListdp(L);

    DealokasiListdp(P);
    DealokasiListdp(Q);

    return 0;
}