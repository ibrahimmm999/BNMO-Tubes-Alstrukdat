IF2111 Algoritma dan Struktur Data

Tugas Besar 1 dan 2

Dibuat oleh kelompok 7 K02 dengan anggota:
1. Gevyndo Gunawan            (18221076)
2. Imam Rusydi Ibrahim        (18221140)
3. Yasmin Arum Sari           (18221142)
4. Tara Chandani Haryono      (18221146)
5. Angela Geraldine Hasian P. (18221158)

Tugas besar ini memiliki misi utama memprogram ulang BNOMO--sebuah video game console. Program yang dibuat dalam bahasa C menggunakan library stdio.h, stdlib.h, mat.h, dan time.h dengan bantuan ADT array, mesin karakter, mesin kata, queue, list, linked list, set, map, stack, serta binary tree ini memiliki 6 fitur utama berupa memainkan, menambahkan, dan menghapus game, mengurutkan game yang akan dimainkan, menampilkan game yang telah dimainkan, dan menampilkan scoreboard game. Terdapat beberapa command pendukung fitur-fitur tersebut, meliputi START, LOAD, SAVE, CREATE GAME, LIST GAME, DELETE GAME, QUEUE GAME, PLAY GAME, SKIPGAME, HISTORY, RESET HISTORY, SCOREBOARD, RESET SCOREBOARD, dan QUIT. Kegunaan setiap command dapat dilihat dengan mengakses command HELP.

Program akan dimulai dengan menampilkan main menu berisi text art bertuliskan 'BNMO' dan sejumlah command (START dan LOAD <savefile.txt). Pengguna akan diarahkan untuk memulai game dengan mengetikkan command yang sesuai. Saat memulai game, akan dibaca sebuah file konfigurasi berisi jumlah games dan nama-nama games tersebut (jika memilih START) atau dibaca sebuah file yang berisi data persis dengan file konfigurasi, tetapi memiliki data tambahan berupa jumlah games yang telah dimainkan dan nama-nama games tersebut, serta scoreboard games (jika memilih LOAD <savefile.txt>). Kemudian, program akan menampilkan sejumlah command yang sudah ditampilkan sebelumnya dan mengarahkan pengguna untuk memasukkan command yang sesuai. Dalam hal ini, program akan menggunakan data dari file yang dibaca sebelumnya.

Sejauh ini, program memiliki 7 default games, yaitu
- RNG (game menebak angka)
- Diner Dash (game menyajikan makanan cepat saji)
- GBK (game gunting batu kertas)
- Tic Tac Toe (game strategi membuat garis dengan tanda 'O' atau 'X')
- Hangman (game menebak kata)
- Tower of Hanoi (game memindahkan piringan)
- Snake on Meteor (game menggerakkan ular untuk mendapat makanan dan menghindari meteor)

Selain itu, juga terdapat game tambahan, yaitu:
- Guess the Peter Parker (game mengungkap penyamaran seseorang)

Berikut cara kompilasi program melalui terminal (dengan terlebih dahulu melakukan set terhadap path folder dengan memasukkan command cd Tubes-Alstrukdat/src).

gcc main.c consoleV2.c ADT/array.c ADT/bintree.c ADT/list.c ADT/listV2.c ADT/listdp.c ADT/map.c ADT/mapV2.c ADT/mesinkarakter.c ADT/mesinkata.c ADT/point.c ADT/prioqueue.c ADT/queueV2.c ADT/set.c ADT/stack.c ADT/stackV2.c command/SKIPGAME.c command/creategame.c command/deletegame.c command/help.c command/history.c command/listgame.c command/loadV2.c command/playgame.c command/queuegame.c command/quit.c command/resethistory.c command/resetscoreboard.c command/saveV2.c command/scoreboard.c command/start.c games/DINERDASH.c games/TowerOfHanoi.c games/guessthepeterparker.c games/guntingbatuk.c games/hangman.c games/rng.c games/snakeonmeteor.c games/tictactoe.c -o main

