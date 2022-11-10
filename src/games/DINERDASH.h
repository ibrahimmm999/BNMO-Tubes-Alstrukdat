/* file: DINERDASH.h */

#ifndef _DINER_DASH_H_
#define _DINER_DASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queueV2.h"
#include "array.h"
#include "mesinkata.h"
#include "boolean.h"
#include "converter.h"

#define SPACE ' '
/* gcc DINERDASH.c queueV2.c array.c mesinkata.c mesinkarakter.c converter.c */

typedef struct {
    Queue order;
    Queue time;
    Queue exp;
    Queue price;
    int length;
    int totalCust;
} QueueDD;

typedef struct {
    Arr order;
    Arr time;
    int length;
} IsBeingCooked;

typedef struct {
    Arr order;
    Arr exp;
    int length;
} ReadyToServe;

QueueDD createEmptyQueueDD (QueueDD *q);

IsBeingCooked createEmptyIsBeingCooked (IsBeingCooked *c);

ReadyToServe createEmptyReadyToServe (ReadyToServe *s);

int randNumber(int max, int min);

int randPrice();

int randTime();

int randExp();

void newOrder(QueueDD q, Word *w);

void custComing(QueueDD *q);

void openRestaurant(QueueDD *q);

boolean commandValid(Word currentWord);

Word getCommand(Word currentWord, Word *com);

Word getOrder(Word currentWord, Word *ord);

void oneRound(QueueDD *q, IsBeingCooked *c, ReadyToServe *s); // include =========== (border)

void displayQueueDD(QueueDD q);

void displayCook(IsBeingCooked c);

void displayServe(ReadyToServe s);

void displayAll(QueueDD q, IsBeingCooked c, ReadyToServe s, int saldo);

boolean isFirstQueue(QueueDD q, Word currentWord);

boolean isInServe(ReadyToServe s, Word currentword);

boolean isInCook(IsBeingCooked c, Word currentword);

boolean isInQueueDD(QueueDD q, Word currentword);

boolean canBeServed(QueueDD q, ReadyToServe s, Word currentword);

boolean canCook(QueueDD q, IsBeingCooked c, Word currentWord);

void searchInQueue(QueueDD q, Word currentWord, int *idx);

void searchInServe(ReadyToServe s, Word currentWord, int *idx);

void COOK(QueueDD q, IsBeingCooked *c, Word currentWord);

void SERVE(QueueDD *q, ReadyToServe *s, Word currentWord, int *payment);

void delServeAt(ReadyToServe *s, int x);

void moveFoodAt(QueueDD q, IsBeingCooked *c, ReadyToServe *s, Word currentWord, int y);

void DINERDASH();

#endif