#include <stdio.h>

#include "prioqueue.h"
#include "../boolean.h"

void createQueuePQ(PrioQueue *pq)
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmptyPQ(PrioQueue pq)
{
    return ((IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF));
}

boolean isFullPQ(PrioQueue pq)
{
    return (IDX_TAIL(pq) == PQCAPACITY - 1 && IDX_HEAD(pq) == 0);
}

int lengthPQ(PrioQueue pq)
{
    if (isEmptyPQ(pq))
    {
        return 0;
    }
    else
    {
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }
}

void enqueuePQ(PrioQueue *pq, PQElType val)
{
    if (isEmptyPQ(*pq))
    {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }
    else
    {
        IDX_TAIL(*pq) = IDX_TAIL(*pq) + 1;
    }
    TAIL(*pq).foodId = val.foodId;
    TAIL(*pq).cookTime = val.cookTime;
    TAIL(*pq).stayTime = val.stayTime;
    TAIL(*pq).price = val.price;
}

void dequeuePQ(PrioQueue *pq, PQElType *val)
{
    (*val).foodId = HEAD(*pq).foodId;
    (*val).cookTime = HEAD(*pq).cookTime;
    (*val).stayTime = HEAD(*pq).stayTime;
    (*val).price = HEAD(*pq).price;
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq))
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
    {
        int i;
        for (i = 0; i < IDX_TAIL(*pq); i++)
        {
            (*pq).buffer[i].foodId = (*pq).buffer[i + 1].foodId;
            (*pq).buffer[i].cookTime = (*pq).buffer[i + 1].cookTime;
            (*pq).buffer[i].stayTime = (*pq).buffer[i + 1].stayTime;
            (*pq).buffer[i].price = (*pq).buffer[i + 1].price;
        }
        IDX_TAIL(*pq)
        --;
    }
}

PQElType addQueue(int i)
{
    PQElType addOrder;
    addOrder.foodId = i;
    addOrder.cookTime = (rand() % 5) + 1;
    addOrder.stayTime = (rand() % 5) + 1;
    addOrder.price = (rand() % 5) * 5000 + 10000;
    return addOrder;
}

void dequeueAt(PrioQueue *pq, int idx, PQElType *val)
{
    (*val).foodId = (*pq).buffer[idx].foodId;
    (*val).cookTime = (*pq).buffer[idx].cookTime;
    (*val).stayTime = (*pq).buffer[idx].stayTime;
    (*val).price = (*pq).buffer[idx].price;
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq))
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
    {
        int i;
        for (i = idx; i < IDX_TAIL(*pq); i++)
        {
            (*pq).buffer[i].foodId = (*pq).buffer[i + 1].foodId;
            (*pq).buffer[i].cookTime = (*pq).buffer[i + 1].cookTime;
            (*pq).buffer[i].stayTime = (*pq).buffer[i + 1].stayTime;
            (*pq).buffer[i].price = (*pq).buffer[i + 1].price;
        }
        IDX_TAIL(*pq)
        --;
    }
}

void printOrders(PrioQueue pq)
{
    printf("Daftar Pesanan: \n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
    if (isEmptyPQ(pq))
    {
        printf("\n");
    }
    else
    {
        PQElType val;
        int i = IDX_HEAD(pq);
        while (i != IDX_TAIL(pq) + 1)
        {
            printf("M%d      | %d              | %d         | %d\n", pq.buffer[i].foodId,
                   pq.buffer[i].cookTime, pq.buffer[i].stayTime, pq.buffer[i].price);
            i++;
        }
    }
}

void printCooking(PrioQueue pq)
{
    printf("\n \n");
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmptyPQ(pq))
    {
        printf("        |                 \n");
        ;
    }
    else
    {
        PQElType val;
        int i = IDX_HEAD(pq);
        while (i != IDX_TAIL(pq) + 1)
        {
            printf("M%d      | %d              \n", pq.buffer[i].foodId, pq.buffer[i].cookTime);
            i++;
        }
    }
}

void printServing(PrioQueue pq)
{
    printf("\n \n");
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("-----------------------------\n");
    if (isEmptyPQ(pq))
    {
        printf("        |                 \n");
    }
    else
    {
        PQElType val;
        int i = IDX_HEAD(pq);
        while (i != IDX_TAIL(pq) + 1)
        {
            printf("M%d      | %d              \n", pq.buffer[i].foodId, pq.buffer[i].stayTime);
            i++;
        }
    }
}