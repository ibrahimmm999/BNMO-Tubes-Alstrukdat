#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

int main()
{
    List L;
    CreateEmpty(&L);
    printf("%d", IsEmpty(L));

    POINT x = MakePOINT(1, 2);
    POINT y = MakePOINT(6, 3);
    address test = Alokasi('a', x);
    address test2 = Alokasi('b', y);
    InsVLast(&L, test->info, test->pos);
    InsVLast(&L, test2->info, test2->pos);

    return 0;
}
