#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "snakeonmeteor.h"

void displayBoard(ListDP snake, POINT food, POINT meteor)
{
    int x, y;
    addressLDP current;
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
                if (current != NilLDP)
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

POINT Food(ListDP L)
{
    POINT P;
    srand(time(NULL));
    P.x = rand() % 5;
    P.y = rand() % 5;
    while (Search(L, P) != NilLDP)
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

void move(ListDP snake, char input, POINT food, POINT meteor)
{
    addressLDP P = First(snake);
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

    if (Search(snake, Temp) == NilLDP)
    {
        printf("Anda terkena meteor!\n");
        addressLDP Q;
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

void SnakeOnMeteor(int *score)
{
    ListDP snake;
    *score = 0;
    POINT temp, temp1, temp2, temp3, temp4;
    struct tm *ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    CreateEmptyListdp(&snake);
    printf("\nSelamat datang di snake on meteor!\n");
    printf("\nMengenerate peta, snake dan makanan . . .\n");
    printf("\nBerhasil digenerate!\n");
    printf("\n__________________________________________\n");
    srand(time(NULL));
    InsVLast(&snake, 0, MakePOINT((rand() * ptr->tm_sec) % 5, rand() % 5));
    addressLDP current = snake.First;
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
    boolean isMeteorOnBody = false;
    while (!GameOver)
    {
        printf("TURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        STARTSTDIN();
        printf("\n");
        boolean cekInput = false;
        addressLDP P = First(snake);
        POINT TempP;
        if (IsWordEqual(currentWord, "w"))
        {
            TempP.x = Pos(P).x % 5;
            TempP.y = (Pos(P).y + 4) % 5;
        }
        else if (IsWordEqual(currentWord, "a"))
        {
            TempP.x = (Pos(P).x + 4) % 5;
            TempP.y = Pos(P).y % 5;
        }
        else if ((IsWordEqual(currentWord, "s")))
        {
            TempP.x = Pos(P).x % 5;
            TempP.y = (Pos(P).y + 1) % 5;
        }
        else if ((IsWordEqual(currentWord, "d")))
        {
            TempP.x = (Pos(P).x + 1) % 5;
            TempP.y = Pos(P).y % 5;
        }
        while (((!IsWordEqual(currentWord, "a") && !IsWordEqual(currentWord, "w") && !IsWordEqual(currentWord, "s") && !IsWordEqual(currentWord, "d")) || currentWord.Length != 1) || ((Search(snake, TempP) != NilLDP)) || (((IsWordEqual(currentWord, "a") && (prevMeteor.x == snake.First->pos.x - 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "d") && (prevMeteor.x == snake.First->pos.x + 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "s") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y + 1))) || ((IsWordEqual(currentWord, "w") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y - 1)))))
        {
            if (cekInput)
            {
                STARTSTDIN();

                if (IsWordEqual(currentWord, "w"))
                {
                    TempP.x = Pos(P).x % 5;
                    TempP.y = (Pos(P).y + 4) % 5;
                }
                else if (IsWordEqual(currentWord, "a"))
                {
                    TempP.x = (Pos(P).x + 4) % 5;
                    TempP.y = Pos(P).y % 5;
                }
                else if ((IsWordEqual(currentWord, "s")))
                {
                    TempP.x = Pos(P).x % 5;
                    TempP.y = (Pos(P).y + 1) % 5;
                }
                else if ((IsWordEqual(currentWord, "d")))
                {
                    TempP.x = (Pos(P).x + 1) % 5;
                    TempP.y = Pos(P).y % 5;
                }
            }
            if ((!IsWordEqual(currentWord, "a") && !IsWordEqual(currentWord, "w") && !IsWordEqual(currentWord, "s") && !IsWordEqual(currentWord, "d")) || currentWord.Length != 1)
            {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                printf("Silahkan masukkan command anda: ");
                cekInput = true;
                printf("\n");
            }
            else
            {
                if ((Search(snake, TempP) != NilLDP))
                {
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n");
                    printf("Silahkan masukkan command anda: ");
                    cekInput = true;
                    printf("\n");
                }
                // ((IsWordEqual(currentWord, "a") && (prevMeteor.x == snake.First->pos.x - 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "d") && (prevMeteor.x == snake.First->pos.x + 1) && (prevMeteor.y == snake.First->pos.y))) || ((IsWordEqual(currentWord, "s") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y + 1))) || ((IsWordEqual(currentWord, "w") && (prevMeteor.x == snake.First->pos.x) && (prevMeteor.y == snake.First->pos.y - 1)))
                if (((IsWordEqual(currentWord, "a") && (prevMeteor.x == (snake.First->pos.x + 4) % 5) && (prevMeteor.y == snake.First->pos.y % 5))) || ((IsWordEqual(currentWord, "d") && (prevMeteor.x == (snake.First->pos.x + 1) % 5) && (prevMeteor.y == snake.First->pos.y % 5))) || ((IsWordEqual(currentWord, "s") && (prevMeteor.x == snake.First->pos.x % 5) && (prevMeteor.y == (snake.First->pos.y + 1) % 5))) || ((IsWordEqual(currentWord, "w") && (prevMeteor.x == snake.First->pos.x % 5) && (prevMeteor.y == (snake.First->pos.y + 4) % 5))))
                {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\nSilahkan masukkan command lainnya\n");
                    printf("Silahkan masukkan command anda: ");
                    printf("\n");
                    cekInput = true;
                }
            }
        }
        temp = GetLastPos(snake);
        move(snake, currentWord.TabWord[0], food, meteor);
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
            printf("Berikut merupakan peta permainan\n");
            displayBoard(snake, food, meteor);
        }
        if (Search(snake, meteor) != NilLDP)
        {
            if (Pos(First(snake)).x == meteor.x && Pos(First(snake)).y == meteor.y)
            {
                isMeteorOnHead = true;
                GameOver = true;
            }
            else
            {
                DelP(&snake, meteor);
                lenSnake--;
                printf("Berikut merupakan peta permainan sekarang:\n");
                displayBoard(snake, food, meteor);
                printf("Silakan lanjutkan permainan.\n");
            }
        }
        else
        {
            printf("Anda beruntung tidak terkena meteor! Silakan lanjutkan permainan.\n\n");
        }
        addressLDP B = First(snake);
        temp1.x = Pos(B).x % 5;
        temp1.y = (Pos(B).y + 4) % 5;
        temp2.x = (Pos(B).x + 4) % 5;
        temp2.y = Pos(B).y % 5;
        temp3.x = Pos(B).x % 5;
        temp3.y = (Pos(B).y + 1) % 5;
        temp4.x = (Pos(B).x + 1) % 5;
        temp4.y = Pos(B).y % 5;
        if ((Search(snake, temp1) != NilLDP) && (Search(snake, temp2) != NilLDP) && (Search(snake, temp3) != NilLDP) && (Search(snake, temp4) != NilLDP))
        {
            GameOver = true;
        }
        else if ((temp1.x == meteor.x && temp1.y == meteor.y) && (Search(snake, temp2) != NilLDP) && (Search(snake, temp3) != NilLDP) && (Search(snake, temp4) != NilLDP))
        {
            GameOver = true;
        }
        else if ((Search(snake, temp1) != NilLDP) && (temp2.x == meteor.x && temp2.y == meteor.y) && (Search(snake, temp3) != NilLDP) && (Search(snake, temp4) != NilLDP))
        {
            GameOver = true;
        }
        else if ((Search(snake, temp1) != NilLDP) && (Search(snake, temp2) != NilLDP) && (temp3.x == meteor.x && temp3.y == meteor.y) && (Search(snake, temp4) != NilLDP))
        {
            GameOver = true;
        }
        else if ((Search(snake, temp1) != NilLDP) && (Search(snake, temp2) != NilLDP) && (Search(snake, temp3) != NilLDP) && (temp4.x == meteor.x && temp4.y == meteor.y))
        {
            GameOver = true;
        }

        turn++;
    }
    if (isMeteorOnHead)
    {
        printf("\nKepala snake terkena meteor\n");
        addressLDP addr = First(snake);
        while (addr != Last(snake))
        {
            *score++;
            addr = Next(addr);
        }
        *score *= 2;
        printf("\nGame berakhir. Skor: %d\n", *score);
    }
    else
    {
        addressLDP addr = First(snake);
        while (addr != NilLDP)
        {
            *score++;
            addr = Next(addr);
        }
        *score--;
        *score *= 2;
        printf("\nGame berakhir. Skor: %d\n", *score);
    }
    printf("===== GAME OVER =====\n");
}