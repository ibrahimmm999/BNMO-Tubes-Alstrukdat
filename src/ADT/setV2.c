#include "setV2.h"

void CreateEmptySet(SetV2 *S)
{
    int i;
    S->Count = 0;
    for (i = 0; i < MaxElsetV2; i++)
    {
        S->Elements[i].game = "";
        CreateEmptyMapV2(&S->Elements[i].M);
    }
}

boolean IsEmptySet(SetV2 S)
{
    return (S.Count == 0);
}

boolean IsFullSet(SetV2 S)
{
    return (S.Count == MaxElsetV2);
}

void InsertSetV2(SetV2 *S, infotypeSetV2 Elmt)
{
    if (!IsMemberOfSet(*S, Elmt.game))
    {
        S->Elements[S->Count].game = Elmt.game;
        S->Elements[S->Count].M = Elmt.M;
        S->Count++;
    }
}

void DeleteSetV2(SetV2 *S, char *game)
{
    int i = 0;
    boolean found = false;
    if (IsMemberOfSet(*S, game))
    {
        while (i < S->Count && !found)
        {
            if (S->Elements[i].game == game)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
        while (i < S->Count)
        {
            S->Elements[i] = S->Elements[i + 1];
            i++;
        }
        S->Count--;
    }
}

boolean IsMemberOfSet(SetV2 S, char *game)
{
    int i = 0;
    boolean found = false;
    while (i < S.Count && !found)
    {
        if (S.Elements[i].game == game)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}