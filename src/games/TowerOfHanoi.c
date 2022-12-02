#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../games/TowerOfHanoi.h"

// gcc stack.c mesinkata.c mesinkarakter.c towerofhanoia.c -o main

boolean isWin(Stack s, int temp)
{
    int i;
    Stack W;
    CreateEmptyStack(&W);
    for (i = temp; i > 0; i--)
    {
        PushStack(&W, i);
    }
    boolean win = true;
    infotypestack x;
    while (!IsStackEmpty(W) && !IsStackEmpty(s))
    {
        if (InfoTop(s) != InfoTop(W))
        {
            win = false;
        }
        PopStack(&s, &x);
        PopStack(&W, &x);
    }
    if (IsStackEmpty(s) && IsStackEmpty(W))
    {
        return win;
    }
    else
    {
        return false;
    }
}

void Tower(int x)
{
    if (x == 1)
    {
        printf("        o       \n");
    }
    else if (x == 2)
    {
        printf("       ooo      \n");
    }
    else if (x == 3)
    {
        printf("      ooooo     \n");
    }
    else if (x == 4)
    {
        printf("     ooooooo    \n");
    }
    else if (x == 5)
    {
        printf("    ooooooooo   \n");
    }
    else if (x == 6)
    {
        printf("   ooooooooooo   \n");
    }
    else if (x == 7)
    {
        printf("  ooooooooooooo   \n");
    }
    else if (x == 8)
    {
        printf(" ooooooooooooooo   \n");
    }
    else if (x == 9)
    {
        printf("ooooooooooooooooo   \n");
    }
    else
    {
        printf("        |       \n");
    }
}

void Alas()
{
    printf("-----------------\n");
}

void DisplayTower(Stack S, Stack S2, Stack S3, int disk)
{
    printf("\n");
    printf("\n");

    for (int i = disk; i >= 0; i--)
    {
        if (i < lengthStack(S))
        {
            if (S.T[i] == 1)
            {
                infotypestack x = 1;
                Tower(x);
            }
            else if (S.T[i] == 2)
            {
                infotypestack x = 2;
                Tower(x);
            }
            else if (S.T[i] == 3)
            {
                infotypestack x = 3;
                Tower(x);
            }
            else if (S.T[i] == 4)
            {
                infotypestack x = 4;
                Tower(x);
            }
            else if (S.T[i] == 5)
            {
                infotypestack x = 5;
                Tower(x);
            }
            else if (S.T[i] == 6)
            {
                infotypestack x = 6;
                Tower(x);
            }
            else if (S.T[i] == 7)
            {
                infotypestack x = 7;
                Tower(x);
            }
            else if (S.T[i] == 8)
            {
                infotypestack x = 8;
                Tower(x);
            }
            else if (S.T[i] == 9)
            {
                infotypestack x = 9;
                Tower(x);
            }
        }
        else
        {
            infotypestack x = 0;
            Tower(x);
        }
    }

    Alas();
    printf("\n");
    printf("     TOWER A\n");
    printf("\n");

    for (int i = disk; i >= 0; i--)
    {
        if (i < lengthStack(S2))
        {
            if (S2.T[i] == 1)
            {
                infotypestack x = 1;
                Tower(x);
            }
            else if (S2.T[i] == 2)
            {
                infotypestack x = 2;
                Tower(x);
            }
            else if (S2.T[i] == 3)
            {
                infotypestack x = 3;
                Tower(x);
            }
            else if (S2.T[i] == 4)
            {
                infotypestack x = 4;
                Tower(x);
            }
            else if (S2.T[i] == 5)
            {
                infotypestack x = 5;
                Tower(x);
            }
            else if (S2.T[i] == 6)
            {
                infotypestack x = 6;
                Tower(x);
            }
            else if (S2.T[i] == 7)
            {
                infotypestack x = 7;
                Tower(x);
            }
            else if (S2.T[i] == 8)
            {
                infotypestack x = 8;
                Tower(x);
            }
            else if (S2.T[i] == 9)
            {
                infotypestack x = 9;
                Tower(x);
            }
        }
        else
        {
            infotypestack x = 0;
            Tower(x);
        }
    }
    Alas();
    printf("\n");
    printf("     TOWER B\n");
    printf("\n");

    for (int i = disk; i >= 0; i--)
    {
        if (i < lengthStack(S3))
        {
            if (S3.T[i] == 1)
            {
                infotypestack x = 1;
                Tower(x);
            }
            else if (S3.T[i] == 2)
            {
                infotypestack x = 2;
                Tower(x);
            }
            else if (S3.T[i] == 3)
            {
                infotypestack x = 3;
                Tower(x);
            }
            else if (S3.T[i] == 4)
            {
                infotypestack x = 4;
                Tower(x);
            }
            else if (S3.T[i] == 5)
            {
                infotypestack x = 5;
                Tower(x);
            }
            else if (S3.T[i] == 6)
            {
                infotypestack x = 6;
                Tower(x);
            }
            else if (S3.T[i] == 7)
            {
                infotypestack x = 7;
                Tower(x);
            }
            else if (S3.T[i] == 8)
            {
                infotypestack x = 8;
                Tower(x);
            }
            else if (S3.T[i] == 9)
            {
                infotypestack x = 9;
                Tower(x);
            }
        }
        else
        {
            infotypestack x = 0;
            Tower(x);
        }
    }
    Alas();
    printf("\n");
    printf("     TOWER C\n");
    printf("\n");
}

