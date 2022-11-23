# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "../ADT/stack.h"
# include "boolean.h"
# include "../ADT/mesinkarakter.h"
# include "../ADT/mesinkata.h"


// gcc stack.c mesinkata.c mesinkarakter.c toh.c boolean.c -o main
void Move(Stack *s1, Stack *s2)
{
    if (IsEmpty(*s1)){
        printf("Tidak bisa, kosong tiangnya, mas.. atau mba?");
    }
    else{
        infotype x;
        if(IsEmpty(*s2)){
            Pop(s1,&x);
            Push(s2,x);
        }
        else{
            if(InfoTop(*s1) > InfoTop(*s2)){
                printf("Invalid Command!\n");
            }    
            else{
                Pop(s1,&x);
                Push(s2,x);
            }
        }
    }
}

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
        printf ("       o       \n"); 
    }
    else if (x==2){
        printf ("      ooo      \n");      
    }
    else if (x==3){
        printf ("     ooooo     \n");
    }
    else if (x==4){
        printf ("    ooooooo    \n");
    }
    else if(x==5){
        printf ("   ooooooooo   \n");
    }
    else{
        printf ("       |       \n");
    }
}

void Alas(){
    printf ("---------------\n");
}

void DisplayTower(Stack S, Stack S2, Stack S3){
    printf("\n");
    printf("\n");

    for (int i = 5; i>0; i--){
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

    for (int i = 5; i>0; i--){
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

    for (int i = 5; i>0; i--){
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


void TowerOfHanoi(){
    Stack A, B, C;
    infotype x = 6;
    infotype y = 7;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    for(int i=6;i>0;i--){
        Push(&A,x);
        x--;
    }
    Push(&B,y);
    Push(&C,y);
    // printf("%d\n",InfoTop(B));
    // Move(&A,&B);

    // pindah(&A,&B,&C,'A','B');
    // pindah(&A,&B,&C,'A','B');
    // pindah(&A,&B,&C,'B','C');

    DisplayTower(A,B,C);
}

int main(){

    TowerOfHanoi();
}