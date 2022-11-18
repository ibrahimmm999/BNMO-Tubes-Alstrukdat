
#ifndef __PRIO_QUEUE_H
#define __PRIO_QUEUE_H

#include "../boolean.h"

#define IDX_UNDEFPQ -1
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

#define IDX_HEADPQ(pq) (pq).idxHead
#define IDX_TAILPQ(pq) (pq).idxTail
#define HEADPQ(pq) (pq).buffer[(pq).idxHead]
#define TAILPQ(pq) (pq).buffer[(pq).idxTail]

void createQueuePQ(PrioQueue *pq);

boolean isEmptyPQ(PrioQueue pq);

boolean isFullPQ(PrioQueue pq);

int lengthPQ(PrioQueue pq);

void enqueuePQ(PrioQueue *pq, PQElType val);

void dequeuePQ(PrioQueue *pq, PQElType *val);

void printOrders(PrioQueue pq);

void printCooking(PrioQueue pq);

void printServing(PrioQueue pq);

PQElType addQueue(int i);

void dequeueAt(PrioQueue *pq, int idx, PQElType *val);

#endif
