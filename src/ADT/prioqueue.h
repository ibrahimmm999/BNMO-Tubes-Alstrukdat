
#ifndef __PRIO_QUEUE_H
#define __PRIO_QUEUE_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define PQCAPACITY 7

/* Definisi elemen dan address */
typedef struct
{
    /* data */
    int foodId;
    int cookTime;
    int stayTime;
    int price;
} PQElType;

typedef struct
{
    PQElType buffer[PQCAPACITY];
    int idxHead;
    int idxTail;
} PrioQueue;

#define IDX_HEAD(pq) (pq).idxHead
#define IDX_TAIL(pq) (pq).idxTail
#define HEAD(pq) (pq).buffer[(pq).idxHead]
#define TAIL(pq) (pq).buffer[(pq).idxTail]

void createQueuePQ(PrioQueue *pq);

boolean isEmptyPQ(PrioQueue pq);

boolean isFullPQ(PrioQueue pq);

int lengthPQ(PrioQueue pq);

void enqueuePQ(PrioQueue *pq, PQElType val);

void dequeuePQ(PrioQueue *pq, PQElType *val);

void dequeuePQ(PrioQueue *pq, PQElType *val);

void printOrders(PrioQueue pq);

void printCooking(PrioQueue pq);

void printServing(PrioQueue pq);

void dequeueAt(PrioQueue *pq, int idx, PQElType *val);

PQElType addQueue(int i);

#endif
