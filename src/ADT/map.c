#include "map.h"

void CreateMap(Map *M)
{
    (*M).Count = Nil;
}

boolean IsMapEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsMapFull(Map M)
{
    return M.Count == MaxEl;
}

valuetype Value(Map M, keytype k)
{
    for (int i = 0; i < M.Count; i++)
    {
        if (IsWordEqual(M.Elements[i].Key, k.TabWord))
        {
            return M.Elements[i].Value;
        }
    }
    return Undefined;
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (!IsMember(*M, k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}

void Delete(Map *M, keytype k)
{
    int idx = 0;
    if (IsMember(*M, k))
    {
        for (int i = 0; i < (*M).Count; i++)
        {
            if (IsWordEqual((*M).Elements[i].Key, k.TabWord))
            {
                idx = i;
            }
        }
        for (int j = idx + 1; j < (*M).Count; j++)
        {
            (*M).Elements[j - 1] = (*M).Elements[j];
        }
        (*M).Count--;
    }
}

boolean IsMember(Map M, keytype k)
{
    for (int i = 0; i < M.Count; i++)
    {
        if (IsWordEqual(M.Elements[i].Key, k.TabWord))
        {
            return true;
        }
    }
    return false;
}