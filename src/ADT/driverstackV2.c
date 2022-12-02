#include "stackV2.h"

int main()
{
    /* Kamus */
    Word X, Y, Z, info;
    StackW IniStack, reverse1, reverse2;
    /* Algoritma */
    X.Length = 5;
    X.TabWord[0] = 'H';
    X.TabWord[1] = 'u';
    X.TabWord[2] = 'r';
    X.TabWord[3] = 'u';
    X.TabWord[4] = 'f';

    Y.Length = 4;
    Y.TabWord[0] = 'W';
    Y.TabWord[1] = 'o';
    Y.TabWord[2] = 'r';
    Y.TabWord[3] = 'd';

    Z.Length = 4;
    Z.TabWord[0] = 'K';
    Z.TabWord[1] = 'a';
    Z.TabWord[2] = 't';
    Z.TabWord[3] = 'a';

    CreateEmptyStack(&IniStack);
    CreateEmptyStack(&reverse1);
    CreateEmptyStack(&reverse2);

    if (IsStackEmptyV2)
    {
        printf("Stack masih kosong.\n");
    }

    PushStack(&IniStack, X);
    printf("Length IniStack: %d\n", lengthStack(IniStack));
    PushStack(&IniStack, Y);
    printf("Length IniStack: %d\n", lengthStack(IniStack));
    PushStack(&IniStack, Z);
    printf("Length IniStack: %d\n", lengthStack(IniStack));
    printf("IniStack penuh? %d\n", IsStackFull(IniStack)); // 0

    printf("IniStack:\n");
    CetakStack(IniStack, 10);

    printf("IniStack setelah dibalik:\n");
    ReverseStack(IniStack, &reverse1);
    CetakStack(reverse1, 10);

    printf("IniStack setelah di-Pop satu elemen:\n");
    PopStack(&IniStack, &info);
    CetakStack(IniStack, 8);
    printf("Length IniStack: %d\n", lengthStack(IniStack));

    printf("IniStack dengan CetakStack(IniStack, 4):\n");
    PushStack(&IniStack, X);
    PushStack(&IniStack, X);
    PushStack(&IniStack, Y);
    CetakStack(IniStack, 4);

    PopAllStack(&IniStack);
    if (IsStackEmptyV2)
    {
        printf("Kini Stack kosong setelah di-PopAll.\n");
    }
    return 0;
}
