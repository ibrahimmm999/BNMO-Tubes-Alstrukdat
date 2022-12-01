#include <stdio.h>
#include "mapV2.h"

void CreateEmptyMapV2(Map *M)
{
    M->Count = NilMapV2;
    int i;
    for (i = 0; i < MaxElMapV2; i++)
    {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value.name = "";
        M->Elements[i].Value.score = Undefined;
    }
}

boolean IsMapV2Empty(Map M)
{
    return (M.Count == NilMapV2);
}

boolean IsMapV2Full(Map M)
{
    return (M.Count == MaxElMapV2);
}

/* valuetype Value(Map M, keytype k) {
    int i = 0;
    boolean found = false;
    if (IsMemberMapV2(M, k)) {
        while (!found && i < M.Count) {
            if (M.Elements[i].Key == k) {
                found = true;
            }
            else {
                i++;
            }
        }
        return M.Elements[i].Value;
    }
    else {
        return Undefined;
    }
} */

char *VName(Map M, keytype k)
{
    if (IsMemberMapV2(M, k))
    {
        return M.Elements[k].Value.name;
    }
    else
    {
        return "";
    }
}

int VScore(Map M, keytype k)
{
    if (IsMemberMapV2(M, k))
    {
        return M.Elements[k].Value.score;
    }
    else
    {
        return Undefined;
    }
}

void InsertMapV2(Map *M, keytype k, valuetype v)
{
    M->Elements[k].Key = k;
    M->Elements[k].Value.name = v.name;
    M->Elements[k].Value.score = v.score;
    M->Count++;
}

/* void Delete(Map *M, keytype k) {
    int i = 0;
    boolean found = false;
    if (IsMemberMapV2(*M, k)) {
        while (!found && i < M->Count) {
            if (M->Elements[i].Key == k) {
                found = true;
            }
            else {
                i++;
            }
        }
        while (i < M->Count) {
            M->Elements[i].Key = M->Elements[i+1].Key;
            M->Elements[i].Value.name = M->Elements[i+1].Value.name;
            M->Elements[i].Value.score = M->Elements[i+1].Value.score;
            i++;
        }
        M->Count--;
    }
} */

boolean IsMemberMapV2(Map M, keytype k)
{
    int i = 0;
    boolean found = false;
    while (!found && i < M.Count)
    {
        if (M.Elements[i].Key == k)
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

boolean NameExist(Map M, char *name)
{
    int i = 0;
    boolean found = false;
    while (!found && i < M.Count)
    {
        if (M.Elements[i].Value.name == name)
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
