#ifndef __GPP__
#define __GPP__

#include <stdio.h>
#include <time.h>
#include "rng.h"
#include "../boolean.h"
#include "../ADT/bintree.h"
#include "../ADT/mesinkata.h"
#include "../ADT/listV2.h"

int generate(int i, int max, int min);

void getInfo(BinTree Tree, int idx, int *i, Word *info);

void relation(ListV2 listFam, Word checked, int idxSusPP, int *n);

void TheClue(Word who, Word clue, Word checked);

void PrintFamTree(BinTree FamTree);

void GPP(int *score);

#endif