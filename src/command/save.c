
#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void save(char *file_name, Arr list_game)
{
    /*
    Prosedur untuk menyimpan state game (jumlah dan daftar game yang dimiliki sistem)
    I.S. game belum disimpan
    F.S. state game disimpan pada suatu file. Jika file sudah ada sebelumnya, make file akan dioverwrite
    */
    FILE *fp = NULL;
    fp = fopen(file_name, "w+");

    if (fp != NULL)
    {
        int i, j, len, wordlen;
        char *temp;

        len = NbElmt(list_game);
        fprintf(fp, "%d\n", len);
        for (i = 0; i < len; i++)
        {
            wordlen = GetElmt(list_game, i).Length;
            char *temp = malloc((wordlen) * sizeof(char));
            for (j = 0; j < wordlen; j++)
            {
                temp[j] = GetElmt(list_game, i).TabWord[j];
            }

            temp[j] = '\0';
            if (i == len - 1)
            {
                fprintf(fp, "%s", temp);
            }
            else
            {

                fprintf(fp, "%s\n", temp);
            }
        }

        printf("File %s.txt berhasil disimpan\n", file_name);
        fclose(fp);
    }
    else
    {
        printf("File gagal disimpan.\n");
    }
}
