#ifndef __GPP__
#define __GPP__

#include <stdio.h>
#include <time.h>
#include "rng.h"
#include "../boolean.h"
#include "../ADT/bintree.h"
#include "../ADT/mesinkata.h"
#include "../ADT/listV2.h"

int generate(int i, int max, int min);
// Prekondisi: i, min, dan max terdefinisi, i > 0, min > 0, max > 0, max > min
// Melakukan generate integer dengan batas minimum min dan batas maksimum maks
// i digunakan sebagai bantuan agar mendapat hasil generate dengan tingkat random maksimal

void getInfo(BinTree Tree, int idx, int *i, Word *info);
/* Proses: Kalimat-kalimat pada guessthepeterparker.txt yang sudah dimasukkan ke dlaam info Tree
           akan diakses pada 'idx' tertentu. */ 
// I.S. Tree tidak kosong, idx terdefinisi (valid dalam Tree), info. kosong (length = 0)
// F.S. length info != 0, info berisi sebuah kalimat yang diambil dari Tree dengan 'index' idx

void relation(ListV2 listFam, Word checked, int idxSusPP, int *n);
// Proses: Melakukan generate untuk menentukan anggota keluarga yang akan 'dikomentari'
// I.S. n = 0, checked terdefinisi (length > 0), idxSusPP valid (bisa diakses pada listFam)
// F.S. Ditemukan relasi yang diinginkan dengan anggota keluarga yang akan 'dikomentari'

void TheClue(Word who, Word clue, Word checked);
// Proses: Merangkai kata-kata who, clue, dan checked menjadi sebuah clue
// I.S. who, clue, dan checked memiliki length > 0
// F.S. Tercetak kalimat berisi clue dengan menggabungkan who, clue, dan checked

void PrintFamTree(BinTree FamTree);
// Proses: Mencetak pohon keluarga dengan bagan pohon ke layar
// I.S. FamTree tidak kosong.
// F.S. Info-info dalam FamTree tercetak ke layar dalam bentuk pohon keluarga

void GPP(int *score);
/* Proses: Permainan utama Guess the Peter Parker dimulai dengan menampilkan 'pesan pembuka',
           disusul dengan menampilkan pohon keluarga, kemudian program mulai meminta pengguna memasukkan
           nama anggota keluarga pada pohon keluarga yang akan diinterogasi, program akan menolak masukan
           yang tidak valid, akan terdapat 2 putaran dengan setiap putaran berisi 3 kali penginterogasian
           dan sekali memberikan dugaan tersangka (Peter Parker).
           Berikut beberapa ketentuan yang perlu diperhatikan.
           - Input pengguna dikatakan valid jika nama yang dimasukkan terdapat dalam pohon keluarga.
             Jika terdapat input yang tidak valid, pengguna akan diminta kembali untuk memberikan input.
           - Pemain tidak boleh menginterogasi orang yang sama lebih dari sekali. Pemain akan diminta memberikan masukan.
           - Untuk putaran kedua, saat pemain memasukkan nama yang sama untuk diinterogasi lebih dari sekali,
             program akan menawarkan bantuan untuk menampilkan nama-nama anggota keluarga yang belum diinterogasi 
           - Untuk setiap input yang tidak valid (tidak termasuk memasukkan nama anggota > 1x),
             score -1
           - Jika pemain berhasil menebak pada putaran pertama, pemain berkesempatan mendapat full score (100).
           - Jika pemain berhasil menebak pada putaran kedua, full score pemain berada pada kisaran 70-87.
           - JIka pemain tidak berhasil menebak hingga putaran kedua, full score pemain berada pada kisaran 30-60. */
/* I.S. score terdefinisi dengan nilai default 0 */
/* F.S. pemain mendapat skor sesuai ketentuan permainan */

#endif