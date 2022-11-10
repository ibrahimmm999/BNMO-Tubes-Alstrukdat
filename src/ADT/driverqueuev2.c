#include <stdio.h>

#include "queueV2.h"
#include "mesinkata.h"

int main()
{
    Queue test;
    Word testWord;
    Word testWord2;
    testWord.TabWord[0] = 'h';
    testWord.TabWord[1] = 'a';
    testWord.TabWord[2] = 'l';
    testWord.TabWord[3] = 'o';
    testWord.Length = 4;

    testWord2.TabWord[0] = 'p';
    testWord2.TabWord[1] = 'p';
    testWord2.TabWord[2] = 'p';
    testWord2.Length = 3;
    CreateQueue(&test);
    printf("%d\n", isEmpty(test));
    printf("%d\n", length(test));
    enqueue(&test, testWord);
    printf("%d\n", isEmpty(test));
    printf("%d\n", length(test));
    enqueue(&test, testWord2);
    printf("%d\n", length(test));
    displayQueue(test);
    dequeue(&test, &testWord);
    displayQueue(test);
}