#include "set.h"

void CreateSet(Set *S){
    (*S).Count = Nil;
}

boolean IsEmpty(Set S){
    return S.Count == Nil;
}

boolean IsFull(Set S){
    return S.Count == MaxEl;
}

void Insert(Set *S, infotype Elmt){
    if (!IsMember(*S, Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void Delete(Set *S, infotype Elmt){
    int idx = 0;
    if (IsMember(*S, Elmt)){
        for (int i=0;i<(*S).Count;i++){
            if (IsWordEqual((*S).Elements[i], Elmt.TabWord)){
                idx = i;
            }
        }
        for (int j=idx+1;j<(*S).Count;j++){
            (*S).Elements[j-1] = (*S).Elements[j];
        }
        (*S).Count--;
    }
}

boolean IsMember(Set S, infotype Elmt){
    for (int i=0; i<S.Count; i++){
        if (IsWordEqual(S.Elements[i], Elmt.TabWord)){
            return true;
        }
    }
    return false;
}