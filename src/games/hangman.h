#ifndef _HANGMAN_
#define _HANGMAN_

#include "../ADT/set.h"
#include <stdlib.h>
#include "../ADT/array.h"

void hangman();

void playHangman(int *chance, Word currentGuess, Set *guessedAlphabet);

boolean IsRoundFinished(char* guessTemp, Word currentGuess);

void underscoreToAlphabet(char c, char *guessTemp, Word currentGuess);

boolean IsAlphabetExist(char c, Word currentGuess);

void printStringWithSpace(char* str, int len);

void generateWordList(Arr *word);

#endif