#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <math.h> 
#include "../ADT/mesinkata.h" 
#include "../ADT/mesinkarakter.h" 
#include "../boolean.h" 
#include "../ADT/stack.h" 
#include "../games/TowerOfHanoi.h" 
  

// gcc stack.c mesinkata.c mesinkarakter.c towerofhanoia.c -o main
 
 
boolean isWin(Stack s, int temp){
    int i; 
    Stack W; 
    CreateEmpty(&W); 
    for(i=temp; i>0; i--){ 
        Push(&W,i); 
    } 
    boolean win = true; 
    infotype x; 
    while(!IsEmpty(W) && !IsEmpty(s)) 
    { 
        if(InfoTop(s) != InfoTop(W)) 
        { 
            win = false; 
        } 
        Pop(&s,&x); 
        Pop(&W,&x); 
    } 
    if(IsEmpty(s) && IsEmpty(W)){ 
        return win; 
    } 
    else{ 
        return false; 
    }  
}  
 
void Tower(int x){  
    if(x==1){ 
        printf ("        o       \n"); 
    } 
    else if (x==2){
        printf ("       ooo      \n");      
    }
    else if (x==3){
        printf ("      ooooo     \n");
    }
    else if (x==4){
        printf ("     ooooooo    \n");  
    }
    else if(x==5){ 
        printf ("    ooooooooo   \n");
    }
    else if(x==6){
        printf ("   ooooooooooo   \n"); 
    }
    else if(x==7){ 
        printf ("  ooooooooooooo   \n");
    }
    else if(x==8){
        printf (" ooooooooooooooo   \n");
    }
    else if(x==9){
        printf ("ooooooooooooooooo   \n");        
    }
    else{
        printf ("       |       \n");
    }
}

void Alas(){
    printf ("-----------------\n");
}

void DisplayTower(Stack S, Stack S2, Stack S3,int disk){
    printf("\n");
    printf("\n");

    for (int i = disk; i>=0; i--){
        if (i<length(S)){
            if (S.T[i]==1){
                infotype x=1;
                Tower(x);
            }
            else if(S.T[i]==2){
                infotype x=2;
                Tower(x);
            }
            else if(S.T[i]==3){
                infotype x=3;
                Tower(x);
            }
            else if(S.T[i]==4){
                infotype x=4;
                Tower(x);
            }
            else if(S.T[i]==5){
                infotype x=5;
                Tower(x);
            }
            else if(S.T[i]==6){
                infotype x=6;
                Tower(x);
            }
            else if(S.T[i]==7){
                infotype x=7;
                Tower(x);
            }
            else if(S.T[i]==8){
                infotype x=8;
                Tower(x);
            }
            else if(S.T[i]==9){
                infotype x=9;
                Tower(x);
            }
        }
        else {
            infotype x=0;
            Tower(x);
        }
    }

    Alas();
    printf("\n");
    printf("    TOWER A\n");
    printf("\n");

    for (int i = disk; i>=0; i--){
        if (i<length(S2)){
            if (S2.T[i]==1){
                infotype x=1;
                Tower(x);
            }
            else if(S2.T[i]==2){
                infotype x=2;
                Tower(x);
            }
            else if(S2.T[i]==3){
                infotype x=3;
                Tower(x);
            }
            else if(S2.T[i]==4){
                infotype x=4;
                Tower(x);
            }
            else if(S2.T[i]==5){
                infotype x=5;
                Tower(x);
            }
            else if(S2.T[i]==6){
                infotype x=6;
                Tower(x);
            }
            else if(S2.T[i]==7){
                infotype x=7;
                Tower(x);
            }
            else if(S2.T[i]==8){
                infotype x=8;
                Tower(x);
            }
            else if(S2.T[i]==9){
                infotype x=9;
                Tower(x);
            }
        }
        else {
            infotype x=0;
            Tower(x);
        }
    }
    Alas();
    printf("\n");
    printf("    TOWER B\n"); 
    printf("\n"); 
  
    for (int i = disk; i>=0; i--){
        if (i<length(S3)){ 
            if (S3.T[i]==1){
                infotype x=1;
                Tower(x); 
            }
            else if(S3.T[i]==2){
                infotype x=2;
                Tower(x); 
            }
            else if(S3.T[i]==3){
                infotype x=3;
                Tower(x);
            }
            else if(S3.T[i]==4){
                infotype x=4;
                Tower(x); 
            }
            else if(S3.T[i]==5){
                infotype x=5;
                Tower(x);
            }
            else if(S3.T[i]==6){
                infotype x=6;
                Tower(x);
            }
            else if(S3.T[i]==7){
                infotype x=7;
                Tower(x);
            }
            else if(S3.T[i]==8){
                infotype x=8;
                Tower(x);
            }
            else if(S3.T[i]==9){
                infotype x=9;
                Tower(x);
            }
        }
        else {
            infotype x=0;
            Tower(x);
        }
    }
    Alas();
    printf("\n");
    printf("    TOWER C\n");
    printf("\n");
}

boolean MoveValid(Stack S1, Stack S2){
    if (InfoTop(S2)==7){
        return true;
    }
    else if(!IsEmpty(S2)){
        return InfoTop(S2)>InfoTop(S1);
    }
    else{
        return true;
    }
}

void Pindah(Stack *A, Stack *B){
    if(!IsEmpty(*A)){
        if (MoveValid(*A,*B)){
            infotype x;
            Pop(A,&x);
            Push(B,x);
        }
        else{
            printf("Tidak bisa mas mba..\n");
        }
    }
    else{
        printf("Tidak bisa mas mba..\n");
    }    
}

void TowerOfHanoi(){
    Stack A,B,C;
    int steps = 0;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    int disk;
    printf("Main Menu:\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("ENTER CHOICE : ");
    int c;
    STARTSTDIN();
    while (IsWordStr(currentWord, "2")){
        break;
    }
    while (IsWordStr(currentWord, "1")){ 
        printf("Masukkan banyak disk yang ingin dimainkan: ");
        ADVWORD();
        disk = ScanNum(currentWord);
        int i;
        for(i=disk; i>0; i--){
            Push(&A,i);
        }
        while(!isWin(C,disk)){
            printf("%d\n", InfoTop(A));
            printf("%d\n", InfoTop(B));
            printf("%d\n", InfoTop(C));    
            DisplayTower(A,B,C, disk);
            printf("Masukkan menara yang disknya ingin dipindahkan: ");
            ADVWORD();
            if (IsWordStr(currentWord,"A")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"A")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"B")){
                    Pindah(&A, &B);
                }
                else if (IsWordStr(currentWord,"C")){
                    Pindah(&A, &C);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            else if (IsWordStr(currentWord,"B")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"B")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"A")){
                    Pindah(&B, &A);
                }
                else if (IsWordStr(currentWord,"C")){
                    Pindah(&B, &C);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            else if (IsWordStr(currentWord,"C")){
                printf("Dipindahkan ke Menara: ");
                ADVWORD();
                if (IsWordStr(currentWord,"C")){
                    printf("Invalid Command!\n");
                }
                else if (IsWordStr(currentWord,"A")){
                    Pindah(&C, &A);
                }
                else if (IsWordStr(currentWord,"B")){
                    Pindah(&C, &B);
                }
                else{
                    printf("Invalid Command!\n");
                }
            }
            steps++;
        }
        printf("Selamat Anda Menyelesaikan Tower of Hanoi dengan %d langkah\n", steps);
        break;
    }
}


// int main(){
//     TowerOfHanoi();
// }