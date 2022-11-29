#include <stdio.h>
#include "mapV2.h"

void CreateEmptyMap(Map *M) {
    M->Count = Nil;
    int i;
    for (i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value.name = "";
        M->Elements[i].Value.score = Undefined;
    }
}

boolean IsEmpty(Map M) {
    return (M.Count == Nil);
}

boolean IsFull(Map M) {
    return (M.Count == MaxEl);
}

/* valuetype Value(Map M, keytype k) {
    int i = 0;
    boolean found = false;
    if (IsMember(M, k)) {
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

char *VName(Map M, keytype k) {
    if (IsMember(M, k)) {
        return M.Elements[k].Value.name;
    }
    else {
        return "";
    }
}

int VScore(Map M, keytype k) {
    if (IsMember(M, k)) {
        return M.Elements[k].Value.score;
    }
    else {
        return Undefined;
    }
}

void Insert(Map *M, keytype k, valuetype v) {
    M->Elements[k].Key = k;
    M->Elements[k].Value.name = v.name;
    M->Elements[k].Value.score = v.score;
    M->Count++;
}

/* void Delete(Map *M, keytype k) {
    int i = 0;
    boolean found = false;
    if (IsMember(*M, k)) {
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

boolean IsMember(Map M, keytype k) {
    int i = 0;
    boolean found = false;
    while (!found && i < M.Count) {
        if (M.Elements[i].Key == k) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}

boolean NameExist(Map M, char* name) {
    int i = 0;
    boolean found = false;
    while (!found && i < M.Count) {
        if (M.Elements[i].Value.name == name) {
            found = true;
        }
        else {
            i++;
        }
    }
    return found;
}
