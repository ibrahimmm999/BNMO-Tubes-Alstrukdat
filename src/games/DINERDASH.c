#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/prioqueue.h"
#include "../ADT/array.h"

void dinerDash()
{

    char input[100];
    char cook[] = "COOK";
    char serve[] = "SERVE";
    char skip[] = "SKIP";
    int queue = 0;
    int served = 0;
    int saldo = 0;
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

    printf("SALDO: %d\n\n", saldo);
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
        while (!((IsWordEqual(command, cook) || IsWordEqual(command, serve) || IsWordEqual(command, skip)) && orderId.TabWord[0] == 'M'))
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
        while (id < HEAD(queuePesanan).foodId || id > TAIL(queuePesanan).foodId)
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
            if (!isEmptyPQ(serveQ))
            {
                if (HEAD(queuePesanan).foodId == id)
                {
                    printf("Berhasil mengantar M%d\n", id);
                    enqueuePQ(&queuePesanan, addQueue(count));
                    PQElType vals;
                    dequeuePQ(&queuePesanan, &vals);
                    dequeuePQ(&serveQ, &vals);
                    served++;
                    count++;
                    saldo += HEAD(queuePesanan).price;
                }

                else
                {
                    printf("Makanan M%d tidak dapat disajikan karena M%d belum selesai\n", id, HEAD(queuePesanan).foodId);
                }
            }
            else
            {
                printf("Tidak ada makanan yang siap disajikan\n");
            }
        }
        else if (IsWordEqual(command, skip) == true)
        {
            enqueuePQ(&queuePesanan, addQueue(count));
            count++;
        }

        printf("\n \n");
        printf("SALDO: %d\n\n", saldo);
        printOrders(queuePesanan);
        printCooking(cookQ);
        printServing(serveQ);

        printf("\n \n");
        printf("=================================================================\n");

        int ctr;
        ctr = IDX_HEAD(serveQ);

        while (ctr < IDX_TAIL(serveQ) + 1)
        { // untuk mengurangi waktu masak
            serveQ.buffer[ctr].stayTime -= 1;
            ctr++;
        }

        ctr = IDX_HEAD(cookQ);
        while (ctr < IDX_TAIL(cookQ) + 1)
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
    printf("SKOR AKHIR : %d\n", saldo);
}

int main()
{
    dinerDash();
}