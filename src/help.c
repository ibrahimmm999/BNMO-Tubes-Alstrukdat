#include <stdio.h>

    void help(){
    printf("\n");
    printf("~(^-^)~*-*-*-HELP-*-*-*~(^-^)~*-*-*-HELP-*-*-*~(^-^)~*-*-*-HELP-*-*-*~(^-^)~*-*-*-HELP-*-*-*~(^-^)~\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|      START      | Mulai perjalananmu bermain BNOMO dengan menuliskan command ini.                |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("| LOAD <filename> | Buka sebuah file berisi informasi-informasi permainan yang ingin kamu mainkan. |\n");
    printf("|                 | Program akan memprosesnya agar kamu dapat menikmati permainan-permainan        |\n");
    printf("|                 | tersebut!                                                                      |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("| SAVE <filename> | Jangan biarkan progress-mu hilang. Simpan perjalananmu melalui command ini dan |\n");
    printf("|                 | lanjut bermain lain waktu tanpa perlu mengulang permainan dari awal.           |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|    CREATEGAME   | Buat permainan apa pun sesuai keinginanmu, kamu bebas berkreasi di sini.       |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|     LISTGAME    | Lihat daftar permainan yang tersedia oleh sistem.                              |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|    DELETEGAME   | Hapus permainan yang tidak kamu inginkan*.                                     |\n");
    printf("|                 | *Catatan:                                                                      |\n");
    printf("|                 |  - Kamu hanya bisa menghapus permainan buatanmu sendiri.                       |\n");
    printf("|                 |  - Kamu tidak bisa menghapus permainan yang sedang berada pada antrean         |\n");
    printf("|                 |    permainan yang ingin kamu mainkan.                                          |\n");
    printf("|                 |    Hint: Kamu bisa menggunakan command SKIPGAME untuk membuang permainan       |\n");
    printf("|                 |          tertentu dari antrean.                                                |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|    QUEUEGAME    | Lihat daftar antrean permainan yang akan kamu mainkan nanti. Ingat, seluruh    |\n");
    printf("|                 | antrean ini akan terhapus saat kamu memasukkan command QUIT.                   |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|     PLAYGAME    | Nikmati permainanmu. Sistem akan menjalankan permainan pada antrean pertama.   |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|   SKIPGAME <n>  | Mendadak hilang mood untuk memainkan permainan tertentu? Tenang saja!          |\n");
    printf("|                 | Kamu bisa melewati satu atau beberapa permainan pada antrean awal dengan cara  |\n");
    printf("|                 | mengubah <n> menjadi banyaknya permainan yang ingin kamu lewati. Berikutnya,   |\n");
    printf("|                 | program akan secara otomatis memulai permainan pada urutan antrean <n+1>.      |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("|       QUIT      | Keluar dari permainan BNOMO. Jangan lupa simpan progress-mu melalui command    |\n");
    printf("|                 | SAVE <filename> ya. Sampai jumpa!                                              |\n");
    printf(" ----------------- --------------------------------------------------------------------------------\n");
    printf("\n");
    printf("      ~(0-0)~<Lainnya>~(0-0)~<Lainnya>~(0-0)~<Lainnya>~(0-0)~<Lainnya>~(0-0)~<Lainnya>~(0-0)~\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf("|                     ---------------> Tentang Permainan <---------------                          |\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf("|                                        :>>> RNG <<<:                                             |\n");
    printf("|                                                                                                  |\n");
    printf("| *(n) Sebuah permainan menebak angka.                                                             |\n");
    printf("| **Cara bermain:                                                                                  |\n");
    printf("|   1. Masukkan angka acak.                                                                        |\n");
    printf("|   2. Program akan memberi petunjuk agar tebakanmu mendekati angka yang disimpan program.         |\n");
    printf("|   3. Masukkan kembali angka tebakanmu mengikuti petunjuk tersebut.                               |\n");
    printf("|   4. Kamu bisa menebak angka sebanyak yang kamu inginkan--sampai kamu mulai menyerah.            |\n");
    printf("|   5. Permainan selesai saat kamu berhasil menebak angka.                                         |\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf("|                                     :>>> DINER DASH <<<:                                         |\n");
    printf("|                                                                                                  |\n");
    printf("| *(n) Sebuah permainan menyajikan makanan cepat saji.                                             |\n");
    printf("| **Cara bermain:                                                                                  |\n");
    printf("|   1. Permainan akan dibuka dengan 3 pesanan.                                                     |\n");
    printf("|   2. Masak pesanan pelanggan dimulai dari antrean paling awal dengan menuliskan command          |\n");
    printf("|      'COOK M<ID Makanan>'. Misal: 'COOK M01'.                                                    |\n");
    printf("|   3. Jika durasi memasak menunjukkan '0', sajikan makanan dimulai dari makanan yang matang       |\n");
    printf("|      terlebih dahulu. Penyajian ini bisa dilakukan dengan menuliskan command                     |\n");
    printf("|      'SERVE M<ID Makanan>'. Misal: 'SERVE M01'. Hati-hati, makanan dengan ketahanan mencapai '0' |\n");
    printf("|      akan dianggap hangus sehingga kamu harus memasaknya ulang.                                  |\n");
    printf("|   4. Permainan selesai saat kamu berhasil melayani 15 pelanggan. Namun, jangan lengah! Atur      |\n");
    printf("|      strategi agar permainan tidak berhenti karena antrean pelanggan terlalu panjang             |\n");
    printf("|      (lebih dari 7).                                                                             |\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
}

int main() {
    help();
}