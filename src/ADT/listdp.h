/* File : ListDPdp.h */
/* ADT ListDP dengan Double Pointer */
/* Representasi berkait dengan addressLDP adalah pointer */
/* infotype adalah integer */

#ifndef Listdp_H
#define Listdp_H

#include "../boolean.h"
#include "point.h"

#define NilLDP NULL

/* Definisi Type Data */
typedef int infotypeLdp;
typedef struct tElmtListDP *addressLDP;
typedef struct tElmtListDP
{
    infotypeLdp info;
    addressLDP next;
    addressLDP prev;
    POINT pos;
} ElmtListDP;
typedef struct
{
    addressLDP First;
    addressLDP Last;
} ListDP;

/* Definisi ListDP : */
/* ListDP kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressLDP P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir ListDP: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Pos(P) (P)->pos

/* PROTOTYPE */
/****************** TEST ListDP KOSONG ******************/
boolean IsLDPEmpty(ListDP L);
/* Mengirim true jika ListDP kosong. Lihat definisi di atas. */

/****************** PEMBUATAN ListDP KOSONG ******************/
void CreateEmpty(ListDP *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk ListDP kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressLDP Alokasi(infotypeLdp X, POINT Y);
/* Mengirimkan addressLDP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLDP tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi(addressLDP P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLDP P */

/****************** PENCARIAN SEBUAH ELEMEN ListDP ******************/
addressLDP Search(ListDP L, POINT Y);
/* Mencari apakah ada elemen ListDP dengan Info(P)=X */
/* Jika ada, mengirimkan addressLDP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast(ListDP *L, infotypeLdp X, POINT Y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListDP di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void DelFirst(ListDP *L, addressLDP *P);
/* I.S. ListDP tidak kosong */
/* F.S. P adalah alamat elemen pertama ListDP sebelum penghapusan */
/*      Elemen ListDP berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast(ListDP *L, addressLDP *P);
/* I.S. ListDP tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListDP sebelum penghapusan  */
/*      Elemen ListDP berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void DelP(ListDP *L, POINT X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListDP beraddressLDP P, dengan Info(P)=X  */
/* maka P dihapus dari ListDP dan didealokasi */
/* Jika tidak ada elemen ListDP dengan Info(P)=X, maka ListDP tetap */
/* ListDP mungkin menjadi kosong karena penghapusan */
/****************** PROSES SEMUA ELEMEN ListDP ******************/
void PrintForward(ListDP L);
/* I.S. ListDP mungkin kosong */
/* F.S. Jika ListDP tidak kosong, isi ListDP dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListDP kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward(ListDP L);
/* I.S. ListDP mungkin kosong */
/* F.S. Jika ListDP tidak kosong, isi ListDP dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika ListDP kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
POINT GetLastPos(ListDP L);
/* Mengambil posisi pada Last(L)*/

#endif