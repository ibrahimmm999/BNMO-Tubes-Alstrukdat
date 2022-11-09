#include <stdio.h>

#include "../ADT/mesinkata.h"
#include "../ADT/list.h"
#include "../boolean.h"

void displayBoard(List board)
{
    int i;
    int x = 0;
    printf("\n");
    for (i = 0; i < 9; i++)
    {
        printf("%c ", Get(board, i));
        x++;
        if (x == 3)
        {
            printf("\n");
            x = 0;
        }
    }
    printf("\n");
}

void tictactoe()
{
    List board = MakeList();
    int playerwin = 0;
    int i;
    for (i = 1; i <= 9; i++)
    {
        Set(&board, i - 1, i + '0');
    }
    int count = 0;
    boolean end = false;
    int isPlayer1 = true;
    while (!end && count != 9)
    {
        displayBoard(board);
        if (isPlayer1)
        {
            printf("\n= Giliran Player 1 =\n");
        }
        else
        {
            printf("\n= Giliran Player 2 =\n");
        }
        printf("Pilih nomor yang masih tersedia: ");
        STARTSTDIN();
        int input = WordToInt(currentWord);
        if ((input <= 9) && (input >= 1))
        {
            if (Get(board, input - 1) != 'X' && Get(board, input - 1) != 'O')
            {
                if (isPlayer1)
                {
                    Set(&board, input - 1, 'X');
                    isPlayer1 = false;
                }
                else
                {
                    Set(&board, input - 1, 'O');
                    isPlayer1 = true;
                }
                count++;
            }
            else
            {
                printf("\nPilih angka lain\n");
            }
        }
        else
        {
            printf("\nMasukkan angka yang sesuai\n");
        }
        if (Get(board, 0) == Get(board, 1) && Get(board, 0) == Get(board, 2))
        {
            if ((Get(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 3) == Get(board, 4) && Get(board, 3) == Get(board, 5))
        {
            if ((Get(board, 3) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 3) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 6) == Get(board, 7) && Get(board, 6) == Get(board, 8))
        {
            if ((Get(board, 6) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 6) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 0) == Get(board, 3) && Get(board, 0) == Get(board, 6))
        {
            if ((Get(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 1) == Get(board, 7) && Get(board, 4) == Get(board, 7))
        {
            if ((Get(board, 1) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 1) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 2) == Get(board, 8) && Get(board, 5) == Get(board, 8))
        {
            if ((Get(board, 2) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 2) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 0) == Get(board, 8) && Get(board, 4) == Get(board, 8))
        {
            if ((Get(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (Get(board, 2) == Get(board, 6) && Get(board, 4) == Get(board, 6))
        {
            if ((Get(board, 2) == 'X'))
            {
                playerwin = 1;
            }
            else if ((Get(board, 2) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
    }
    displayBoard(board);
    if (playerwin == 1)
    {
        printf("\nSelamat Player 1 menang\n");
    }
    else if (playerwin == 2)
    {
        printf("\nSelamat Player 2 menang\n");
    }
    else
    {
        printf("\nCupu semua ga ada yang menang\n");
    }
}
