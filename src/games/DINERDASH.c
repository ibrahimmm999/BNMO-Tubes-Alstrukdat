#include <stdio.h>
#include <stdlib.h>

#include "dinerdash.h"

void dinerDash(int *saldo)
{

    char input[100];
    char cook[] = "COOK";
    char serve[] = "SERVE";
    char skip[] = "SKIP";
    int queue = 0;
    int served = 0;
    *saldo = 0;
    int i;
    printf("\nWELCOME TO DINER DASH!\n\n");
    PQElType order[20];

    srand(time(NULL));
    PrioQueue queuePesanan, cookQ, serveQ;
    createQueuePQ(&queuePesanan);
    createQueuePQ(&cookQ);
    createQueuePQ(&serveQ);
    for (int i = 0; i < 3; i++)
    {
        order[i].foodId = i;
        order[i].cookTime = (rand() % 5) + 1;
        order[i].stayTime = (rand() % 5) + 1;
        order[i].price = (rand() % 5) * 5000 + 10000;
        enqueuePQ(&queuePesanan, order[i]);
    }

    printf("SALDO: %d\n\n", *saldo);
    printOrders(queuePesanan);
    printCooking(cookQ);
    printServing(serveQ);

    int count;
    count = 3;
    while (!isFullPQ(queuePesanan) && served <= 15)
    {
        Word orderId;
        Word command;

        printf("\n \n");
        printf("Masukkan command:");
        STARTSTDIN();

        command = accessIndexWord(currentWord, 1);
        orderId = accessIndexWord(currentWord, 2);
        while (!(((IsWordEqual(command, cook) && orderId.TabWord[0] == 'M') || (IsWordEqual(command, serve) && orderId.TabWord[0] == 'M') || IsWordEqual(command, skip))))
        {
            printf("\nInput tidak sesuai\n");
            printf("Masukkan command: ");
            STARTSTDIN();
            command = accessIndexWord(currentWord, 1);
            orderId = accessIndexWord(currentWord, 2);
        }

        int id = 0;
        for (int i = 1; i < orderId.Length; i++)
        {
            id = id * 10 + (orderId.TabWord[i] - '0');
        }
        while (id < HEADPQ(queuePesanan).foodId || id > TAILPQ(queuePesanan).foodId)
        {
            printf("Masukkan command: ");
            STARTSTDIN();
            command = accessIndexWord(currentWord, 1);
            orderId = accessIndexWord(currentWord, 2);

            id = 0;
            for (int i = 1; i < orderId.Length; i++)
            {
                id = id * 10 + (orderId.TabWord[i] - '0');
            }
        }

        if (IsWordEqual(command, cook) == true)
        {
            enqueuePQ(&queuePesanan, addQueue(count));
            enqueuePQ(&cookQ, queuePesanan.buffer[id - served]);
            printf("Makanan M%d sedang dimasak\n", id);
            queue++;
            count++;
        }

        else if (IsWordEqual(command, serve) == true)
        {
            int i = 0;
            PQElType servableFood;
            PQElType currentFood;

            boolean found = false;

            while (i != IDX_TAILPQ(serveQ) + 1 && !found)
            {
                if (serveQ.buffer[i].foodId == id)
                {
                    currentFood = serveQ.buffer[i];
                    found = true;
                }
                i++;
            }

            if (!isEmptyPQ(serveQ))
            {

                if (currentFood.cookTime == 0)
                {
                    if (currentFood.stayTime > 0)
                    {
                        if (currentFood.foodId == queuePesanan.buffer[IDX_HEADPQ(queuePesanan)].foodId)
                        {
                            dequeuePQ(&queuePesanan, &servableFood);
                            dequeueAt(&serveQ, i - 1, &servableFood);
                            printf("Makanan M%d telah disajikan\n", servableFood.foodId);
                            *saldo += servableFood.price;
                        }

                        else
                        {
                            printf("Makanan M%d belum dapat disajikan karena M%d belum disajikan\n", id, queuePesanan.buffer[IDX_HEADPQ(queuePesanan)].foodId);
                        }
                    }
                    else
                    {
                        dequeueAt(&serveQ, i - 1, &servableFood);
                        dequeuePQ(&queuePesanan, &servableFood);
                        printf("Makanan basi\n");
                    }
                }

                else
                {
                    printf("Makanan M%d belum siap disajikan\n", id);
                }
            }
            enqueuePQ(&queuePesanan, addQueue(count));
            count++;
        }
        else if (IsWordEqual(command, skip) == true)
        {
            enqueuePQ(&queuePesanan, addQueue(count));
            count++;
        }

        printf("\n \n");
        printf("SALDO: %d\n\n", *saldo);
        printOrders(queuePesanan);
        printCooking(cookQ);
        printServing(serveQ);

        printf("\n \n");
        printf("=================================================================\n");

        int ctr;
        ctr = IDX_HEADPQ(serveQ);

        while (ctr < IDX_TAILPQ(serveQ) + 1)
        { // untuk mengurangi ketahanan masak
            if (serveQ.buffer[ctr].stayTime != 0)
            {
                serveQ.buffer[ctr].stayTime -= 1;
            }
            ctr++;
        }

        ctr = IDX_HEADPQ(cookQ);
        while (ctr < IDX_TAILPQ(cookQ) + 1)
        { // untuk mengurangi waktu masak
            cookQ.buffer[ctr].cookTime -= 1;
            if (cookQ.buffer[ctr].cookTime == 0)
            {
                PQElType vall;
                dequeueAt(&cookQ, ctr, &vall);
                enqueuePQ(&serveQ, vall);
            }
            else
            {
                ctr++;
            }
        }
    }
    printf("========== GAME OVER ==========\n");
    printf("SKOR AKHIR : %d\n", *saldo);
}
