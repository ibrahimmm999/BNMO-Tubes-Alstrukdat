#include "rng.h"

void RNG(int *skor)
{
    srand(time(NULL));
    int x = rand();
    int y = rand();
    if (x > y)
    {
        x -= y;
    }
    else
    {
        int temp = x;
        x = y - temp;
    }
    while (x > 1000)
    {
        x /= 10;
    }
    (*skor) += 100;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTSTDIN();
    while (WordToInt(currentWord) != x && (*skor) != 0)
    {
        (*skor)--;
        if (WordToInt(currentWord) > x)
        {
            printf("Lebih kecil\n");
        }
        else if (WordToInt(currentWord) < x)
        {
            printf("Lebih besar\n");
        }
        printf("Tebakan: ");
        STARTSTDIN();
    }
    printf("\nYa, X adalah %d.\n", x);
    printf("\nSkor anda adalah %d\n", *skor);
}
/*
int main()
{
    RNG();
}
*/
