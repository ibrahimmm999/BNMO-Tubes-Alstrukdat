#include <stdio.h>
#include "bintree.h"

int main() {
    BinTree Pohon, Left, Right;
    Word Akar, Ga, Hmm, Yes;

    Akar.TabWord[0] = 'Y';
    Akar.TabWord[1] = 'a';
    Akar.Length = 2;

    Ga.TabWord[0] = 'G';
    Ga.TabWord[1] = 'a';
    Ga.Length = 2;

    Hmm.TabWord[0] = 'H';
    Hmm.TabWord[1] = 'm';
    Hmm.TabWord[2] = 'm';
    Hmm.Length = 3;

    Yes.TabWord[0] = 'Y';
    Yes.TabWord[1] = 'e';
    Yes.TabWord[2] = 's';
    Yes.Length = 3;

    Pohon = Nil;
    PrintPreorder(Pohon);
    Left = AlokNode(Ga);
    Right = AlokNode(Hmm);
    Pohon = Tree(Akar, Left, Right);

    PrintPreorder(Pohon);

    if(IsTreeEmpty(Pohon))
    {
        printf("\nPohon kosong.\n");
    } else {
        printf("\nPohon tidak kosong.\n");
    }

    AddDaun(&Pohon, Hmm, Yes, false);
    PrintPreorder(Pohon);

    if(IsTreeOneElmt(Pohon))
    {
        printf("\nPohon hanya berisi satu elemen.\n");
    }
    else
    {
        printf("\nPohon berisi lebih dari satu elemen.\n");
    }

    if(IsBiner)
    {
        printf("\nPohon merupakan pohon biner.\n");
    }
    
   /* if(SearchTree(Pohon, Ga))
    {
        printf("Ada elemen dengan info 'Ga' dalam pohon.\n");
    } */

    printf("Banyak elemen Pohon: %d\n", NbElmt(Pohon));
    printf("Banyak daun Pohon: %d\n", NbDaun(Pohon));
   // printf("Level node bernilai 2: %d\n", Level(Pohon, Yes));
    printf("Tinggi Pohon: %d\n", Tinggi(Pohon));

    // AddDaun(&Pohon, 2, 5, false);
    // AddDaun(&Pohon, 8, 10, true);
    /* AddDaun(&Pohon, 8, 5, false);
    PrintPreorder(Pohon);

    // AddDaun(&Pohon, 10, 5, false);
    DelDaun(&Pohon, 10);
    PrintPreorder(Pohon); */

    return 0;

}