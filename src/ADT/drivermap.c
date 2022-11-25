#include "map.h"

// gcc drivermap.c map.c mesinkarakter.c mesinkata.c -o map

int main(){
    Map M;
    Word name, test;
    name.TabWord[0] = 'c';
    name.TabWord[1] = 'o';
    name.TabWord[2] = 'b';
    name.TabWord[3] = 'a';
    name.Length = 4;

    test.TabWord[0] = 't';
    test.TabWord[1] = 'e';
    test.TabWord[2] = 's';
    test.TabWord[3] = 't';
    test.Length = 4;

    CreateMap(&M);
    printf("%d\n", IsEmpty(M)); // 1
    printf("%d\n", IsMember(M, name)); // 0
    Insert(&M, name, 100);
    printf("%d\n", IsMember(M, name)); // 1
    printf("%d\n", IsEmpty(M)); // 0
    printf("%d\n", Value(M, name)); // 100
    Insert(&M, name, 200);
    printf("%d\n", Value(M, name)); // 100
    printf("%d\n", IsMember(M, test)); // 0
    Insert(&M, test, 50);
    printf("%d\n", IsMember(M, test)); // 1
    printf("%d\n", Value(M, test)); // 50
    Delete(&M, name);
    printf("%d\n", IsMember(M, name)); // 0
    printf("%d\n", IsMember(M, test)); // 1
    printf("%d\n", IsEmpty(M)); // 0
    Delete(&M, test);
    printf("%d\n", IsMember(M, test)); // 0
    printf("%d\n", IsEmpty(M)); // 1
}