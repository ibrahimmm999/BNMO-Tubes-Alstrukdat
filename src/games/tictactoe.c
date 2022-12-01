#include <stdio.h>

#include "../ADT/mesinkata.h"
#include "../ADT/list.h"
#include "../boolean.h"

void displayBoardTTT(List board)
{
    int i;
    int x = 0;
    printf("\n");
    for (i = 0; i < 9; i++)
    {
        printf("%c ", GetElList(board, i));
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
        SetElList(&board, i - 1, i + '0');
    }
    int count = 0;
    boolean end = false;
    int isPlayer1 = true;
    while (!end && count != 9)
    {
        displayBoardTTT(board);
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
            if (GetElList(board, input - 1) != 'X' && GetElList(board, input - 1) != 'O')
            {
                if (isPlayer1)
                {
                    SetElList(&board, input - 1, 'X');
                    isPlayer1 = false;
                }
                else
                {
                    SetElList(&board, input - 1, 'O');
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
        if (GetElList(board, 0) == GetElList(board, 1) && GetElList(board, 0) == GetElList(board, 2))
        {
            if ((GetElList(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 3) == GetElList(board, 4) && GetElList(board, 3) == GetElList(board, 5))
        {
            if ((GetElList(board, 3) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 3) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 6) == GetElList(board, 7) && GetElList(board, 6) == GetElList(board, 8))
        {
            if ((GetElList(board, 6) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 6) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 0) == GetElList(board, 3) && GetElList(board, 0) == GetElList(board, 6))
        {
            if ((GetElList(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 1) == GetElList(board, 7) && GetElList(board, 4) == GetElList(board, 7))
        {
            if ((GetElList(board, 1) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 1) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 2) == GetElList(board, 8) && GetElList(board, 5) == GetElList(board, 8))
        {
            if ((GetElList(board, 2) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 2) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 0) == GetElList(board, 8) && GetElList(board, 4) == GetElList(board, 8))
        {
            if ((GetElList(board, 0) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 0) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
        else if (GetElList(board, 2) == GetElList(board, 6) && GetElList(board, 4) == GetElList(board, 6))
        {
            if ((GetElList(board, 2) == 'X'))
            {
                playerwin = 1;
            }
            else if ((GetElList(board, 2) == 'O'))
            {

                playerwin = 2;
            }
            end = true;
        }
    }
    displayBoardTTT(board);
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
