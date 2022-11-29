
#include <stdio.h>
#include <stdlib.h>
#include "saveV2.h"

void save(char *file_name, Arr list_game, StackW history, Map SBrng, Map SBdd, Map SBhm, Map SBtoh, Map SBsom);
{
    FILE *fp = NULL;
    Word info;
    fp = fopen(file_name, "w+");

    if (fp != NULL)
    {
        int i, j, len, lenhis, wordlen;
        char *temp;

        // ------------ list game ------------
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

        // ------------ history ------------
        lenhis = lengthStack(history);
        fprintf(fp, "\n%d\n", lenhis);
        for (i = 0; i < lenhis; i++)
        {
            wordlen = history.T[history.TOP].Length;
            // wordlen = GetElmt(list_game, i).Length;
            char *temp = malloc((wordlen) * sizeof(char));
            PopStack(&history, &info);
            for (j = 0; j < wordlen; j++)
            {
                temp[j] = info.TabWord[j];
                // temp[j] = GetV2(history, i).TabWord[j];
                // temp[j] = GetElmt(list_game, i).TabWord[j];
            }

            temp[j] = '\0';
            if (i == lenhis - 1)
            {
                fprintf(fp, "%s", temp);
            }
            else
            {
                fprintf(fp, "%s\n", temp);
            }
        }
        
        // ------------ scoreboard ------------
        SaveSB(SBrng, fp);
        SaveSB(SBdd, fp);
        SaveSB(SBhm, fp);
        SaveSB(SBtoh, fp);
        SaveSB(SBsom, fp);

        printf("File %s.txt berhasil disimpan\n", file_name);
        fclose(fp);
    }
    else
    {
        printf("File gagal disimpan.\n");
    }
}

void SaveSB(Map SBGame, FILE *fp)
{
    int i;
    fprintf(fp, "%d\n", SBGame.Count);
    for (i = 0; i < SBGame.Count; i++)
    {
        fprintf(fp, "%s %d\n", VName(SBGame, i), VScore(SBGame, i));
    }
}