boolean MoveValid(Stack S1, Stack S2)
{
    if (InfoTop(S2) == 7)
    {
        return true;
    }
    else if (!IsStackEmpty(S2))
    {
        return InfoTop(S2) > InfoTop(S1);
    }
    else
    {
        return true;
    }
}

void Pindah(Stack *A, Stack *B)
{
    if (!IsStackEmpty(*A))
    {
        if (MoveValid(*A, *B))
        {
            infotypestack x;
            PopStack(A, &x);
            PushStack(B, x);
        }
        else
        {
            printf("Tidak bisa mas mba..\n");
        }
    }
    else
    {
        printf("Tidak bisa mas mba..\n");
    }
}

void TowerOfHanoi(float *score)
{
    Stack A, B, C;
    int steps = 0;
    CreateEmptyStack(&A);
    CreateEmptyStack(&B);
    CreateEmptyStack(&C);
    int disk;
    printf("Welcome to Tower of Hanoi\n");
    printf("1. Ketik 1 untuk bermain\n");
    printf("2. Ketik 2 untuk keluar\n");
    printf("ENTER CHOICE : ");
    int c;
    STARTSTDIN();
    while (IsWordStr(currentWord, "2"))
    {
        break;
    }
    while (IsWordStr(currentWord, "1"))
    {
        printf("Masukkan banyak disk yang ingin dimainkan: ");
        ADVWORD();
        disk = ScanNum(currentWord);
        int i;
        for (i = disk; i > 0; i--)
        {
            PushStack(&A, i);
        }
        while (!isWin(C, disk))
        {
            DisplayTower(A, B, C, disk);
            printf("Masukkan menara yang disknya ingin dipindahkan: ");
            ADVWORD();
            if (IsWordStr(currentWord, "A"))
            {
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord, "A"))
                {
                    printf("Input Invalid!\n");
                }
                else if (IsWordStr(currentWord, "B"))
                {
                    Pindah(&A, &B);
                }
                else if (IsWordStr(currentWord, "C"))
                {
                    Pindah(&A, &C);
                }
                else
                {
                    printf("Input Invalid!\n");
                }
            }
            else if (IsWordStr(currentWord, "B"))
            {
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord, "B"))
                {
                    printf("Input Invalid!\n");
                }
                else if (IsWordStr(currentWord, "A"))
                {
                    Pindah(&B, &A);
                }
                else if (IsWordStr(currentWord, "C"))
                {
                    Pindah(&B, &C);
                }
                else
                {
                    printf("Input Invalid!\n");
                }
            } 
            else if (IsWordStr(currentWord, "C"))
            {
                printf("Dipindahkan ke Menara: ");  
                ADVWORD(); 
                if (IsWordStr(currentWord, "C")) 
                { 
                    printf("Input Invalid!\n"); 
                } 
                else if (IsWordStr(currentWord, "A")) 
                { 
                    Pindah(&C, &A); 
                } 
                else if (IsWordStr(currentWord, "B"))
                {
                    Pindah(&C, &B);
                } 
                else 
                {   
                    printf("Input Invalid!\n");
                }
            }
            else{
                printf("Input invalid!");
            }
            steps++;
        }
        printf("Selamat Anda Menyelesaikan Tower of Hanoi dengan %d langkah\n", steps);
        float skorMax = (pow(2, disk)) - 1;
        *score= skorMax * 10 / steps;
        if (disk==1 || disk==2 || disk==3){ 
            *score=*score-1;
        } 
        printf("Anda mendapatkan score sebesar %f\n", *score);
        break; 
    } 
} 

// int main(){
//     TowerOfHanoi();
// }











