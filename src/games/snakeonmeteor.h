#ifndef SNAKEOFMETEOR_H
#define SNAKEOFMETEOR_H

#include "../ADT/listdp.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/point.h"
#include "../boolean.h"

void printmap(List L, POINT M, POINT F);

POINT Food(List L);

POINT Meteor(POINT Food);

void UserMove(List L, char input, boolean *GameOver);

void FirstRandSnake(List *L);

void SnakeOfMeteor();

#endif