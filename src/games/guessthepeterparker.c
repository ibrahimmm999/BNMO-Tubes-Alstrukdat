#include "guessthepeterparker.h"

int generate(int i, int max, int min)
{
    srand(time(NULL));
    int num = ((rand() * i + i) % (max - min + 1)) + min;
    return num;
}

void getInfo(BinTree Tree, int idx, int *i, Word *info)
{
    int j;
    if((*i) < idx)
    {
        (*i)++;
        getInfo(Left(Tree), idx, i, info);
    }
    else
    {
        (*info).Length = 0;
        for(j = 0; j < Tree->info.Length; j++)
        {
            (*info).TabWord[j] = Tree->info.TabWord[j];
            (*info).Length++;
        }
    }
}

void relation(ListV2 listFam, Word checked, int idxSusPP, int *n)
{
    int idxChecked = GetIdxList(listFam, checked)+1;
    // printf("idx checked in list: %d\n", idxChecked);
    int i = generate(2, 10, 4);
    int rel = generate(i, 7, 1);
    Word hub;
    int role;
    if(idxChecked == 1)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 2)
        {
            (*n) = 1;
            // hub.TabWord[0] = 'anak perempuanku';
        }
        if(rel == 3)
        {
            (*n) = 2;
            //hub.TabWord[0] = 'anak laki-lakiku';
        }
        if(rel == 4)
        {
            (*n) = 6;
            //hub.TabWord[0] = 'anak laki-laki putraku';
        }
        if(rel == 5)
        {
            (*n) = 4;
            //hub.TabWord[0] = 'anak perempuan putriku';
        }
        if(rel == 6)
        {
            (*n) = 5;
            //hub.TabWord[0] = 'anak perempuan putraku';
        }
        if(rel == 7)
        {
            (*n) = 4;
            //hub.TabWord[0] = 'anak laki-laki putriku';
        }
    }
    else if(idxChecked == 2)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 8;
            //hub.TabWord[0] = 'ibu';
        }
        if(rel == 3)
        {
            (*n) = 10;
            //hub.TabWord[0] = 'adik laki-lakiku';
        }
        if(rel == 4)
        {
            (*n) = 19;
            //hub.TabWord[0] = 'keponakan laki-lakiku';
        }
        if(rel == 5)
        {
            (*n) = 1;
            //hub.TabWord[0] = 'putriku';
        }
        if(rel == 6)
        {
            (*n) = 18;
            //hub.TabWord[0] = 'keponakan perempuanku';
        }
        if(rel == 7)
        {
            (*n) = 2;
            //hub.TabWord[0] = 'putraku';
        }
    }
    if(idxChecked == 3)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 8;
            //hub.TabWord[0] = 'ibuku';
        }
        if(rel == 2)
        {
            (*n) = 9;
            //hub.TabWord[0] = 'kakak perempuan';
        }
        if(rel == 4)
        {
            (*n) = 2;
            //hub.TabWord[0] = 'putraku';
        }
        if(rel == 5)
        {
            (*n) = 18;
            //hub.TabWord[0] = 'keponakan perempuan';
        }
        if(rel == 6)
        {
            (*n) = 1;
            //hub.TabWord[0] = 'putriku';
        }
        if(rel == 7)
        {
            (*n) = 19;
            //hub.TabWord[0] = 'keponakan laki-laki';
        }
    }
    if(idxChecked == 4)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 15;
            //hub.TabWord[0] = 'Nenekku';
        }
        if(rel == 2)
        {
            (*n) = 14;
            //hub.TabWord[0] = 'Bibiku';
        }
        if(rel == 3)
        {
            (*n) = 7;
            //hub.TabWord[0] = 'Ayahku';
        }
        if(rel == 5)
        {
            (*n) = 16;
            //hub.TabWord[0] = 'Sepupu perempuanku';
        }
        if(rel == 6)
        {
            (*n) = 12;
            //hub.TabWord[0] = 'adik perempuanku';
        }
        if(rel == 7)
        {
            (*n) = 17;
            //hub.TabWord[0] = 'sepupu laki-lakiku';
        }
    }
    if(idxChecked == 5)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 15;
            //hub.TabWord[0] = 'Nenekku';
        }
        if(rel == 2)
        {
            (*n) = 8;
            //hub.TabWord[0] = 'ibuku';
        }
        if(rel == 3)
        {
            (*n) = 13;
            //hub.TabWord[0] = 'pamanku';
        }
        if(rel == 4)
        {
            (*n) = 17;
            //hub.TabWord[0] = 'sepupu laki-lakiku';
        }
        if(rel == 6)
        {
            (*n) = 16;
            //hub.TabWord[0] = 'sepupu perempuanku';
        }
        if(rel == 7)
        {
            (*n) = 10;
            //hub.TabWord[0] = 'adik laki-lakiku';
        }
    }
    if(idxChecked == 6)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 15;
            //hub.TabWord[0] = 'nenekku';
        }
        if(rel == 2)
        {
            (*n) = 14;
            //hub.TabWord[0] = 'bibiku';
        }
        if(rel == 3)
        {
            (*n) = 7;
            //hub.TabWord[0] = 'ayahku';
        }
        if(rel == 4)
        {
            (*n) = 11;
            //hub.TabWord[0] = 'kakak laki-lakiku';
        }
        if(rel == 5)
        {
            (*n) = 16;
            //hub.TabWord[0] = 'sepupu perempuanku';
        }
        if(rel == 7)
        {
            (*n) = 17;
            //hub.TabWord[0] = 'sepupu laki-lakiku';
        }
    }
    if(idxChecked == 7)
    {
        while(rel == idxChecked || rel == idxSusPP)
        {
            i++;
            rel = generate(i, 7, 1);
        }
        // printf("rel: %d\n", rel);
        if(rel == 1)
        {
            (*n) = 15;
            //hub.TabWord[0] = 'nenekku';
        }
        if(rel == 2)
        {
            (*n) = 8;
            //hub.TabWord[0] = 'ibuku';
        }
        if(rel == 3)
        {
            (*n) = 13;
            //hub.TabWord[0] = 'pamanku';
        }
        if(rel == 4)
        {
            (*n) = 17;
            //hub.TabWord[0] = 'sepupu laki-lakiku';
        }
        if(rel == 5)
        {
            (*n) = 9;
            //hub.TabWord[0] = 'kakak perempuanku';
        }
        if(rel == 6)
        {
            (*n) = 16;
            //hub.TabWord[0] = 'sepupu perempuanku';
        }
    }
}

