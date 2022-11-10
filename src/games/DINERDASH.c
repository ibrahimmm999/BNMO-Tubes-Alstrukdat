#include "DINERDASH.h"
#include "converter.h"

QueueDD createEmptyQueueDD (QueueDD *q){ // aman
    CreateQueue(&q->order);
    CreateQueue(&q->time);
    CreateQueue(&q->exp);
    CreateQueue(&q->price);
    (*q).length = 0;
    (*q).totalCust = 0;
}

IsBeingCooked createEmptyIsBeingCooked (IsBeingCooked *c){ // aman
    MakeEmpty(&c->order);
    MakeEmpty(&c->time);
    (*c).length = 0;
}

ReadyToServe createEmptyReadyToServe (ReadyToServe *s){  // aman
    MakeEmpty(&s->order);
    MakeEmpty(&s->exp);
    (*s).length = 0;
}

int randNumber(int max, int min){ // aman
    srand(time(0));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int randPrice(){ // aman
    int num = randNumber(50000, 10000);
    return num;
}

int randTime(){ // aman
    int num = randNumber(5, 1);
    return num;
}

int randExp(){ // aman
    int num = randTime();
    num = (num + randTime(9,1)) % 5 + 1;
    return num;
}

void newOrder(QueueDD q, Word *w){
    /* Kamus */
    Word x;
    int i;
    /* Algoritma */
    (*w).Length = 3;
    (*w).TabWord[0] = m;
    convert(&x, q.totalCust);
    if(q.totalCust <= 9){
        (*w).TabWord[1] = '0';
        if(q.totalCust == 0){
            (*w).TabWord[2] = '0';
        } else {
            (*w).TabWord[2] = x.TabWord[0];
        }
    } else {
        (*w).TabWord[1] = x.TabWord[0];
        (*w).TabWord[2] = x.TabWord[1];
    }
}

void custComing(QueueDD *q){
    /* Kamus */
    Word order;
    Word wTime;
    Word wExp;
    Word wPrice;
    int i = 0;
    /* Algoritma */
    newOrder(*q, &order);
    enqueue(&q->order, order);
    convert(&wTime, randTime());
    enqueue(&q->time, wTime);
    convert(&wExp, randExp());
    enqueue(&q->exp, wExp);
    convert(&wPrice, randPrice());
    for(i = 0; i < 5; i++){
        (*q).price.buffer[(*q).time.idxTail + 1].TabWord[i] = wPrice.TabWord[i];
    }
    (*q).price.idxTail++;
    enqueue(&q->price, wPrice);
    (*q).length++;
    (*q).totalCust++;
}


void openRestaurant(QueueDD *q){
    /* Kamus */
    int i = 0;
    /* Algoritma */
    while(i < 3){
        custComing(q);
        i++;
    }
    printf("ini len: %d, ini totcus: %d", (*q).length, (*q).totalCust);
}

boolean commandValid(Word currentWord){ // asumsi pada akhir input command tidak boleh disertai spasi
    /* Kamus */
    Word com;
    /* Algoritma */
    getCommand(currentWord, &com);
    if(IsWordEqual(com, "SKIP")){
        return(currentWord.Length == 4);
    } else if(IsWordEqual(com, "COOK")){
        return(currentWord.Length == 8);
    } else if(IsWordEqual(com, "SERVE")){
        return(currentWord.Length == 9);
    }
}

Word getCommand(Word currentWord, Word *com){ //aman
    /* Kamus */ 
    int i = 0;
    /* Algoritma */
    while(currentWord.TabWord[i] != SPACE && i < currentWord.Length){
        (*com).TabWord[i] = currentWord.TabWord[i];
        i++;
        (*com).Length++;
    }
}

Word getOrder(Word currentWord, Word *ord){
    /* Kamus */
    int i = 0;
    int ctr = 0;
    int j = currentWord.Length - 1;
    int arr[100];
    /* Algoritma */
    while(currentWord.TabWord[j] != SPACE && i < currentWord.Length){
        arr[i] = currentWord.TabWord[j];
        i++;
        j--;
        ctr++;
    }
    i = 0; j = ctr - 1;
    while(i < ctr){
        (*ord).TabWord[i] = arr[j];
        i++;
        j--;
        (*ord).Length++;
    }
    for(i = 0; i < (*ord).Length; i++){
        printf("%c", (*ord).TabWord[i]);
    }
    return(*ord);
}

void oneRound(QueueDD *q, IsBeingCooked *c, ReadyToServe *s){
    /* Kamus */
    int i, j, t, e, x, y, time, exp;
    int delIdxTime[100];
    int delIdxExp[100];
    Word wTime, wExp;
    /* Algoritma */
    i = j = t = e = x = y = 0;
    custComing(q);
    while(i < (*c).length){
        time = WordToInt((*c).time.A[i]);
        time--;
        if(time == 0){
            delIdxTime[t] = i;
            t++;
        }
        convert(&wTime, time);
        (*c).time.A[i].TabWord[0] = wTime.TabWord[0];
        i++;
    }
    while(j < (*s).length){
        exp = WordToInt((*s).exp.A[i]);
        exp--;
        if(exp == 0){
            delIdxExp[e] = j;
            e++;
        }
        convert(&wExp, exp);
        (*s).exp.A[i].TabWord[0] = wExp.TabWord[0];
        j++;
    }
    if(e != 0){
        while(x < e){
            // delServeAt(s, delIdxExp[x]);
        }
    }
    if(t != 0){
        while(y < t){
            // moveFoodAt(c, s, currentWord, delIdxTime[y]);
        }
    }
}


void displayQueueDD(QueueDD q){
    /* Kamus */
    int i = 0;
    int j, k;
    /* Algoritma */
    printf("Daftar Pesanan\n");
    printf("------------------------------------------------\n");
    printf("| Makanan | Durasi Memasak | Ketahanan | Harga |\n");
    printf("------------------------------------------------\n");
    while(i < q.length){
        printf("| ");
        for(j = 0; j < 3; j++){
            printf("%c", q.order.buffer[q.order.idxHead + i].TabWord[j]);
        }
        printf("     | ");
        printf("%c", q.time.buffer[q.time.idxHead + i].TabWord[0]);
        printf("              | ");
        printf("%c", q.exp.buffer[q.exp.idxHead + i].TabWord[0]);
        printf("         | ");
        for(k = 0; k < 5; k++){
            printf("%c", q.price.buffer[q.price.idxHead + i].TabWord[k]);
        }
        printf(" |\n");
        i++;
    }
    printf("------------------------------------------------\n");
    printf(" \n");
}

void displayCook(IsBeingCooked c){
    /* Kamus */
    int i = 0;
    int j;
    /* Algoritma */
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("---------------------------------\n");
    printf("| Makanan | Sisa durasi memasak |\n");
    printf("---------------------------------\n");
    while(i < c.length){
        printf("| ");
        for(j = 0; j < 3; j++){
            printf("%c", c.order.A[i].TabWord[j]);
        }
        i++;
        printf("     | ");
        printf("%c", c.time.A[i].TabWord[0]);
        printf("                   |\n");
    }
    printf("---------------------------------\n");
    printf(" \n");
}

void displayServe(ReadyToServe s){
     /* Kamus */
    int i = 0;
    int j;
    /* Algoritma */
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("------------------------------------\n");
    printf("| Makanan | Sisa ketahanan makanan |\n");
    printf("------------------------------------\n");
    while(i < s.length){
        printf("| ");
        for(j = 0; j < 3; j++){
            printf("%c", s.order.A[i].TabWord[j]);
        }
        i++;
        printf("     | ");
        printf("%c", s.exp.A[i].TabWord[0]);
        printf("                      |\n");
    }
    printf("------------------------------------\n");
    printf(" \n");
}

void displayAll(QueueDD q, IsBeingCooked c, ReadyToServe s, int saldo){
    printf("SALDO: %d\n", saldo);
    printf(" \n");
    displayQueueDD(q);
    displayCook(c);
    displayServe(s);
}

boolean isFirstQueue(QueueDD q, Word currentWord){
    /* Kamus */
    Word ord;
    boolean same = true;
    int i = 0;
    /* Algoritma */
    getOrder(currentWord, &ord);
    while(i < 3){
        if(q.order.buffer[q.order.idxHead].TabWord[i] != ord.TabWord[i]){
            same = false;
        }
        i++;
    }
    return(same);
}

boolean isInServe(ReadyToServe s, Word currentword){
    /* Kamus */
    int i, j;
    Word ord;
    boolean same = false;
    boolean notDif = true;
    /* Algoritma */
    getOrder(currentWord, &ord);
    while(i <= s.order.Neff && same == false){
        if(ord.Length == s.order.A[i].Length){
            j = 0;
            while(j < ord.Length && notDif == true){
                if(ord.TabWord[j] != s.order.A[i].TabWord[j]){
                    notDif == false;
                }
                j++;
            }
            if(notDif == true){
                same = true;
            }
        }
        i++;
    }
}

boolean isInCook(IsBeingCooked c, Word currentword){
    /* Kamus */
    int i, j;
    Word ord;
    boolean same = false;
    boolean notDif = true;
    /* Algoritma */
    getOrder(currentWord, &ord);
    while(i <= c.order.Neff && same == false){
        if(ord.Length == c.order.A[i].Length){
            j = 0;
            while(j < ord.Length && notDif == true){
                if(ord.TabWord[j] != c.order.A[i].TabWord[j]){
                    notDif == false;
                }
                j++;
            }
            if(notDif == true){
                same = true;
            }
        }
        i++;
    }
}

boolean isInQueueDD(QueueDD q, Word currentword){
    /* Kamus */
    int i = q.order.idxHead;
    int j;
    Word ord;
    boolean same = false;
    boolean notDif = true;
    /* Algoritma */
    getOrder(currentWord, &ord);
    while(i <= q.order.idxTail && same == false){
        if(ord.Length == q.order.buffer[i].Length){
            j = 0;
            while(j < ord.Length && notDif == true){
                if(ord.TabWord[j] != q.order.buffer[i].TabWord[j]){
                    notDif == false;
                }
                j++;
            }
            if(notDif == true){
                same = true;
            }
        }
        i++;
    }
    return(same);

}

boolean canBeServed(QueueDD q, ReadyToServe s, Word currentword){
    if(isFirstQueue(q, currentWord)){
        return(isInServe(s, currentWord));
    }
}

boolean canCook(QueueDD q, IsBeingCooked c, Word currentWord){
    if(isInQueueDD(q, currentWord)){
        return(q.length < 5);
    }
}

void searchInQueue(QueueDD q, Word currentWord, int *idx){
    /* Kamus */
    int i = q.order.idxHead;
    int j;
    Word ord;
    boolean same = false;
    boolean notDif = true;
    /* Algoritma */
    if(isInQueueDD(q, currentWord)){
        getOrder(currentWord, &ord);
        while(i <= q.order.idxTail && same == false){
            if(ord.Length == q.order.buffer[i].Length){
                j = 0;
                while(j < ord.Length && notDif == true){
                    if(ord.TabWord[j] != q.order.buffer[i].TabWord[j]){
                        notDif == false;
                    }
                    j++;
                }
                if(notDif == true){
                    same = true;
                }
            }
            i++;
        }
        (*idx) = i - 1;
    }
}

void searchInServe(ReadyToServe s, Word currentWord, int *idx){
    /* Kamus */
    int i = 0;
    int j;
    Word ord;
    boolean same = false;
    boolean notDif = true;
    /* Algoritma */
    if(isInServe(s, currentWord)){
        getOrder(currentWord, &ord);
        while(i <= s.length && same == false){
            if(ord.Length == s.order.A[i].Length){
                j = 0;
                while(j < ord.Length && notDif == true){
                    if(ord.TabWord[j] != s.order.A[i].TabWord[j]){
                        notDif == false;
                    }
                    j++;
                }
                if(notDif == true){
                    same = true;
                }
            }
            i++;
        }
        (*idx) = i - 1;
    }
}

void COOK(QueueDD q, IsBeingCooked *c, Word currentWord){
    /* Kamus */
    int idx;
    int i = 0;
    int j = (*c).length;
    Word ord;
    /* Algoritma */
    searchInQueue(q, currentWord, &idx);
    getOrder(currentWord, &ord);
    while(i < 3){
        (*c).order.A[j+1].TabWord[i] = ord.TabWord[i];
        i++;
    }
    (*c).length++;
    (*c).order.A[j+1].TabWord[0] = q.time.buffer[idx].TabWord[0];
}

void SERVE(QueueDD *q, ReadyToServe *s, Word currentWord, int *payment){
    /* Kamus */
    int idxServe, idxQueue, i;
    Word ord, price, val;
    /* Algoritma */
    getOrder(currentWord, &ord);
    if(isInServe((*s), currentWord) && isFirstQueue((*q), currentWord)){
        searchInServe(*s, currentWord, &idxServe);
        searchInQueue(*q, currentWord, &idxQueue);
        for(i = 0; i < 5; i++){
            price.TabWord[i] = (*q).price.buffer[idxQueue].TabWord[i];
        }
        *payment = WordToInt(price);
        delServeAt(s, idxServe);
        dequeue(&q->order, &val);
        dequeue(&q->time, &val);
        dequeue(&q->exp, &val);
        dequeue(&q->price, &val);
        q->length--;
    }
}

void delServeAt(ReadyToServe *s, int x){
    /* Kamus */
    int i, j, k;
    /* Algoritma */
    i = x;
    j = x + 1;
    while(i < (*s).length){
        for(k = 0; k < 3; k++){
            (*s).order.A[i].TabWord[k] = (*s).order.A[j].TabWord[k];
        }
        (*s).exp.A[i].TabWord[0] = (*s).exp.A[j].TabWord[0];
        i++;
        j++;
    }
    (*s).length--;
}

void delCookAt(IsBeingCooked *c, int x){
    /* Kamus */
    int i, j, k;
    /* Algoritma */
    i = x;
    j = x + 1;
    while(i < (*c).length){
        for(k = 0; k < 3; k++){
            (*c).order.A[i].TabWord[k] = (*c).order.A[j].TabWord[k];
        }
        (*c).time.A[i].TabWord[0] = (*c).time.A[j].TabWord[0];
        i++;
        j++;
    }
    (*c).length--;
}

void moveFoodAt(QueueDD q, IsBeingCooked *c, ReadyToServe *s, Word currentWord, int y){
    /* Kamus */
    Word ord;
    int idxQueue;
    int i = 0;
    /* Algoritma */
    getOrder(currentWord, &ord);
    delCookAt(c, y);
    (*s).length++;
    searchInQueue(q, currentWord, &idxQueue);
    while (i < 3){
        (*s).order.A[(*s).length].TabWord[i] = ord.TabWord[i];
    }
    (*s).exp.A[0].TabWord[0] = q.order.buffer[idxQueue].TabWord[0];
}

void DINERDASH(){
    /* Kamus */
    int saldo = 0;
    int served = 0;
    int payment = 0;
    int i, custQueue;
    QueueDD queueOrder;
    IsBeingCooked beingCooked;
    ReadyToServe toServe;
    Word command;
    Word order;
    /* Algoritma */
    createEmptyQueueDD(&queueOrder);
    createEmptyIsBeingCooked(&beingCooked);
    createEmptyReadyToServe(&toServe);
    custQueue = queueOrder.length;
    printf("Selamat Datang di Diner Dash! ^-^)/\n");
    printf(" \n");
    openRestaurant(&queueOrder);
    while(served < 15 && custQueue <= 7){
        displayAll(queueOrder, beingCooked, toServe, saldo);
        printf("MASUKKAN COMMAND: ");
        STARTSTDIN();
        printf(" \n");
        if(!commandValid){
            printf("Ups, command yang kamu masukkan keliru! x-x\nCoba ulangi kembali, ya! ^-^");
        } else {
            getCommand(currentWord, &command);
            getOrder(currentWord, &order);
            if(IsWordEqual(command, "COOK")){
                if(!canCook){
                    if(beingCooked.length == 5){
                        printf("Waduh, belum ada cukup ruang untuk memasak. Coba lakukan hal lain terlebih dahulu!");
                    } else { //ID Makanan tidak ada dalam antrean pesanan
                        printf("Tidak ada pelanggan yang memesan makanan itu. Coba periksa kembali!");
                    }
                } else {
                    COOK(queueOrder, &beingCooked, order);
                    printf("Berhasil memasak ");
                    for(i = 0; i < 3; i++){
                        printf("%c", order.TabWord[i]);
                    }
                    printf(" \n");
                    oneRound(&queueOrder, &beingCooked, &toServe);
                    printf("======================\n");
                }
            } else if(IsWordEqual(command, "SERVE")){
                if(!canBeServed){
                    for(i = 0; i < 3; i++){
                        printf("%c", order.TabWord[i]);
                    }
                    printf(" belum dapat disajikan karena ");
                    for(i = 0; i < 3; i++){
                        printf("%c", queueOrder.order.buffer[queueOrder.order.idxHead].TabWord[i]);
                    }
                    printf(" belum selesai dimasak");
                } else {
                    printf("Berhasil mengantar ");
                    for(i = 0; i < 3; i++){
                        printf("%c", order.TabWord[i]);
                    }
                    printf(" \n");
                    SERVE(&queueOrder, &toServe, currentWord, &payment);
                    saldo += payment;
                    served++;
                    oneRound(&queueOrder, &beingCooked, &toServe);
                    printf("======================\n");
                }
            } else if(IsWordEqual(command, "SKIP")){
                oneRound(&queueOrder, &beingCooked, &toServe);
                printf("Tidak ada aksi yang dilakukan. Permainan berlanjut.");
                printf("======================\n");
            }
        }
    }
}

int main(){
     /* Kamus */
    int saldo = 0;
    int served = 0;
    int payment = 0;
    int i, custQueue;
    QueueDD queueOrder;
    IsBeingCooked beingCooked;
    ReadyToServe toServe;
    Word command;
    Word order;
    /* Algoritma */
    createEmptyQueueDD(&queueOrder);
    createEmptyIsBeingCooked(&beingCooked);
    createEmptyReadyToServe(&toServe);
    custQueue = queueOrder.length;
    printf("masukin yu");
    STARTSTDIN();
    getOrder(currentWord, &command);
}

/* spasi 5, 14, 9, 
Selamat Datang di Diner Dash! ^-^)/

SALDO: 0

Daftar Pesanan
------------------------------------------------
| Makanan | Durasi Memasak | Ketahanan | Harga |
------------------------------------------------
| M01     | 2              | 3         | 18213 |
| M02     | 3              | 1         | 48999 |
------------------------------------------------

spasi 5, 19
Daftar Makanan yang sedang dimasak
---------------------------------
| Makanan | Sisa durasi memasak |
---------------------------------
| M01     | 2                   |
---------------------------------

spasi 5, 22
Daftar Makanan yang dapat disajikan
------------------------------------
| Makanan | Sisa ketahanan makanan |
------------------------------------
| M01     | 2                      |
------------------------------------

MASUKKAN COMMAND: xxxx xx

/statement/

================================================
*/