#ifndef _HANGMAN_
#define _HANGMAN_

#include "../ADT/set.h"
#include <stdlib.h>
#include "../ADT/array.h"

/* Fungsi utama untuk memainkan hangman */
void hangman();

/* Memainkan satu ronde hangman*/
void playHangman(int *chance, Word currentGuess, Set *guessedAlphabet);

/* Mengubah huruf kecil menjadi huruf kapital */
void charUpper(Word *w);

/* Mengubah huruf kapital menjadi huruf kecil */
void charLower(Word *w);

/* Mengecek apakah semua huruf dalam kata sudah tertebak.
   Mengembalikan true jika semua huruf sudah tertebak*/
boolean IsRoundFinished(char* guessTemp, Word currentGuess);

/* Mengubah underscore menjadi huruf yang berhasil ditebak */
void underscoreToAlphabet(char c, char *guessTemp, Word currentGuess);

/* Mengecek apakah huruf terdapat dalam kata yang harus ditebak.
   Mengembalikan true apabila huruf ada dalam kata */
boolean IsAlphabetExist(char c, Word currentGuess);

/* Mencetak string dengan spasi setelah setiap karakter */
void printStringWithSpace(char* str, int len);

/* Mengambil daftar kata tebakan dari file txt dan menyimpan
   daftar kata pada array */
void generateWordList(Arr *word);

/* Mencetak banner hangman */
void displayHangmanTextArt();

#endif