void TheClue(Word who, Word clue, Word checked)
{
    boolean foundMark = false;
    boolean foundPercent = false;
    boolean makeCaps = false;
    int i, j, alphabet;
    for(i = 0; i < checked.Length; i++)
    {
        printf("%c", checked.TabWord[i]);
    }
    printf(": '");
    if(clue.TabWord[0] == '%')
    {
        alphabet = who.TabWord[0];
        alphabet -= 32;
        who.TabWord[0] = alphabet;
    }
    for(i = 0; i < clue.Length; i++)
    {
        if(clue.TabWord[i] == '?' || clue.TabWord[i] == '.')
        {
            foundMark = true;
        }
        if(foundMark == true && clue.TabWord[i] == '%')
        {
            alphabet = who.TabWord[0];
            alphabet -= 32;
            who.TabWord[0] = alphabet;
        }
        if(clue.TabWord[i] == '%')
        {
            foundPercent = true;
            for(j = 0; j < who.Length; j++)
            {
                printf("%c", who.TabWord[j]);
            }
        }
        else
        {
            printf("%c", clue.TabWord[i]);
        }
    }
    printf("'\n");
}

void PrintFamTree(BinTree FamTree)
{
    int i, j;
    printf("\n");
    for(i = 0; i < 23; i++)
    {
        printf(" ");
    }
    printf("%c", 218);
    for(i = 0; i < 12; i++)
    {
        printf("%c", 196);
    }
    
    printf("%c", 191);
    printf("\n");
    for(i = 0; i < 23; i++)
        {
            printf(" ");
        }
        printf("%c", 179);
        printf(" ");
        i = 0;
        while(i < (FamTree)->info.Length)
        {
            printf("%c", (FamTree)->info.TabWord[i]);
            i++;
        }
        printf(" ");
        printf("%c", 179);
    printf("\n");
    for(i = 0; i < 23; i++)
    {
        printf(" ");
    }
    printf("%c", 192);
    for(i = 0; i < 12; i++)
    {
        if(i == 6)
        {
            printf("%c", 194);
        }
        else
        {
            printf("%c", 196);
        }
    }
    printf("%c", 217);
    
    printf("\n");
    for(i = 0; i < 15; i++)
    {
        printf(" ");
    }
    printf("%c", 218);
    for(i = 0; i < 29; i++)
    {
        if(i == 14)
        {
            printf("%c", 193);
        }
        else
        {
            printf("%c", 196);
        }
    }
    printf("%c", 191);
    printf("\n");
    for(j = 0; j < 2; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
        printf("%c", 218);
        for(i = 0; i < 12; i++)
        {
            if(i == 6)
            {
                printf("%c", 193);
            }
            else
            {
                printf("%c", 196);
            }
        }
        printf("%c", 191);
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(j = 0; j < 2; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
        printf("%c", 179);
        printf(" ");
        i = 0;
        if(j == 0)
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Left(FamTree))->info.TabWord[i]);
                i++;
            }
        }
        else
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Right(FamTree))->info.TabWord[i]);
                i++;
            }
        }
        printf(" ");
        printf("%c", 179);
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
    }

    printf("\n");
    for(j = 0; j < 2; j++)
    {
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
        printf("%c", 192);
        for(i = 0; i < 12; i++)
        {
            if(i == 6)
            {
                printf("%c", 194);
            }
            else
            {
                printf("%c", 196);
            }
        }
        printf("%c", 217);
        for(i = 0; i < 8; i++)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    for(j = 0; j < 2; j++)
    {
        for(i = 0; i < 7; i++)
        {
            printf(" ");
        }
        printf("%c", 218);
        for(i = 0; i < 14; i++)
        {
            if(i == 7)
            {
                printf("%c", 193);
            }
            else
            {
                printf("%c", 196);
            }
        }
        printf("%c", 191);
        for(i = 0; i < 7; i++)
        {
            printf(" ");
        }
    }
    
    
    printf("\n");
    for(j = 0; j < 4; j++)
    {
        printf("%c", 218);
        for(i = 0; i < 12; i++)
        {
            if(i == 6)
            {
                printf("%c", 193);
            }
            else
            {
                printf("%c", 196);
            }
        }
        printf("%c", 191);
        printf(" ");
    }
    printf("\n");
    for(j = 0; j < 4; j++)
    {
        printf("%c", 179);
        printf(" ");
        i = 0;
        if(j == 0)
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Left(Left(FamTree)))->info.TabWord[i]);
                i++;
            }
        }
        else if(j == 2)
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Right(Left(FamTree)))->info.TabWord[i]);
                i++;
            }
        }
        else if(j == 3)
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Left(Right(FamTree)))->info.TabWord[i]);
                i++;
            }
        }
        else
        {
            while(i < (FamTree)->info.Length)
            {
                printf("%c", (Right(Right(FamTree)))->info.TabWord[i]);
                i++;
            }
        }
        printf(" ");
        printf("%c", 179);
        printf(" ");
    }
    printf("\n");
    for(j = 0; j < 4; j++)
    {
        printf("%c", 192);
        for(i = 0; i < 12; i++)
        {
            printf("%c", 196);
        }
        printf("%c", 217);
        printf(" ");
    }
    printf("\n");
}

