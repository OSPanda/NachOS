// Test cases for dllist
#include "dllist.h"
#include <assert.h>
#include <cstdio>

int* 
intNode(int i) {
    int *place = (int*)malloc(sizeof(int));
    *place = i;
    return place;
}

void 
Ppd_Apd_at_Head_and_Tail_on_Empty_List(){
    int i = -2, j = -2;
    int *thing;
    DLList* t = new DLList();
    DLList* t2 = new DLList();

    t->Prepend(intNode(i++));
    t->Append(intNode(i++));

    t2->Append(intNode(i++));
    t2->Prepend(intNode(i++));
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(NULL);
        assert(*thing == j);
        j++;
    }
    j = 1;
    while(t2->IsEmpty()) {
        thing = (int*)t2->Remove(NULL);
        assert(*thing == j);
        j--;
    }
}

void 
Ppd_Apd_at_Head_and_Tail_on_Not_Empty_List_with_SrtIns(){
    int i = -2, j = -2;
    int *thing, *outk = intNode(0);
    DLList* t = new DLList();
    DLList* t2 = new DLList();

    t->SortedInsert(intNode(-1), 0);
    t->Prepend(intNode(i++));
    t->Append(intNode(++i));

    i=-2;
    t2->SortedInsert(intNode(-1), -1);
    t2->Append(intNode(i++));
    t2->Prepend(intNode(++i));

    i = -2; j = -1;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j++;
        i++;
    }

    i = 0; j = -2;
    while(t2->IsEmpty()) {
        thing = (int*)t2->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j++;
        i--;
    }
}

void 
SrtIns_and_SrtRmv_with_Ppd_Apd_Rmv(){
    int i = -2, j = -5, key = -5;
    int *thing = NULL, *outk = intNode(0);
    DLList* t = new DLList();

    for (; key < 10 ; key += 3) {
        t->SortedInsert(intNode(i++), key);
    }
    t->Prepend(intNode(90));
    t->Append(intNode(-3));

    thing = (int*)t->SortedRemove(-6);
    assert(*thing == 90);
    thing = (int*)t->SortedRemove(2);
    assert(thing == NULL);
    thing = (int*)t->SortedRemove(8);
    assert(*thing == -3);

    i = -2;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j += 3;
        i++;
    }

    i = -2;
    for (key = 12; key > -5 ; key -= 4) {
        t->SortedInsert(intNode(i++), key);
    }
    t->Prepend(intNode(1000));
    t->Append(intNode(-132));

    thing = (int*)t->SortedRemove(-5);
    assert(*thing == 1000);
    thing = (int*)t->SortedRemove(-132);
    assert(thing == NULL);
    thing = (int*)t->SortedRemove(13);
    assert(*thing == -132);
    i = 2; j = -4;
    while(t->IsEmpty()) {
        thing = (int*)t->Remove(outk);
        assert(*thing == i);
        assert(*outk == j);
        j += 4;
        i--;
    }
}

int 
main() {

    Ppd_Apd_at_Head_and_Tail_on_Empty_List();
    Ppd_Apd_at_Head_and_Tail_on_Not_Empty_List_with_SrtIns();
    SrtIns_and_SrtRmv_with_Ppd_Apd_Rmv();
    printf("All tests passed.\n");
    return 0;
}

