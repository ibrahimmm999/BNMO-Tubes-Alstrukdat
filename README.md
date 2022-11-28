IF2111 Algoritma dan Struktur Data
Tugas Besar 1 

Dibuat oleh kelompok 7 K02 dengan anggota:
1. Gevyndo Gunawan            (18221076)
2. Imam Rusydi Ibrahim        (18221140)
3. Yasmin Arum Sari           (18221142)
4. Tara Chandani Haryono      (18221146)
5. Angela Geraldine Hasian P. (18221158)

Tugas besar ini memiliki misi utama memprogram ulang BNOMO--sebuah video game console. Program yang dibuat dalam bahasa
C menggunakan library stdio.h, stdlib.h, mat.h, dan time.h dengan bantuan ADT array, mesin karakter dan mesin kata, serta
queue ini memiliki 4 fitur utama berupa memainkan, menambahkan, dan menghapus game, serta mengurutkan game yang akan
dimainkan. Terdapat beberapa command pendukung fitur-fitur tersebut, meliputi START, LOAD, SAVE, CREATEGAME, LISTGAME,
DELETEGAME, QUEUEGAME, PLAYGAME, SKIPGAME, dan QUIT. Kegunaan setiap command dapat dilihat dengan mengakses command HELP.

Program akan dimulai dengan menampilkan main menu berisi ///insert isi tampilan main menu///. Pengguna akan diarahkan untuk
memulai permainan dengan mengetikkan command yang sesuai. Saat memulai permainan, akan dibaca sebuah file konfigurasi
berisi jumlah permainan dan nama-nama permainan tersebut. Sejauh ini, program ini memiliki 2 permainan default, yaitu
RNG (permainan menebak angka) dan Diner Dash (permainan menyajikan makanan cepat saji).

Berikut cara kompilasi program.
gcc main.c consoleV2.c ADT/listV2.c ADT/list.c ADT/queueV2.c ADT/mesinkata.c ADT/mesinkarakter.c command/help.c ADT/array.c command/start.c command/loadV2.c command/playgame.c command/queuegame.c games/rng.c command/SKIPGAME.c command/listgame.c command/creategame.c command/deletegame.c command/saveV2.c command/history.c command/resethistory.c command/quit.c games/tictactoe.c games/guntingbatuk.c games/DINERDASH.c ADT/prioqueue.c ADT/bintree.c ADT/set.c ADT/map.c ADT/mapV2.c ADT/listdp.c ADT/stack.c games/hangman.c games/TowerOfHanoi.c games/snakeonmeteor.c games/guessthepeterparker.c -o main

gcc main.c consoleV2.c ADT/array.c ADT/bintree.c ADT/list.c ADT/listV2.c ADT/listdp.c ADT/map.c ADT/mapV2.c ADT/mesinkarakter.c ADT/mesinkata.c ADT/point.c ADT/prioqueue.c ADT/queueV2.c ADT/set.c ADT/stack.c ADT/stackV2.c ADT/SKIPGAME.c ADT/creategame.c ADT/deletegame.c ADT/help.c ADT/history.c ADT/listgame.c ADT/load.c ADT/