void GPP(int *score)
{
    BinTree FamTree, RelTree, ClueTree;
    int x, new;
    int i = 1;
    int j = 0;
    int n = 0;
    Word who, clue;
    char arrx[100];
    ListV2 list, notChecked;
    notChecked = MakeListV2();
    list = MakeListV2();
    Word temp;
    FILE *p;
    p = fopen("../../data/guessthepeterparker.txt", "r");
    STARTWORD("../../data/guessthepeterparker.txt");
    (*score) = 100;
    while(j < 50)
    {
        ADVWORD();
        j++;
    }
    j = 0;
    while(i < 8)
    {
        x = generate(i, 40, 5);
        if(i % 2 == 0) // i genap
        {
            if(x % 2 != 0)
            {
                x--;
            }
        }
        else // i ganjil
        {
            if(x % 2 == 0)
            {
                x++;
            }
        }
        if(i % 2 == 0 && i > 2) // i genap
        {
            j--;
        }
        new = j + x;
        while(j < new)
        {
            ADVWORD();
            j++;
        }
        int k = 0;

        if(i == 1)
        {
            FamTree = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else if(i == 2)
        {
            Left(FamTree) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else if(i == 3)
        {
            Right(FamTree) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else if(i == 4)
        {
            Right(Left(FamTree)) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else if(i == 5)
        {
            Left(Left(FamTree)) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else if(i == 6)
        {
            Left(Right(FamTree)) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        else
        {
            Right(Right(FamTree)) = AlokNode(currentWord);
            SetV2(&list, i-1, currentWord);
        }
        i++;
    }
    // CetakList(list, 10);

    STARTWORD("../../data/guessthepeterparker.txt");
    for(i = 0; i < 19; i++)
    {
        if(i == 0)
        {
            RelTree = AlokNode(currentWord);
        }
        else
        {
            AddDaunTerkiri(&RelTree, currentWord);
        }
        ADVWORD();
    }

    STARTWORD("../../data/guessthepeterparker.txt");
    j = 0;
    while(j < 19)
    {
        ADVWORD();
        j++;
    }
    j = 0;
    for(i = 0; i < 21; i++)
    {
        if(i == 0)
        {
            ClueTree = AlokNode(currentWord);
        }
        else
        {
            AddDaunTerkiri(&ClueTree, currentWord);
        }
        ADVWORD();
    }

    fclose(p);
    printf("Hai, Detektif!\n");
    printf("Salah satu orang pada pohon keluarga ini merupakan aktor terkenal, Peter Parker, yang dicari dunia selama ini.\n");
    printf("Kini, seluruh anggota keluarga telah meminum ramuan kejujuran.\n");
    printf("Kumpulkan informasi dari mereka. Temukan benang merah dari misteri ini: temukan Peter Parker yang sedang menyamar!\n");
    
    PrintFamTree(FamTree);

    i = generate(2, 4, 8);
    int idxSusPP = generate(i, 7, 1);
    Word SusPP;
    SusPP.Length = 0;
    for(i = 0; i < 10; i++)
    {
        SusPP.TabWord[i] = list.A[idxSusPP-1].TabWord[i];
        SusPP.Length++;
    }
    /* for(i = 0; i < SusPP.Length; i++)
    {
        printf("%c", SusPP.TabWord[i]);
    } */
    int y;
    boolean PPFound = false;
    x = 0;
    for(j = 0; j < 7; j++)
    {
        notChecked.A[j] = list.A[j];
    }
    char arry[100];
    while(x < 2 && PPFound == false)
    {
        x++;
        for(y = 0; y < 3; y++)
        {
            printf("\nKetik nama anggota keluarga yang ingin diinterogasi: ");
            STARTSTDIN();
            // printf("%d\n", SearchTree(FamTree, currentWord));
            while(!SearchTree(FamTree, currentWord))
            {
                (*score)--;
                printf("Input tidak valid. Mohon periksa kembali nama yang dimasukkan.\n");
                printf("\nKetik nama anggota keluarga yang ingin diinterogasi: ");
                STARTSTDIN();
            }
            temp = currentWord;
            while(!IsInList(notChecked, currentWord))
            {
                printf("Jangan buang-buang waktu, ");
                for(i = 0; i < currentWord.Length; i++)
                {
                    printf("%c", currentWord.TabWord[i]);
                }
                printf(" sudah diinterogasi.\n");
                if(x == 2)
                {
                    printf("\nPerlu bantuan? (y/n) ");
                    STARTSTDIN();
                    arrx[0] = 'y';
                    arry[0] = 'n';
                    while(!IsWordEqual(currentWord, arrx) && !IsWordEqual(currentWord, arry))
                    {
                        (*score)--;
                        printf("Input tidak valid. Harap masukkan hanya 'y' atau 'n'.\n");
                        printf("\nPerlu bantuan? (y/n) ");
                        STARTSTDIN();
                    }
                    if(IsWordEqual(currentWord, arrx))
                    {
                        printf("Berikut daftar anggota keluarga yang belum diinterogasi.\n");
                        CetakList(notChecked, LengthV2(notChecked));
                    }
                }
                printf("\nKetik nama anggota keluarga yang ingin diinterogasi: ");
                STARTSTDIN();
                temp = currentWord;
            }
            i = GetIdxList(list, temp);
            // printf("ini idx: %d\n", i+1);

            // CetakList(notChecked, 7);
            i = GetIdxList(notChecked, temp);
            DeleteAtV2(&notChecked, i);

            // printf("nama yang belum diintergoasi:\n");
            // CetakList(notChecked, LengthV2(notChecked));

            relation(list, temp, idxSusPP, &n);
            
            i = 1;
            getInfo(RelTree, n, &i, &who);
            /* printf("ini who:\n");
            for(i = 0; i < who.Length; i++)
            {
                printf("%c", who.TabWord[i]);
            } */

            j = generate(2, 90, 2);
            n = generate(j, 21, 1);
            // printf("ini n: %d\n", n);
            i = 1;
        
            getInfo(ClueTree, n, &i, &clue);
            /* printf("ini clue:\n");
            for(i = 0; i < clue.Length; i++)
            {
                printf("%c", clue.TabWord[i]);
            } */
            TheClue(who, clue, temp);
        }

        printf("\nSaatnya menebak. Siapa Peter Parker menurut dugaanmu? ");
        STARTSTDIN();
        while(!SearchTree(FamTree, currentWord))
            {
                (*score)--;
                printf("Input tidak valid. Mohon periksa kembali nama yang dimasukkan.\n");
                printf("\nKetik nama anggota keluarga yang ingin diinterogasi: ");
                STARTSTDIN();
            }

        if(x == 2)
        {
            printf("\nPeter Parker menyamar menjadi ");
            for(i = 0; i < SusPP.Length; i++)
            {
                arrx[i] = SusPP.TabWord[i];
                printf("%c", arrx[i]);
            }
            printf(".\n");
        }
        else
        {
            for(i = 0; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
            printf(" bukanlah Peter Parker.\n");
        }
        
        if(IsWordEqual(currentWord, arrx))
        {
            printf("Dugaanmu valid! Kamu memang Detektif terhebat di penjuru negeri ini!\n");
            PPFound = true;
        }
        else
        {
            printf("Sayang sekali kamu gagal dalam misi kali ini. ");
            if(x == 2)
            {
                printf("Cobalah lain waktu!\n");
            }
            else
            {
                printf("Namun, tenanglah. Kamu masih mempunyai kesempatan!");
            }
            printf("\n");
        }
        if(x == 1)
        {
            PrintFamTree(FamTree);
        }
    }

    if(PPFound != true)
    {
        y = generate((*score), 40, 7);
        (*score) -= y;
    }

    printf("Skor akhir: %d\n", (*score));
    /* printf("\nKetik nama anggota keluarga yang ingin diinterogasi: ");
    STARTSTDIN();
    // printf("%d\n", SearchTree(FamTree, currentWord));
    while(!SearchTree(FamTree, currentWord))
    {
        printf("\nInput tidak valid. Mohon periksa kembali nama yang dimasukkan.\n");
        printf("Ketik nama anggota keluarga yang ingin diinterogasi: ");
        STARTSTDIN();
    }

    i = GetIdxList(list, currentWord);
    // printf("ini idx: %d\n", i+1);

    CetakList(notChecked, 7);
    i = GetIdxList(notChecked, currentWord);
    DeleteAtV2(&notChecked, i);

    printf("nama yang belum diintergoasi:\n");
    CetakList(notChecked, LengthV2(notChecked)); */

}

/* int main()
{
    int score = 0;
    GPP(&score);
} */