#ifndef _HANGMAN_
#define _HANGMAN_

#include "../ADT/set.h"
#include <stdlib.h>
#include "../ADT/array.h"

/* Main menu hangman */
void hangman();

/* Mengecek apakah input hanya terdiri dari huruf saja */
boolean isInputValid(Word w);

/* Mengecek jika kata sudah ada di list kata */
boolean isWordExist(Arr guessWords, Word w);

/* Fungsi utama untuk memainkan hangman */
void hangman_game(Arr guessWords);

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

/* Menambah kata tebakan dan menyimpan ke file hangman.txt*/
void save_hangman(char *file_name, Arr list_game);

/* Mengambil daftar kata tebakan dari file txt dan menyimpan
   daftar kata pada array */
void generateWordList(Arr *word);

/* Mencetak banner hangman */
void displayHangmanTextArt();

/* Mencetak gambar kondisi hangman */
void hangmanPics(int chance);

/* Mencetak pesan kemenangan */
void winMessage();

#endif