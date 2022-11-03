#include "rng.h"

void RNG()
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
        printf("Tebakan: ");
        STARTSTDIN();
    }
    printf("\nYa, X adalah %d.\n", x);
}

int main()
{
    RNG();
}
