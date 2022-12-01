#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../boolean.h"
#include "../ADT/stack.h"

#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

boolean isWin(Stack s, int temp);
// Mengecek kemenangan

void Tower(int x);
// Berbagai macam tower

void Alas();
// Alas tower

void DisplayTower(Stack S, Stack S2, Stack S3, int disk);
// Print tower

boolean MoveValid(Stack S1, Stack S2);
// Mengecek apakah perpindahan dapat dilakukan

void Pindah(Stack *A, Stack *B);
// Memindahkan piring dari stack 1 ke stack 2

void TowerOfHanoi();
// Permainannya

#endif