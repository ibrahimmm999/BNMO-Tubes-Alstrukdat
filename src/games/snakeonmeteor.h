#ifndef SNAKEOFMETEOR_H
#define SNAKEOFMETEOR_H

#include "../ADT/listdp.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/point.h"
#include "../boolean.h"

void displayBoard(List snake, POINT food, POINT meteor);

POINT Food(List L);

POINT Meteor(POINT Food);

void move(List snake, char input, boolean *GameOver);

void FirstRandSnake(List *L);

void SnakeOfMeteor();

#endif