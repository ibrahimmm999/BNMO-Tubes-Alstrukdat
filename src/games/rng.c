#include "rng.h"

void RNG()
{
    srand(time(NULL));
    int x = rand();
    int y = rand();
    float score = 1.0;
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
    printf("%d\n", x);
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTSTDIN();
    while (WordToInt(currentWord) != x)
    {
        if (WordToInt(currentWord) > x)
        {
            printf("Lebih kecil\n");
        }
        else if (WordToInt(currentWord) < x)
        {
            printf("Lebih besar\n");
        }
        score++;
        printf("Tebakan: ");
        STARTSTDIN();
    }
    printf("\nYa, X adalah %d.\n", x);
    printf("\nSkor anda adalah %.0f\n", (1 / score) * 100);
}
/*
int main()
{
    RNG();
}
*/
