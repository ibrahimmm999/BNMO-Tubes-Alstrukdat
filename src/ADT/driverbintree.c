#include "bintree.h"

int main()
{
    BinTree Pohon;
    BinTree Left;
    BinTree Right;

    Word satu, dua, tiga, empat, lima;

    satu.Length = 4;
    dua.Length = 3;
    tiga.Length = 4;
    empat.Length = 5;
    lima.Length = 4;

    satu.TabWord[0] = 'S';
    satu.TabWord[1] = 'a';
    satu.TabWord[2] = 't';
    satu.TabWord[3] = 'u';

    dua.TabWord[0] = 'D';
    dua.TabWord[1] = 'u';
    dua.TabWord[2] = 'a';

    tiga.TabWord[0] = 'T';
    tiga.TabWord[1] = 'i';
    tiga.TabWord[2] = 'g';
    tiga.TabWord[3] = 'a';

    empat.TabWord[0] = 'E';
    empat.TabWord[1] = 'm';
    empat.TabWord[2] = 'p';
    empat.TabWord[3] = 'a';
    empat.TabWord[4] = 't';

    lima.TabWord[0] = 'L';
    lima.TabWord[1] = 'i';
    lima.TabWord[2] = 'm';
    lima.TabWord[3] = 'a';

    Pohon = AlokNode(satu);
    Left(Pohon) = AlokNode(dua);
    Left(Left(Pohon)) = AlokNode(tiga);

    printf("Pohon:");
    PrintPreorder(Pohon);
    printf("\n");
    printf("NbDaun: %d\n", NbDaun(Pohon));
    printf("Level elemen berinfo 'Tiga': %d\n", Level(Pohon, tiga));
    printf("Tinggi: %d\n", Tinggi(Pohon));
    printf("Pohon kosong? %d\n", IsTreeEmpty(Pohon));                    // 0
    printf("Pohon berelemen satu? %d\n", IsTreeOneElmt(Pohon));          // 0
    printf("Ada elemen '20' di pohon? %d\n", SearchTree(Pohon, dua));    // 1
    printf("Ada elemen 'Lima' di pohon? %d\n", SearchTree(Pohon, lima)); // 0

    Right(Pohon) = AlokNode(empat);
    Right(Left(Pohon)) = AlokNode(lima);

    PrintPreorder(Pohon);
    printf("\nNbDaun: %d\n", NbDaun(Pohon));

    DelDaunTerkiri(&Pohon, &dua);
    PrintPreorder(Pohon);
    printf("\nNbDaun: %d\n", NbDaun(Pohon));

    DelDaun(&Pohon, satu);
    DelDaun(&Pohon, satu);
    DelDaun(&Pohon, satu);
    PrintPreorder(Pohon);
    printf("\n");
    AddDaunTerkiri(&Pohon, satu);
    PrintPreorder(Pohon);
    printf("\n");
    AddDaunTerkiri(&Pohon, tiga);
    AddDaunTerkiri(&Pohon, empat);
    AddDaunTerkiri(&Pohon, tiga);
    AddDaunTerkiri(&Pohon, tiga);
    AddDaunTerkiri(&Pohon, satu);
    AddDaunTerkiri(&Pohon, tiga);
    AddDaunTerkiri(&Pohon, empat);
    AddDaunTerkiri(&Pohon, tiga);
    AddDaunTerkiri(&Pohon, tiga);
    PrintPreorder(Pohon);
    printf("\nIs it skew left? %d\n", IsSkewLeft(Pohon)); // 1
    // PrintPreorder(Pohon);

    return 0;
}