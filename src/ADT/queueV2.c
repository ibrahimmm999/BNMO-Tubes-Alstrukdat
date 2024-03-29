#include <stdio.h>
#include "queueV2.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    if (IDX_TAIL(q) >= IDX_HEAD(q))
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
    }
    else
    {
        return (IDX_HEAD(q) - IDX_TAIL(q) == 1);
    }
}

int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q))
    {
        return 0;
    }
    else if (IDX_HEAD(q) <= IDX_TAIL(q))
    {
        return ((IDX_TAIL(q) - IDX_HEAD(q)) + 1);
    }
    else
    { /* IDX_HEAD(q) > IDX_TAIL(q) */
        return (CAPACITY - IDX_HEAD(q)) + (IDX_TAIL(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q)
        ++;
        IDX_TAIL(*q) %= CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
            q mungkin kosong */
    *val = (*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail)
    {
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    }
    else
    {
        (*q).idxHead += 1;
        (*q).idxHead %= CAPACITY;
    }
}
void displayQueue(Queue T)
{
    if (length(T) == 0)
    {
        printf("\n\n");
    }
    else
    {
        int k = 0;
        int i = IDX_HEAD(T);
        while (i <= IDX_TAIL(T))
        {
            printf("%d. ", k + 1);
            int j;
            for (j = 0; j < T.buffer[i].Length; j++)
            {
                printf("%c", T.buffer[i].TabWord[j]);
            }
            printf("\n");
            k++;
            i++;
        }
    }
}
