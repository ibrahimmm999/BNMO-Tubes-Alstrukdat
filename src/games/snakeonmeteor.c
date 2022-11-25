#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "snakeonmeteor.h"

void displayBoard(List snake, POINT food, POINT meteor)
{
    int x, y;
    address current;
    printf("\n-------------------------------\n");
    for (y = 0; y < 5; y++)
    {
        printf("|");
        for (x = 0; x < 5; x++)
        {
            POINT currentPoint = MakePOINT(x, y);
            current = Search(snake, currentPoint);
            if (x == food.x && y == food.y)
            {
                if ((food.x == snake.First->pos.x) && (food.y == snake.First->pos.y))
                {
                    printf("  H  |");
                }
                else
                {
                    printf("  O  |");
                }
            }
            else if (x == meteor.x && y == meteor.y)
            {
                printf("  m  |");
            }
            else
            {
                if (current != Nil)
                {
                    if (current == snake.First)
                    {
                        printf("  H  |");
                    }
                    else
                    {
                        if (current->info < 10)
                        {
                            printf("  %d  |", current->info);
                        }
                        else
                        {
                            printf(" %d  |", current->info);
                        }
                    }
                }
                else
                {
                    printf("     |");
                }
            }
        }
        printf("\n-------------------------------\n");
    }
    printf("\n__________________________________________\n");
}

POINT Food(List L)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while (Search(L, P) != Nil)
    {
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

POINT Meteor(POINT Food)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while (P.x == Food.x && P.y == Food.y)
    {
        P.x = rand() % 5;
        P.y = rand() % 5;
    }
    return P;
}

void move(List snake, char input, boolean *GameOver)
{
    address P = First(snake);
    *GameOver = false;
    POINT Temp;
    if (input == 'w')
    {
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 4) % 5;
    }
    else if (input == 'a')
    {
        Temp.x = (Pos(P).x + 4) % 5;
        Temp.y = Pos(P).y % 5;
    }
    else if (input == 's')
    {
        Temp.x = Pos(P).x % 5;
        Temp.y = (Pos(P).y + 1) % 5;
    }
    else if (input == 'd')
    {
        Temp.x = (Pos(P).x + 1) % 5;
        Temp.y = Pos(P).y % 5;
    }
    if (Search(snake, Temp) != Nil)
    {
        printf("\nKepala snake menabrak badan\n");
        *GameOver = true;
    }
    else
    {
        address Q;
        P = Last(snake);
        while (P != First(snake))
        {
            Q = Prev(P);
            Pos(P).x = Pos(Q).x;
            Pos(P).y = Pos(Q).y;
            P = Prev(P);
        }
        Pos(P).x = Temp.x;
        Pos(P).y = Temp.y;
    }
}

void SnakeOfMeteor()
{
    List snake;
    POINT temp;
    struct tm *ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    CreateEmpty(&snake);
    printf("\nSelamat datang di snake on meteor!\n");
    printf("\nMengenerate peta, snake dan makanan . . .\n");
    printf("\nBerhasil digenerate!\n");
    printf("\n__________________________________________\n");
    srand(time(NULL));
    InsVLast(&snake, 0, MakePOINT((rand() * ptr->tm_sec) % 5, rand() % 5));
    address current = snake.First;
    int x = current->pos.x;
    int y = current->pos.y;
    if (x == 0)
    {
        if (y == 0)
        {
            y++;
        }
        else
        {
            y--;
        }
    }
    else
    {
        x--;
    }
    POINT p = MakePOINT(x, y);
    InsVLast(&snake, 1, p);
    current = current->next;
    if (x == 0)
    {
        if (y == 0 && x == 0)
        {
            if (snake.First->pos.x == 0)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        else if (snake.First->pos.x == 0 && snake.First->pos.y == 0)
        {
            y++;
        }
        else
        {
            y--;
        }
    }
    else
    {
        x--;
    }
    p = MakePOINT(x, y);
    InsVLast(&snake, 2, p);
    POINT food = Food(snake);
    POINT meteor = MakePOINT(-1, -1);
    POINT prevMeteor = MakePOINT(meteor.x, meteor.y);
    displayBoard(snake, food, meteor);
    int lenSnake = 3;
    int turn = 1;
    boolean GameOver = false;
    boolean isMeteorOnHead = false;
    while (!GameOver)
    {
        printf("TURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        STARTSTDIN();
        printf("\n");
        boolean cekInput = false;
        while (!cekInput)
        {
            if ((!IsWordEqual(currentWord, "a") && !IsWordEqual(currentWord, "w") && !IsWordEqual(currentWord, "s") && !IsWordEqual(currentWord, "d")) || currentWord.Length != 1)
            {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                printf("Silahkan masukkan command anda: ");
                STARTSTDIN();
                printf("\n");
            }
            else
            {
                if ((IsWordEqual(currentWord, "a") && (snake.First->next->pos.x == snake.First->pos.x - 1) && (snake.First->next->pos.y == snake.First->pos.y)) || (IsWordEqual(currentWord, "d") && (snake.First->next->pos.x == snake.First->pos.x + 1) && (snake.First->next->pos.y == snake.First->pos.y)) || (IsWordEqual(currentWord, "w") && (snake.First->next->pos.x == snake.First->pos.x) && (snake.First->next->pos.y == snake.First->pos.y - 1)) || (IsWordEqual(currentWord, "s") && (snake.First->next->pos.x == snake.First->pos.x) && (snake.First->next->pos.y == snake.First->pos.y + 1)))
                {
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n");
                    printf("Silahkan masukkan command anda: ");
                    STARTSTDIN();
                    printf("\n");
                }
                else
                {
                    cekInput = true;
                }
                if (((IsWordEqual(currentWord, "a") && (prevMeteor.x == snake.First->pos.x - 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "d") && (prevMeteor.x == snake.First->pos.x + 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "s") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y + 1))) || ((IsWordEqual(currentWord, "w") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y - 1))))
                {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\nSilahkan masukkan command lainnya\n");
                    printf("Silahkan masukkan command anda: ");
                    STARTSTDIN();
                    printf("\n");
                }
                else
                {
                    cekInput = true;
                }
            }
        }
        temp = GetLastPos(snake);
        move(snake, currentWord.TabWord[0], &GameOver);
        if (Pos(First(snake)).x == food.x && Pos(First(snake)).y == food.y)
        {
            InsVLast(&snake, lenSnake, temp);
            lenSnake++;
            food = Food(snake);
        }
        meteor = Meteor(food);
        prevMeteor.x = meteor.x;
        prevMeteor.y = meteor.y;
        if (!GameOver)
        {
            displayBoard(snake, food, meteor);
        }
        if (Search(snake, meteor) != Nil)
        {
            if (Pos(First(snake)).x == meteor.x && Pos(First(snake)).y == meteor.y)
            {
                isMeteorOnHead = true;
                GameOver = true;
            }
            DelP(&snake, meteor);
            lenSnake--;
        }
        turn++;
    }
    if (isMeteorOnHead)
    {
        printf("\nKepala snake terkena meteor\n");
    }
    printf("===== GAME OVER =====\n");
}
/*
int main()
{
    SnakeOfMeteor();
}
*/