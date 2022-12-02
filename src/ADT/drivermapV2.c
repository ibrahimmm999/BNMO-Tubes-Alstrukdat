<<<<<<< HEAD
/*
Driver ADT mapV2
gcc drivermapV2.c mapV2.c -o mapV2
*/
#include "mapV2.h"


int main() {
    MapV2 M;
    int i;
    valuetypeMapV2 val;
    
    /*  Empty Map  */
    CreateEmptyMapV2(&M);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", IsMapFullV2(M));     // false 0
    printf("%d\n", M.Count);            // 0

    /*  Full Map  */
    for (i = 0; i < MaxElMapV2; i++) {
        val.name = "";
        val.score = i;
        InsertMapV2(&M, i, val);
    }
    printf("%d\n", IsMapFullV2(M));     // true 1
    printf("%d\n", M.Count);            // = MaxEl (30)

    /*  Make Empty Map again  */
    CreateEmptyMapV2(&M);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", M.Count);            // 0

    /*  Insert Elements  */
    val.name = "abc";
    val.score = 12;
    InsertMapV2(&M, 0, val);
    val.name = "pqr";
    val.score = 99;
    InsertMapV2(&M, 1, val);
    val.name = "xyz";
    val.score = 8;
    InsertMapV2(&M, 2, val);
    printf("%d\n", IsMapEmptyV2(M));    // false 0
    printf("%d\n", M.Count);            // 3

    /*  NameExist  */
    printf("%d\n", NameExist(M, "abc"));    // true 1
    printf("%d\n", NameExist(M, "def"));    // false 0

    /*  IsMember  */
    printf("%d\n", IsMemberMapV2(M, 0));    // true 1
    printf("%d\n", IsMemberMapV2(M, 5));    // false 0

    /*  Check Values (Value, VName, VScore)  */
    printf("%s %d\n", ValueMapV2(M, 0).name, ValueMapV2(M, 0).score); // abc 12
    printf("%s\n", VName(M, 1));                            // pqr
    printf("%d\n", VScore(M, 2));                           // 8

    /*  Delete Elements  */
    DeleteMapV2(&M, 0);  // elemen ke 0 dihapus maka semua elemen geser ke kiri, elemen ke 2 kosong
    printf("%d\n", M.Count);                // 2
    printf("%d\n", IsMemberMapV2(M, 2));    // false 0
    DeleteMapV2(&M, 1);  // elemen ke 1 (last) dihapus
    printf("%d\n", M.Count);                // 1
    printf("%d\n", IsMemberMapV2(M, 1));    // false 0
    DeleteMapV2(&M, 0);  // elemen ke 0 (satu-satunya) dihapus
    printf("%d\n", IsMemberMapV2(M, 0));    // false 0
    printf("%d\n", M.Count);                // 0
    printf("%d\n", IsMapEmptyV2(M));        // true 1
=======
/*
Driver ADT mapV2
gcc drivermapV2.c mapV2.c -o mapV2
*/
#include "mapV2.h"


int main() {
    MapV2 M;
    int i;
    valuetypeMapV2 val;
    
    /*  Empty Map  */
    CreateEmptyMapV2(&M);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", IsMapFullV2(M));     // false 0
    printf("%d\n", M.Count);            // 0

    /*  Full Map  */
    for (i = 0; i < MaxElMapV2; i++) {
        val.name = "";
        val.score = i;
        InsertMapV2(&M, i, val);
    }
    printf("%d\n", IsMapFullV2(M));     // true 1
    printf("%d\n", M.Count);            // = MaxEl (30)

    /*  Make Empty Map again  */
    CreateEmptyMapV2(&M);
    printf("%d\n", IsMapEmptyV2(M));    // true 1
    printf("%d\n", M.Count);            // 0

    /*  Insert Elements  */
    val.name = "abc";
    val.score = 12;
    InsertMapV2(&M, 0, val);
    val.name = "pqr";
    val.score = 99;
    InsertMapV2(&M, 1, val);
    val.name = "xyz";
    val.score = 8;
    InsertMapV2(&M, 2, val);
    printf("%d\n", IsMapEmptyV2(M));    // false 0
    printf("%d\n", M.Count);            // 3

    /*  NameExist  */
    printf("%d\n", NameExist(M, "abc"));    // true 1
    printf("%d\n", NameExist(M, "def"));    // false 0

    /*  IsMember  */
    printf("%d\n", IsMemberMapV2(M, 0));    // true 1
    printf("%d\n", IsMemberMapV2(M, 5));    // false 0

    /*  Check Values (Value, VName, VScore)  */
    printf("%s %d\n", ValueMapV2(M, 0).name, ValueMapV2(M, 0).score); // abc 12
    printf("%s\n", VName(M, 1));                            // pqr
    printf("%d\n", VScore(M, 2));                           // 8

    /*  Delete Elements  */
    DeleteMapV2(&M, 0);  // elemen ke 0 dihapus maka semua elemen geser ke kiri, elemen ke 2 kosong
    printf("%d\n", M.Count);                // 2
    printf("%d\n", IsMemberMapV2(M, 2));    // false 0
    DeleteMapV2(&M, 1);  // elemen ke 1 (last) dihapus
    printf("%d\n", M.Count);                // 1
    printf("%d\n", IsMemberMapV2(M, 1));    // false 0
    DeleteMapV2(&M, 0);  // elemen ke 0 (satu-satunya) dihapus
    printf("%d\n", IsMemberMapV2(M, 0));    // false 0
    printf("%d\n", M.Count);                // 0
    printf("%d\n", IsMapEmptyV2(M));        // true 1
>>>>>>> a5e657f09f48af825ed6e63ee21b747b2bb108b7
}