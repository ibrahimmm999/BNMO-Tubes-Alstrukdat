#ifndef SNAKEONMETEOR_H
#define SNAKEONMETEOR_H

#include "../ADT/listdp.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/point.h"
#include "../boolean.h"

void displayBoard(ListDP snake, POINT food, POINT meteor);

POINT Food(ListDP L);

POINT Meteor(POINT Food);

void move(ListDP snake, char input, POINT food, POINT meteor);

void FirstRandSnake(ListDP *L);

void SnakeOnMeteor(int *score);

#endif