<<<<<<< HEAD
/*
Driver ADT setV2
gcc driversetV2.c setV2.c mapV2.c -o setV2
*/
#include "setV2.h"

int main() {
    Set S;
    MapV2 M, M2;
    valuetypeMapV2 val;
    infotypeSetV2 info;
    int i;
    char str[10], name[10];

    /*  Empty Set   */
    CreateEmptySet(&S);
    printf("%d\n", IsEmptySet(S));  // true 1

    /*  Full Set   */
    S.Count = MaxElsetV2;
    printf("%d\n", IsFullSet(S));   // true 1
    printf("%d\n", S.Count);        // = MaxEl (30)

    /*  Make Empty Map again  */
    CreateEmptySet(&S);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", S.Count);            // 0

    /*  Insert Elements  */
    CreateEmptyMapV2(&M);
    CreateEmptyMapV2(&M2);
    val.name = "abc";
    val.score = 12;
    InsertMapV2(&M, 0, val);
    val.name = "pqr";
    val.score = 99;
    InsertMapV2(&M, 1, val);
    val.name = "xyz";
    val.score = 8;
    InsertMapV2(&M2, 0, val);
    val.name = "tuv";
    val.score = 0;
    InsertMapV2(&M2, 1, val);
    val.name = "ghi";
    val.score = 100;
    InsertMapV2(&M2, 2, val);
    info.game = "game00";
    info.M = M;
    InsertSet(&S, info);
    info.game = "game01";
    info.M = M2;
    InsertSet(&S, info);
    printf("%d\n", IsEmptySet(S));      // false 0
    printf("%d\n", S.Count);            // 2
    InsertSet(&S, info);                // insert tidak dilakukan jika sudah member
    printf("%d\n", S.Count);            // tetap 2
    // game00 abc 12
    printf("%s %s %d\n", S.Elements[0].game, VName(S.Elements[0].M, 0), VScore(S.Elements[0].M, 0));
    // game00 pqr 99
    printf("%s %s %d\n", S.Elements[0].game, VName(S.Elements[0].M, 1), VScore(S.Elements[0].M, 1));
    // game01 ghi 100
    printf("%s %s %d\n", S.Elements[1].game, VName(S.Elements[1].M, 2), VScore(S.Elements[1].M, 2));

    /*  IsMember  */
    printf("%d\n", IsMemberOfSet(S, "game01"));    // true 1
    printf("%d\n", IsMemberOfSet(S, "game"));      // false 0

    /*  Delete Elements  */
    DeleteSet(&S, "game00");  // elemen ke 0 dihapus maka semua elemen geser ke kiri, elemen ke 2 kosong
    printf("%d\n", S.Count);                // 1
    printf("%d\n", IsMemberOfSet(S, "game00"));    // false 0
    DeleteSet(&S, "game02");  // elemen dengan game02 bukan member, maka set tetap
    printf("%d\n", S.Count);                // 1
    printf("%d\n", IsMemberOfSet(S, 0));    // true 0
    DeleteSet(&S, "game01");  // elemen ke 0 (satu-satunya) dihapus
    printf("%d\n", IsMemberOfSet(S, 0));    // false 0
    printf("%d\n", S.Count);                // 0
    printf("%d\n", IsEmptySet(S));          // true 1
}
=======
/*
Driver ADT setV2
gcc driversetV2.c setV2.c mapV2.c -o setV2
*/
#include "setV2.h"

int main() {
    Set S;
    MapV2 M, M2;
    valuetypeMapV2 val;
    infotypeSetV2 info;
    int i;
    char str[10], name[10];

    /*  Empty Set   */
    CreateEmptySet(&S);
    printf("%d\n", IsEmptySet(S));  // true 1

    /*  Full Set   */
    S.Count = MaxElsetV2;
    printf("%d\n", IsFullSet(S));   // true 1
    printf("%d\n", S.Count);        // = MaxEl (30)

    /*  Make Empty Map again  */
    CreateEmptySet(&S);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", S.Count);            // 0

    /*  Insert Elements  */
    CreateEmptyMapV2(&M);
    CreateEmptyMapV2(&M2);
    val.name = "abc";
    val.score = 12;
    InsertMapV2(&M, 0, val);
    val.name = "pqr";
    val.score = 99;
    InsertMapV2(&M, 1, val);
    val.name = "xyz";
    val.score = 8;
    InsertMapV2(&M2, 0, val);
    val.name = "tuv";
    val.score = 0;
    InsertMapV2(&M2, 1, val);
    val.name = "ghi";
    val.score = 100;
    InsertMapV2(&M2, 2, val);
    info.game = "game00";
    info.M = M;
    InsertSet(&S, info);
    info.game = "game01";
    info.M = M2;
    InsertSet(&S, info);
    printf("%d\n", IsEmptySet(S));      // false 0
    printf("%d\n", S.Count);            // 2
    InsertSet(&S, info);                // insert tidak dilakukan jika sudah member
    printf("%d\n", S.Count);            // tetap 2
    // game00 abc 12
    printf("%s %s %d\n", S.Elements[0].game, VName(S.Elements[0].M, 0), VScore(S.Elements[0].M, 0));
    // game00 pqr 99
    printf("%s %s %d\n", S.Elements[0].game, VName(S.Elements[0].M, 1), VScore(S.Elements[0].M, 1));
    // game01 ghi 100
    printf("%s %s %d\n", S.Elements[1].game, VName(S.Elements[1].M, 2), VScore(S.Elements[1].M, 2));

    /*  IsMember  */
    printf("%d\n", IsMemberOfSet(S, "game01"));    // true 1
    printf("%d\n", IsMemberOfSet(S, "game"));      // false 0

    /*  Delete Elements  */
    DeleteSet(&S, "game00");  // elemen ke 0 dihapus maka semua elemen geser ke kiri, elemen ke 2 kosong
    printf("%d\n", S.Count);                // 1
    printf("%d\n", IsMemberOfSet(S, "game00"));    // false 0
    DeleteSet(&S, "game02");  // elemen dengan game02 bukan member, maka set tetap
    printf("%d\n", S.Count);                // 1
    printf("%d\n", IsMemberOfSet(S, 0));    // true 0
    DeleteSet(&S, "game01");  // elemen ke 0 (satu-satunya) dihapus
    printf("%d\n", IsMemberOfSet(S, 0));    // false 0
    printf("%d\n", S.Count);                // 0
    printf("%d\n", IsEmptySet(S));          // true 1
}
>>>>>>> a5e657f09f48af825ed6e63ee21b747b2bb108b7
