#include "set.h"

// gcc set.c mesinkarakter.c mesinkata.c driverset.c -o main
int main()
{
    Set test;
    Word testWord, testWord2;

    testWord.TabWord[0] = 't';
    testWord.TabWord[1] = 'u';
    testWord.TabWord[2] = 'b';
    testWord.TabWord[3] = 'e';
    testWord.TabWord[4] = 's';
    testWord.Length = 5;

    testWord2.TabWord[0] = 'h';
    testWord2.TabWord[1] = 'a';
    testWord2.TabWord[2] = 'l';
    testWord2.TabWord[3] = 'o';
    testWord2.Length = 4;

    CreateSet(&test);
    printf("%d\n", IsEmpty(test)); // 1
    Insert(&test, testWord);
    printf("%d\n", IsEmpty(test));             // 0
    printf("%d\n", IsMember(test, testWord));  // 1
    printf("%d\n", IsMember(test, testWord2)); // 0
    Insert(&test, testWord2);
    printf("%d\n", IsEmpty(test));             // 0
    printf("%d\n", IsMember(test, testWord2)); // 1
    Delete(&test, testWord);
    printf("%d\n", IsEmpty(test));             // 0
    printf("%d\n", IsMember(test, testWord));  // 0
    printf("%d\n", IsMember(test, testWord2)); // 1
    Delete(&test, testWord);
    printf("%d\n", IsEmpty(test));             // 0
    printf("%d\n", IsMember(test, testWord));  // 0
    printf("%d\n", IsMember(test, testWord2)); // 1
    Delete(&test, testWord2);
    printf("%d\n", IsEmpty(test));             // 1
    printf("%d\n", IsMember(test, testWord));  // 0
    printf("%d\n", IsMember(test, testWord2)); // 0

    return 0;
}